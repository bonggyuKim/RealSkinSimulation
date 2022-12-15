// Fill out your copyright notice in the Description page of Project Settings.


#include "SoftBody.h"
#include "GeometryActors/EditorGeometryGenerationSubsystem.h"
#include "Solver.h"
#include "IndexTypes.h"
#include "Math/IntVector.h"
#include "Serialization/Archive.h"
#include <limits>
#include "GeometryBase.h"

#include "Editor/EditorEngine.h" // for CopyPropertiesForUnrelatedObjects
#include "Engine/StaticMeshActor.h"

#include "UDynamicMesh.h"

ASoftBody::ASoftBody(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	RegisterWithGenerationManager();
}

ASoftBody::~ASoftBody()
{
	UnregisterWithGenerationManager();
}


UDynamicMesh* ASoftBody::MeshToSoftBody(UDynamicMesh* TargetMesh, int32 TriangleHitPoint, float deltaTime)
{
	TargetMesh->ProcessMesh([&](const FDynamicMesh3& Mesh1)
		{
			MyMesh.Copy(Mesh1);
			CustomPhysics(deltaTime);

			//MyMesh.SetVertex(MyMesh.GetTriangle(TriangleHitPoint)[0],FVector3d(MyMesh.GetTriVertex(TriangleHitPoint, 0)[0]+10, MyMesh.GetTriVertex(TriangleHitPoint, 0)[1]+10, MyMesh.GetTriVertex(TriangleHitPoint, 0)[2]+10));
		});
	TargetMesh->SetMesh(MoveTemp(MyMesh));
	return TargetMesh;
}

FVector ASoftBody::GetHitActorCenterInfo(UDynamicMesh* CollideMesh)
{
	FDynamicMesh3 CMesh;
	CollideMesh->ProcessMesh([&](const FDynamicMesh3& OtherMesh) { CMesh.Copy(OtherMesh); });
	FVector Center = FVector::ZeroVector;
	for (int i = 0;i < CMesh.VertexCount();i++)
	{
		Center += CMesh.GetVertex(i);
	}
	Center = Center / CMesh.VertexCount();
	return Center;
}

void ASoftBody::SetMeshInfo(UDynamicMesh* TargetMesh, UDynamicMeshComponent* UDMC, float resolution)
{
	TargetMesh->ProcessMesh([&](const FDynamicMesh3& Mesh)
		{
			MyMesh.Copy(Mesh);
			//TempTet(MyMesh);
			//GenerateTetmesh(MyMesh, resolution);
			CreateMeshInfo();

		});
	TargetMesh->SetMesh(MoveTemp(MyMesh));
}

void ASoftBody::GetColNearInfo(UDynamicMesh* CollideMesh, FVector ColNearVector, int32 TN)
{
	FDynamicMesh3 CMesh;
	CollideMesh->ProcessMesh([&](const FDynamicMesh3& OtherMesh) { CMesh.Copy(OtherMesh); });
	ColNearVector = FVector::ZeroVector;
	//int32 V1 = MyMesh.GetTriangle(TN)[0];
	
}
void ASoftBody::IsInCol(FDynamicMesh3 OtherMesh, int32 TN)
{
	//TArray<int32> VA;
	//FVector TA = FVector(MyMesh.GetTriNeighbourTris(TN));
	//int isInsideCount = OtherMesh.CalculateWindingNumber(p);
	/*if (isInsideCount >= 1)
	{
		tetVerts.Add(p);
	}
	if()*/
}


void ASoftBody::ExecuteRebuildGeneratedMeshIfPending()
{
	if (bGeneratedMeshRebuildPending)
	{
		// Automatically defer collision updates during generated mesh rebuild. If we do not do this, then
		// each mesh change will result in collision being rebuilt, which is very expensive !!
		bool bEnabledDeferredCollision = false;
		if (DynamicMeshComponent->bDeferCollisionUpdates == false)
		{
			DynamicMeshComponent->SetDeferredCollisionUpdatesEnabled(true, false);
			bEnabledDeferredCollision = true;
		}

		if (bResetOnRebuild && DynamicMeshComponent && DynamicMeshComponent->GetDynamicMesh())
		{
			DynamicMeshComponent->GetDynamicMesh()->Reset();
		}

		FEditorScriptExecutionGuard Guard;
		OnRebuildSoftBodyMesh(DynamicMeshComponent->GetDynamicMesh());
		bGeneratedMeshRebuildPending = false;

		if (bEnabledDeferredCollision)
		{
			DynamicMeshComponent->SetDeferredCollisionUpdatesEnabled(false, true);
		}
	}
}

void ASoftBody::BeginPlay()
{
	Super::BeginPlay();
}

void ASoftBody::CreateMeshInfo()
{

	NumParticles = MyMesh.VertexCount();
	Normals.Init(FVector::ZeroVector, NumParticles);

	Pos.Init(FVector::ZeroVector, NumParticles);
	skinPos.Init(FVector::ZeroVector, NumParticles);
	for (int i = 0;i < NumParticles;i++)
	{
		Pos[i] = MyMesh.GetVertex(i);
		skinPos[i] = Pos[i] * 1.2;
		MyMesh.SetVertex(i, skinPos[i]);
		Normals[i] = FVector(MyMesh.GetVertexNormal(i));
	}
	Vel.Init(FVector::ZeroVector, NumParticles);
	PrevPos = TArray<FVector>(Pos);

	skinVel.Init(FVector::ZeroVector, NumParticles);
	InvMass.Init(1, NumParticles);

	RestVol.Init(0.0, NumParticles);
	Temp.Init(FVector::ZeroVector, NumParticles);
	Grads.Init(FVector::ZeroVector, NumParticles);
	
	/*for(int i = 0;i < MyTet.NumTets; i++)
	{
		float vol = GetVolume(i);
		RestVol[i] = vol;
		float pInvMass = vol > 0.0f ? 1.0 / (vol / 4.0) : 0.0;
		InvMass[MyTet.tetIds[4 * i]] += pInvMass;
		InvMass[MyTet.tetIds[4 * i + 1]] += pInvMass;
		InvMass[MyTet.tetIds[4 * i + 2]] += pInvMass;
		InvMass[MyTet.tetIds[4 * i + 3]] += pInvMass;
	}*/
	

	/*for (int i = 0; i < MyTet.tetEdges.Num(); i++)
	{
		int id0 = MyTet.tetEdgeIds[2 * i];
		int id1 = MyTet.tetEdgeIds[2 * i + 1];
		MyTet.tetEdgeLengths[i] = FMath::Sqrt((MyTet.tetPos[id0] - MyTet.tetPos[id1]).SizeSquared());
	}*/
	EdgeLengths.Init(0.0, MyMesh.EdgeCount());
	for (int i = 0;i < EdgeLengths.Num(); i++)
	{
		int id0 = MyMesh.GetEdge(i).Vert[0];
		int id1 = MyMesh.GetEdge(i).Vert[1];
		EdgeLengths[i] = FMath::Sqrt((Pos[id0] - Pos[id1]).SizeSquared());
	}
	
}
float ASoftBody::GetVolume(int Nr)
{
	int Id0 = MyTet.tetIds[4 * Nr];
	int Id1 = MyTet.tetIds[4 * Nr + 1];
	int Id2 = MyTet.tetIds[4 * Nr + 2];
	int Id3 = MyTet.tetIds[4 * Nr + 3];

	Temp[0] = MyTet.tetPos[Id1] - MyTet.tetPos[Id0];
	Temp[1] = MyTet.tetPos[Id2] - MyTet.tetPos[Id0];
	Temp[2] = MyTet.tetPos[Id3] - MyTet.tetPos[Id0];
	Temp[3] = FVector::CrossProduct(Temp[0], Temp[1]);
	return FVector::DotProduct(Temp[3], Temp[2]) / 6.0;
}

void ASoftBody::CustomPhysics(float DeltaTime)
{

	float SubDeltaTime = DeltaTime / (float)NumSubsteps;
	for (int step = 0;step < NumSubsteps; step++)
	{
		PreSolve(SubDeltaTime);
		Solve(SubDeltaTime);
		PostSolve(SubDeltaTime);
	}
}
void ASoftBody::PreSolve(float DeltaTime)
{
	for (int i = 0;i < NumParticles; i++)
	{
		/*if (InvMass[i] == 0.0)
		{
			continue;
		}*/
		//Pos[i] = skinPos[i];
		//MyTet.tetVel[i] += Gravity * DeltaTime;
		//MyTet.tetPrevPos[i] = MyTet.tetPos[i];
		//MyTet.tetPos[i] += MyTet.tetVel[i] * DeltaTime;
		//skinVel[i] += Gravity * DeltaTime;
		//skinPos[i] = skinVel[i] * DeltaTime;
		Vel[i] += Gravity * DeltaTime;
		PrevPos[i] = Pos[i];
		Pos[i] += Vel[i] * DeltaTime;
		FVector GroundPosition = FVector::ZeroVector;
		GroundPosition = GetTransform().InverseTransformPosition(GroundPosition);
		if (Pos[i].Z < GroundPosition.Z)
		{
			Pos[i] = PrevPos[i];
			Pos[i].Z = GroundPosition.Z;
		}
		MyMesh.SetVertex(i, Pos[i]);
	}
}

void ASoftBody::Solve(float DeltaTime)
{
	SolveEdges(EdgeCompliance, DeltaTime);
	//SolveVolumes(VolCompliance, DeltaTime);
}

void ASoftBody::PostSolve(float DeltaTime)
{
	for (int i = 0;i < NumParticles;i++)
	{
		/*if (InvMass[i] == 0.0)
		{
			continue;
		}*/
		Vel[i] = (Pos[i] - PrevPos[i]) * (1.0 / DeltaTime);
	}
}

void ASoftBody::SolveEdges(float Compliance, float DeltaTime)
{
	float alpha = Compliance / DeltaTime / DeltaTime;
	for (int i = 0;i < MyMesh.EdgeCount(); i++)
	{
		int id0 = MyMesh.GetEdge(i).Vert[0];
		int id1 = MyMesh.GetEdge(i).Vert[1];
		float w = 2 / 100.0f;

		if (FMath::IsNearlyEqual(w, 0.0f))
			continue;

		Grads[0] = Pos[id0] - Pos[id1];
		float len = FMath::Sqrt(Grads[0].SizeSquared());
		if (FMath::IsNearlyEqual(len, 0.0f))
		{
			continue;
		}

		Grads[0] *= (1.0f / len);
		float restLen = EdgeLengths[i];
		float C = len - restLen;
		float s = -C / ( w + alpha);
		Pos[id0] += Grads[0] * (s * w/2);
		Pos[id1] += Grads[0] * (-s * w/2);
		MyMesh.SetVertex(id0, Pos[id0]);
		MyMesh.SetVertex(id1, Pos[id1]);

	}
}

void ASoftBody::SolveVolumes(float Compliance, float DeltaTime)
{
	float alpha = Compliance / DeltaTime / DeltaTime;
	for (int i = 0;i < MyTet.NumTets;i++)
	{

		float w = 0.0;
		for (int j = 0; j < 4; j++)
		{
			int id0 = MyTet.tetIds[4 * i + VolIdOrder[j][0]];
			int id1 = MyTet.tetIds[4 * i + VolIdOrder[j][1]];
			int id2 = MyTet.tetIds[4 * i + VolIdOrder[j][2]];

			Temp[0] = MyTet.tetPos[id1] - MyTet.tetPos[id0];
			Temp[1] = MyTet.tetPos[id2] - MyTet.tetPos[id0];
			Grads[j] = FVector::CrossProduct(Temp[0], Temp[1]);
			Grads[j] *= (1.0f / 6.0f);

			w += InvMass[MyTet.tetIds[4 * i + j]] * Grads[j].SizeSquared();
		}

		if (FMath::IsNearlyEqual(w, 0.0f))
			continue;
		float vol = GetVolume(i);
		float restV = RestVol[i];

		float C = vol - restV;
		float s = -C / (w + alpha);

		for (int j = 0; j < 4; j++)
		{
			int id = MyTet.tetIds[4 * i + j];
			MyTet.tetPos[id] += Grads[j] * (s * InvMass[id]);
		}
		if (i < MyMesh.VertexCount())
			MyMesh.SetVertex(i, MyTet.tetPos[i]);
	}
}

void ASoftBody::GenerateTetmesh(FDynamicMesh3 Mesh, float resolution)
{
	resolution = 10;
	TArray<FVector> tetVerts;
	for (int i = 0;i < Mesh.VertexCount();i++)
	{
		tetVerts.Add(FVector(Mesh.GetVertex(i).X + RandEps(), Mesh.GetVertex(i).Y+ RandEps(), Mesh.GetVertex(i).Z+ RandEps()));
	}
	FVector center = FVector(0, 0, 0);
	FVector bmin = FVector(inf, inf, inf);
	FVector bmax = FVector(-inf, -inf, -inf);
	for (int i = 0;i< tetVerts.Num();i++)
	{
		center += tetVerts[i];
		for (int j = 0;j < 3;j++)
		{
			bmin[j] = FMath::Min(bmin[j], tetVerts[i][j]);
			bmax[j] = FMath::Max(bmax[j], tetVerts[i][j]);
		}
	}
	center /=tetVerts.Num();

	float radius = 0;
	for (int i = 0;i < tetVerts.Num();i++)
	{
		float d = (tetVerts[i] - center).Length();
		radius = FMath::Max(radius, d);
	}
	if (resolution > 0)
	{
		FVector dims = bmax - bmin;
		float dim = FMath::Max(dims[0], FMath::Max(dims[1], dims[2]));
		float h = dim / resolution;

		for (int i = 0;i<int(dims[0] / h) + 1;i++)
		{
			float x = bmin[0] + i * h + RandEps();
			for (int j = 0;j<int(dims[1] / h) + 1;j++)
			{
				float y = bmin[1] + j * h + RandEps();
				for (int k = 0;k<int(dims[2] / h) + 1;k++)
				{
					float z = bmin[2] + k * h + RandEps();
					FVector p = FVector(x, y, z);
					int isInsideCount = Mesh.CalculateWindingNumber(p);
					if (isInsideCount >= 1)
					{
						tetVerts.Add(p);
					}
				}
			}
		}
	}
	float s = 5 * radius;
	tetVerts.Add(FVector(-s, 0, -s));
	tetVerts.Add(FVector(s, 0, -s));
	tetVerts.Add(FVector(0, s, s));
	tetVerts.Add(FVector(0, -s, s));

	TArray<int32> faces = CreateTetIds(tetVerts, Mesh, -1);
	int32 numTets = int(faces.Num() / 4);

	float numSrcPoints = Mesh.VertexCount();
	float numpoints = tetVerts.Num();

	for (int i = 0;i < numSrcPoints;i++)
	{
		FVector co = Mesh.GetVertex(i);
		MyTet.tetPos.Add(co);
	}

	for (int i = numSrcPoints;i < numpoints;i++)
	{
		FVector p = tetVerts[i];
		MyTet.tetPos.Add(p);
	}

	float nr = 0;
	for (int i = 0;i < MyTet.tetPos.Num();i++)
	{
		MyTet.tetIds.Add(4 * i);
		MyTet.tetIds.Add(4 * i+1);
		MyTet.tetIds.Add(4 * i+2);
		MyTet.tetIds.Add(i);
	}
	
}
float ASoftBody::RandEps()
{
	float eps = 0.0001;
	return -eps + 2.0 * FMath::RandRange(0, 1) * eps;
}
TArray<int32> ASoftBody::CreateTetIds(TArray<FVector> verts, FDynamicMesh3 Mesh, float minQuality)
{
	TArray<int32> tetIds;
	TArray<int32> neighbors;
	TArray<int32> tetMarks;
	int32 tetMark = 0;
	int32 firstFreeTet = -1;
	TArray<FVector> planesN;
	TArray<float> planesD;

	int32 firstBig = verts.Num() - 4;
	tetIds.Add(firstBig);
	tetIds.Add(firstBig + 1);
	tetIds.Add(firstBig + 2);
	tetIds.Add(firstBig + 3);
	tetMarks.Add(0);

	for (int i = 0;i < 4;i++)
	{
		neighbors.Add(-1);
		FVector p0 = verts[firstBig + tetFaces[i][0]];
		FVector p1 = verts[firstBig + tetFaces[i][1]];
		FVector p2 = verts[firstBig + tetFaces[i][2]];
		FVector n = (p1 - p0).FVector::Cross(p2 - p0);
		n.Normalize();
		planesN.Add(n);
		planesD.Add(p0.FVector::Dot(n));

	}
	FVector center = FVector(0, 0, 0);

	for (int i = 0;i < firstBig;i++)
	{
		FVector p = verts[i];

		if (i % 100 == 0)
		{
			printf("inserting vert %d of %d", i, firstBig);
		}
		int32 tetNr = 0;
		while (tetIds[4 * tetNr] < 0)
		{
			tetNr = tetNr + 1;
		}

		tetMark = tetMark + 1;
		bool found = false;
		while (!found)
		{
			if (tetNr < 0 ||tetMarks[tetNr] ==tetMark)
			{
				break;
			}
			tetMarks[tetNr] =tetMark;
			int32 id0 =tetIds[4 *tetNr];
			int32 id1 =tetIds[4 *tetNr + 1];
			int32 id2 =tetIds[4 *tetNr + 2];
			int32 id3 =tetIds[4 *tetNr + 3];

			center = (verts[id0] + verts[id1] + verts[id2] + verts[id3]) * 0.25;
			float minT = inf;
			int32 minFaceNr = -1;

			for (int j = 0;j < 4;j++)
			{
				FVector n = planesN[4 *tetNr + j];
				float d = planesD[4 *tetNr + j];

				float hp = n.FVector::Dot(p) - d;
				float hc = n.FVector::Dot(center) - d;

				float t = hp - hc;
				if (t == 0)
					continue;
				t = -hc / t;

				if (t >= 0 && t < minT)
				{
					minT = t;
					minFaceNr = j;
				}
			}
			if (minT >= 1)
			{
				found = true;
			}
			else
			{
				tetNr = neighbors[4 *tetNr + minFaceNr];
			}
		}
		if (!found)
		{
			continue;
		}
		tetMark =tetMark + 1;

		TArray<int32> violatingTets;
		TArray<int32> stack;
		stack.Add(tetNr);
		while (stack.Num() != 0)
		{
			tetNr = stack.Pop();
			if (tetMarks[tetNr] ==tetMark)
			{
				continue;
			}
			tetMarks[tetNr] =tetMark;
			violatingTets.Add(tetNr);

			for (int j = 0;j < 4;j++)
			{
				int32 n = neighbors[4 *tetNr + j];
				if (n < 0 ||tetMarks[n] ==tetMark)
				{
					continue;
				}
				int32 id0 =tetIds[4 * n];
				int32 id1 =tetIds[4 * n + 1];
				int32 id2 =tetIds[4 * n + 2];
				int32 id3 =tetIds[4 * n + 3];

				FVector c = GetCircumCenter(verts[id0], verts[id1], verts[id2], verts[id3]);

				float r = (verts[id0] - c).Length();
				if ((p - c).Length() < r)
				{
					stack.Add(n);
				}
			}
		}
		TArray<FVector4> edges;
		for (int j = 0;j < violatingTets.Num();j++)
		{
			tetNr = violatingTets[j];
			TArray<int32> ids = { 0, 0, 0, 0 };
			TArray<int32> ns = { 0,0,0,0 };
			for (int k = 0;k < 4;k++)
			{
				ids[k] =tetIds[4 *tetNr + k];
				ns[k] = neighbors[4 *tetNr + k];
			}
			tetIds[4 *tetNr] = -1;
			tetIds[4 *tetNr + 1] = firstFreeTet;
			firstFreeTet =tetNr;

			for (int k = 0;k < 4;k++)
			{
				int32 n = ns[k];
				if (n >= 0 &&tetMarks[n] ==tetMark)
				{
					continue;
				}

				int32 newTetNr = firstFreeTet;

				if (newTetNr >= 0)
				{
					firstFreeTet =tetIds[4 * firstFreeTet + 1];
				}
				else {

					newTetNr = int(tetIds.Num() / 4);
					tetMarks.Add(0);
					for (int l = 0;l < 4;l++)
					{
						tetIds.Add(-1);
						neighbors.Add(-1);
						planesN.Add(FVector((0.0, 0.0, 0.0)));
						planesD.Add(0.0);
					}
				}
				int32 id0 = ids[tetFaces[k][2]];
				int32 id1 = ids[tetFaces[k][1]];
				int32 id2 = ids[tetFaces[k][0]];

				tetIds[4 * newTetNr] = id0;
				tetIds[4 * newTetNr + 1] = id1;
				tetIds[4 * newTetNr + 2] = id2;
				tetIds[4 * newTetNr + 3] = i;

				neighbors[4 * newTetNr] = n;

				if (n >= 0)
				{
					for (int l = 0;l < 4;l++)
					{
						if (neighbors[4 * n + l] ==tetNr)
						{
							neighbors[4 * n + l] = newTetNr;
						}
					}
				}
				neighbors[4 * newTetNr + 1] = -1;
				neighbors[4 * newTetNr + 2] = -1;
				neighbors[4 * newTetNr + 3] = -1;

				for (int l = 0;l < 4;l++)
				{
					FVector p0 = verts[tetIds[4 * newTetNr +tetFaces[l][0]]];
					FVector p1 = verts[tetIds[4 * newTetNr +tetFaces[l][1]]];
					FVector p2 = verts[tetIds[4 * newTetNr +tetFaces[l][2]]];
					FVector newN = (p1 - p0).Cross(p2 - p0);
					newN.Normalize();
					planesN[4 * newTetNr + l] = newN;
					planesD[4 * newTetNr + l] = newN.Dot(p0);
				}
				if (id0 < id1)
				{
					edges.Add(FVector4(id0, id1, newTetNr, 1));
				}
				else {
					edges.Add(FVector4(id1, id0, newTetNr, 1));
				}

				if (id1 < id2)
				{
					edges.Add(FVector4(id1, id2, newTetNr, 2));
				}
				else
				{
					edges.Add(FVector4(id2, id1, newTetNr, 2));
				}

				if (id2 < id0)
				{
					edges.Add(FVector4(id2, id0, newTetNr, 3));
				}
				else
				{
					edges.Add(FVector4(id0, id2, newTetNr, 3));
				}
			}
		}
		for (int j = 0;j < edges.Num() - 1;j++)
		{

		}
		//edges.Sort(CompareEdges);

		int32 nr = 0;
		int32 numEdges = edges.Num();

		while (nr < numEdges) {
			FVector4 e0 = edges[nr];
			nr = nr + 1;

			if (nr < numEdges && EqualEdges(edges[nr], e0))
			{
				FVector4 e1 = edges[nr];

				int32 id0 =tetIds[4 * e0[2]];
				int32 id1 =tetIds[4 * e0[2] + 1];
				int32 id2 =tetIds[4 * e0[2] + 2];
				int32 id3 =tetIds[4 * e0[2] + 3];

				int32 jd0 =tetIds[4 * e1[2]];
				int32 jd1 =tetIds[4 * e1[2] + 1];
				int32 jd2 =tetIds[4 * e1[2] + 2];
				int32 jd3 =tetIds[4 * e1[2] + 3];

				neighbors[4 * e0[2] + e0[3]] = e1[2];
				neighbors[4 * e1[2] + e1[3]] = e0[2];
				nr = nr + 1;
			}
		}
	}
	int32 numT = int((tetIds).Num() / 4);
	int32 num = 0;
	int32 numBad = 0;

	for (int i = 0;i < numT;i++)
	{
		int32 id0 =tetIds[4 * i];
		int32 id1 =tetIds[4 * i + 1];
		int32 id2 =tetIds[4 * i + 2];
		int32 id3 =tetIds[4 * i + 3];

		if (id0 < 0 || id0 >= firstBig || id1 >= firstBig || id2 >= firstBig || id3 >= firstBig)
		{
			continue;
		}

		FVector p0 = verts[id0];
		FVector p1 = verts[id1];
		FVector p2 = verts[id2];
		FVector p3 = verts[id3];

		float quality =TetQuality(p0, p1, p2, p3);
		if (quality < minQuality)
		{
			numBad = numBad + 1;
			continue;
		}
		center = (p0 + p1 + p2 + p3) * 0.25;
		if (Mesh.CalculateWindingNumber(center) == 0)
			continue;

		tetIds[num] = id0;
		num = num + 1;
		tetIds[num] = id1;
		num = num + 1;
		tetIds[num] = id2;
		num = num + 1;
		tetIds[num] = id3;
		num = num + 1;
	}
	TArray<int32>tetResult;

	for (int j = 0;j <tetIds.Num();j++)
	{
		tetResult.Add(tetIds[j]);
	}
	int32 tetResultN = tetResult.Num();
	UE_LOG(LogTemp, Log, TEXT("Tets created %d"), tetResultN);
	return tetResult;
}
FVector ASoftBody::GetCircumCenter(FVector p0, FVector p1, FVector p2, FVector p3)
{
	FVector b = p1 - p0;
	FVector c = p2 - p0;
	FVector d = p3 - p0;

	float det = 2.0 * (b.X * (c.Y * d.Z - c.Z * d.Y) - b.Y * (c.X * d.Z - c.Z * d.X) + b.Z * (c.X * d.Y - c.Y * d.X));
	if (det == 0)
	{
		return p0;
	}
	else
	{
		FVector v = c.FVector::Cross(d) * b.FVector::Dot(b) + d.FVector::Cross(b) * c.FVector::Dot(c) + b.Cross(c) * d.Dot(d);
		v /= det;
		return p0 + v;
	}
}
bool ASoftBody::CompareEdges(FVector4 e0, FVector4 e1)
{
	if (e0[0] < e1[0] || (e0[0] == e1[0] && e0[1] < e1[1]))
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool ASoftBody::EqualEdges(FVector4 e0, FVector4 e1)
{
	return e0[0] == e1[0] && e0[1] == e1[1];
}
float ASoftBody::TetQuality(FVector p0, FVector p1, FVector p2, FVector p3)
{

	FVector d0 = p1 - p0;
	FVector	d1 = p2 - p0;
	FVector	d2 = p3 - p0;
	FVector	d3 = p2 - p1;
	FVector	d4 = p3 - p2;
	FVector	d5 = p1 - p3;

	float s0 = d0.Length();
	float s1 = d1.Length();
	float s2 = d2.Length();
	float s3 = d3.Length();
	float s4 = d4.Length();
	float s5 = d5.Length();

	float ms = (s0 * s0 + s1 * s1 + s2 * s2 + s3 * s3 + s4 * s4 + s5 * s5) / 6.0;
	float rms = FMath::Sqrt(ms);

	float s = 12.0 / FMath::Sqrt(2.0);

	float vol = d0.Dot(d1.Cross(d2)) / 6.0;
	return s * vol / (rms * rms * rms);
}
void ASoftBody::TempTet(FDynamicMesh3 Mesh)
{
	FVector center = FVector::ZeroVector;
	for (int i = 0;i < Mesh.VertexCount();i++)
	{
		MyTet.tetPos.Add(Mesh.GetVertex(i));

		center += Mesh.GetVertex(i);
	}
	center /= Mesh.VertexCount();
	MyTet.tetPos.Add(center);
	for (int i = 0;i < Mesh.TriangleCount();i++)
	{
		int32 id0 = Mesh.GetTriangle(i)[0];
		int32 id1 = Mesh.GetTriangle(i)[1];
		int32 id2 = Mesh.GetTriangle(i)[2];
		MyTet.tetIds.Add(id0);
		MyTet.tetIds.Add(id1);
		MyTet.tetIds.Add(id2);
		MyTet.tetIds.Add(MyTet.tetPos.Num()-1);
		
	}
	for (int i = 0;i < Mesh.EdgeCount();i++)
	{
		MyTet.tetEdgeIds.Add(FVector(Mesh.GetEdge(i).Vert[0], Mesh.GetEdge(i).Vert[1],0));
	}
	for (int i = 0;i < Mesh.VertexCount();i++)
	{
		MyTet.tetEdgeIds.Add(FVector(i, MyTet.tetPos.Num() - 1, 0));
	}
	for (int i = 0;i < MyTet.tetEdgeIds.Num();i++)
	{
		int id0 = MyTet.tetEdgeIds[i][0];
		int id1 = MyTet.tetEdgeIds[i][1];
		MyTet.tetEdgeLengths.Add(FMath::Sqrt((MyTet.tetPos[id0] - MyTet.tetPos[id1]).SizeSquared()));
		
	}
	MyTet.NumTets = MyTet.tetIds.Num() / 4;
	MyTet.NumTetParticles = MyTet.tetPos.Num();
}


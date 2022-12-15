// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GeometryActors/GeneratedDynamicMeshActor.h"
#include "GeometryTypes.h"

#include "DynamicMeshEditor.h"

#include "Spatial/FastWinding.h"
#include "DynamicMesh/DynamicMeshAABBTree3.h"
#include "GeometryScript/MeshSpatialFunctions.h"
#include "Util/ProgressCancel.h"
#include "VectorTypes.h"
#include "VectorUtil.h"
#include "IndexTypes.h"

#include "SoftBody.generated.h"

/**
 * 
 */
UCLASS()
class GEOMETRYPRACTICE_API ASoftBody : public AGeneratedDynamicMeshActor
{
	GENERATED_UCLASS_BODY()

public:
	virtual ~ASoftBody();

	/**
	 * This event will be fired to notify the BP that the generated Mesh should
	 * be rebuilt. GeneratedDynamicMeshActor BP subclasses should rebuild their
	 * meshes on this event, instead of doing so directly from the Construction Script.
	 */
	UFUNCTION(BlueprintImplementableEvent, CallInEditor, Category = "Events")
	void OnRebuildSoftBodyMesh(UDynamicMesh* TargetMesh);

	UFUNCTION(BlueprintCallable)
	UDynamicMesh* MeshToSoftBody(UDynamicMesh* TargetMesh, int32 TriangleHitPoint, float deltaTime);

	UFUNCTION(BlueprintCallable)
	FVector GetHitActorCenterInfo(UDynamicMesh* CollideMesh);


	UFUNCTION(BlueprintCallable)
	void SetMeshInfo(UDynamicMesh* TargetMesh, UDynamicMeshComponent* UDMC, float resolution);

	UFUNCTION(BlueprintCallable)
	void GetColNearInfo(UDynamicMesh* CollideMesh, FVector ColNearVector, int32 TN);

	UPROPERTY(EditAnywhere)
	float EdgeCompliance = 100.0;

	UPROPERTY(EditAnywhere)
	float VolCompliance = 0.0;

	UPROPERTY(EditAnywhere)
		int32 NumSubsteps;

	UPROPERTY(EditAnywhere)
		FVector Gravity;

	/**
	 * This function will fire the OnRebuildGeneratedMesh event if the actor has been
	 * marked for a pending rebuild (eg via OnConstruction)
	 */
	virtual void ExecuteRebuildGeneratedMeshIfPending() override;

	virtual void BeginPlay() override;

	void CreateMeshInfo();

	void PreSolve(float DeltaTime);

	void Solve(float DeltaTime);

	void PostSolve(float DeltaTime);

	void SolveEdges(float Compliance, float DeltaTime);
	void SolveVolumes(float Compliance, float DeltaTime);

	float GetVolume(int Nr);

	void CalculateNormals();

	void CustomPhysics(float DeltaTime);

	void GenerateTetmesh(FDynamicMesh3 Mesh, float resolution);

	float RandEps();

	TArray<int32> CreateTetIds(TArray<FVector> verts, FDynamicMesh3 Mesh, float minQuality);

	FVector GetCircumCenter(FVector p0, FVector p1, FVector p2, FVector p3);

	bool CompareEdges(FVector4 e0, FVector4 e1);

	bool EqualEdges(FVector4 e0, FVector4 e1);
	float TetQuality(FVector p0, FVector p1, FVector p2, FVector p3);
	void TempTet(FDynamicMesh3 Mesh);

	void IsInCol(FDynamicMesh3 OtherMesh, int32 TN);
	protected:
	FDynamicMesh3 MyMesh;
	TArray<int32> IsCheck;
	int NumParticles;
	TArray<FVector> Pos;

	//gravity vel
	TArray<FVector> Vel;

	//	PrevPos = TArray<FVector>(Pos);
	TArray<FVector> PrevPos;

	//verts normals
	TArray<FVector> Normals;

	//Triangles = TArray<int32>(TetMeshData->tetSurfaceTriIds);

	//inverse mass
	TArray<float> InvMass;

	TArray<int32> VertIds;
	//EdgeIds = TArray<int>(tetMeshData->tetEdgeIds);
	TArray<FDynamicMesh3::FEdge> EdgeIds;
	TArray<FVector> Triangles;
	//TriangleIDs = tetMeshData->tetSurfaceTriIds;
	TArray<int32> TriangleIDs;
	TArray<float> RestVol;
	TArray<float> EdgeLengths;
	TArray<FVector> Temp;
	TArray<FVector> Grads;
	int VolIdOrder[4][3] =
	{
		{1, 3, 2},
		{0, 2, 3},
		{0, 3, 1},
		{0, 1, 2}
	};
	TArray<FVector> tetFaces =
	{
		{2,1,0},
		{0,1,3},
		{1,2,3},
		{2,0,3}
	};
	float inf = 100000;

	TArray<FVector> skinPos;
	TArray<FVector> skinVel;



	struct TetMesh
	{
		
		int32 NumTets;
		int32 NumTetParticles;
		TArray<FVector> tetPos;
		TArray<FVector> tetVel;
		TArray<int32> tetIds;
		TArray<FVector> tetEdgeIds;
		TArray<FVector> tetEdges;
		TArray<int32> tetSurfaceTriIds;
		TArray<FVector> tetTriangles;
		TArray<float> tetEdgeLengths;
		TArray<FVector> tetPrevPos;
	};
	TetMesh MyTet;

};

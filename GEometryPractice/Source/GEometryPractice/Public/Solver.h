// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GeometryTypes.h"

#include "DynamicMeshEditor.h"

#include "Spatial/FastWinding.h"
#include "DynamicMesh/DynamicMeshAABBTree3.h"

#include "Util/ProgressCancel.h"


class GEOMETRYPRACTICE_API FSolver
{
public:

	TArray<int32> Triangles;
	TArray<int32> EdgeIds;
	


	FSolver()
	{}
	~FSolver();
};



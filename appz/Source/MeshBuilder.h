#pragma once
/****************************************************************************/
/*!
\file MeshBuilder.h
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A class that provides methods to generate mesh of different shapes
*/
/****************************************************************************/
#include "Mesh.h"

/******************************************************************************/
/*!
Class MeshBuilder:
\brief
Provides methods to generate mesh of different shapes
*/
/******************************************************************************/
class MeshBuilder
{
public:
	static void GenerateQuad(Mesh* mesh, const Color& color, const float& lengthX, const float& lengthY);
	static void GenerateRepeatQuad(Mesh* mesh, const Color& color, const float& lengthX, const float& lengthY);
	static void GenerateCube(Mesh* mesh, const Color& color, const float& lengthX, const float& lengthY, const float& lengthZ);
	static void GenerateSphere(Mesh* mesh, const Color& color, const float& radius, const int& nSegments = 48, const int& nRings = 48);
	static void GenerateCone(Mesh* mesh, const Color& color, const float& height, const float& radius, const int& nSlices = 32);
	static void GenerateCylinder(Mesh* mesh, const Color& color, const float& height, const float& radius, const int& nSlices = 32, const float& thickness = 0);
	static void GenerateRing(Mesh* mesh, const Color& color, const float& radius, const float& thickness, const int& nSlices = 32);
	static void GenerateCircle(Mesh* mesh, const Color& color, const float& radius, const int& nSlices = 32);
	static void GenerateOBJ(Mesh* mesh, const std::wstring &file_path);
	static void GenerateText(Mesh* mesh, const unsigned& numRow, const unsigned& numCol);
};
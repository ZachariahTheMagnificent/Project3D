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
	static void GenerateOBJ(Mesh* mesh, const std::wstring &file_path);
	static void GenerateText(Mesh* mesh, const unsigned& numRow, const unsigned& numCol);
};
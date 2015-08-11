#pragma once

#include <string>
#include "Mesh.h"
/****************************************************************************/
/*!
\file LoadObj.h
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A class used to load OBJs
*/
/****************************************************************************/

/****************************************************************************/
/*!
Class ObjLoader:
\brief
used to load OBJs
*/
/****************************************************************************/
class ObjLoader
{
public:
	static bool LoadOBJ(std::wstring file_path, Mesh* mesh);
};
#include <vector>
#include "MeshBuilder.h"
#include "LoadOBJ.h"
/****************************************************************************/
/*!
\file MeshBuilder.cpp
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A class that provides methods to generate mesh of different shapes
*/
/****************************************************************************/

/****************************************************************************/
/*!
\brief
Generates quads
\param meshName
		the name of the quad
\param color
		the color of the quad
\param lengthX
		the x-length of the quad
\param lengthY
		the y-length of the quad
*/
/****************************************************************************/
void MeshBuilder::GenerateQuad(Mesh* mesh, const Color& color, const float& lengthX, const float& lengthY)
{
	std::vector<Vertex> vertex_buffer_data;
	vertex_buffer_data.resize(4);

	vertex_buffer_data[0].pos.Set(lengthX/2,lengthY/2,0);
	vertex_buffer_data[1].pos.Set(-lengthX/2,lengthY/2,0);
	vertex_buffer_data[2].pos.Set(lengthX/2,-lengthY/2,0);
	vertex_buffer_data[3].pos.Set(-lengthX/2,-lengthY/2,0);

	vertex_buffer_data[0].normal.Set(0,0,1);
	vertex_buffer_data[1].normal.Set(0,0,1);
	vertex_buffer_data[2].normal.Set(0,0,1);
	vertex_buffer_data[3].normal.Set(0,0,1);

	vertex_buffer_data[0].texCoord.Set(1, 1);
	vertex_buffer_data[1].texCoord.Set(0, 1);
	vertex_buffer_data[2].texCoord.Set(1, 0);
	vertex_buffer_data[3].texCoord.Set(0, 0);

	for(std::vector<Vertex>::iterator vert = vertex_buffer_data.begin(); vert != vertex_buffer_data.end(); vert++)
	{
		vert->color = color;
	}
	
	mesh->SetSize(2);
	Vertex* vert = &mesh->GetBegin()->vertex1;
	vert[0] = vertex_buffer_data[2];
	vert[1] = vertex_buffer_data[0];
	vert[2] = vertex_buffer_data[1];
	vert[3] = vertex_buffer_data[3];
	vert[4] = vertex_buffer_data[2];
	vert[5] = vertex_buffer_data[1];
}
/****************************************************************************/
/*!
\brief
Generates meshes from an *.obj
\param meshName
		the name of the mesh
\param file_path
		the location of the *.obj
*/
/****************************************************************************/
void MeshBuilder::GenerateOBJ(Mesh* mesh, const std::wstring &file_path)
{
	ObjLoader::LoadOBJ(file_path, mesh);
}
/****************************************************************************/
/*!
\brief
Generates a mesh used for rendering text
\param meshName
		the name of the mesh text
\param numRow
		the number of rows of characters the text will have
\param numColumn
		the number of columns of characters the text will have
*/
/****************************************************************************/
void MeshBuilder::GenerateText(Mesh* mesh, const unsigned& numRow, const unsigned& numCol)
{
	const double incrementU = 1.0 / numCol;
	const double decrementV = 1.0 / numRow;
	Vector2 BottomLeft(0, 1 - decrementV);
	Vector2 BottomRight(incrementU, 1 - decrementV);
	Vector2 TopLeft(0, 1);
	Vector2 TopRight(incrementU, 1);
	Color color(1,1,1);
	Vector3 normal;

	mesh->SetSize(2 * numRow * numCol);
	Vertex* vert = (Vertex*)mesh->GetBegin();

	for(unsigned y = 0; y < numRow; y++)
	{
		for(unsigned x = 0; x < numCol; x++)
		{
			vert->pos.Set(0, 1, 0);
			vert->color = color;
			vert->normal = normal;
			vert->texCoord = TopLeft;
			vert++;

			vert->pos.Set(1, 0, 0);
			vert->color = color;
			vert->normal = normal;
			vert->texCoord = BottomRight;
			vert++;

			vert->pos.Set(1, 1, 0);
			vert->color = color;
			vert->normal = normal;
			vert->texCoord = TopRight;
			vert++;

			vert->pos.Set(0, 0, 0);
			vert->color = color;
			vert->normal = normal;
			vert->texCoord = BottomLeft;
			vert++;

			vert->pos.Set(1, 0, 0);
			vert->color = color;
			vert->normal = normal;
			vert->texCoord = BottomRight;
			vert++;

			vert->pos.Set(0, 1, 0);
			vert->color = color;
			vert->normal = normal;
			vert->texCoord = TopLeft;
			vert++;
			BottomLeft.x += incrementU;
			BottomRight.x += incrementU;
			TopLeft.x += incrementU;
			TopRight.x += incrementU;
		}
		BottomLeft.y -= decrementV;
		BottomRight.y -= decrementV;
		TopLeft.y -= decrementV;
		TopRight.y -= decrementV;
	}
}
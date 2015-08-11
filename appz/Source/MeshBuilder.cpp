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
	
	mesh->setPolySize(2);
	Vertex* vert = (Vertex*)mesh->GetPolyBuffer();
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
Generates quads with repeated textures in mind
\param meshName
		the name of the quad
\param color
		the color of the quad
\lengthX
		the x-length of the quad
\lengthY
		the y-length of the quad
*/
/****************************************************************************/
void MeshBuilder::GenerateRepeatQuad(Mesh* mesh, const Color& color, const float& lengthX, const float& lengthY)
{
	std::vector<Vertex> vertex_buffer_data;
	vertex_buffer_data.resize(4);

	vertex_buffer_data[0].pos.Set(lengthX/2,0,lengthY/2);
	vertex_buffer_data[1].pos.Set(-lengthX/2,0,lengthY/2);
	vertex_buffer_data[2].pos.Set(lengthX/2,0,-lengthY/2);
	vertex_buffer_data[3].pos.Set(-lengthX/2,0,-lengthY/2);

	vertex_buffer_data[0].normal.Set(0,1,0);
	vertex_buffer_data[1].normal.Set(0,1,0);
	vertex_buffer_data[2].normal.Set(0,1,0);
	vertex_buffer_data[3].normal.Set(0,1,0);

	vertex_buffer_data[3].texCoord.Set(50, 50);
	vertex_buffer_data[1].texCoord.Set(0, 50);
	vertex_buffer_data[2].texCoord.Set(50, 0);
	vertex_buffer_data[0].texCoord.Set(0, 0);

	for(std::vector<Vertex>::iterator vert = vertex_buffer_data.begin(); vert != vertex_buffer_data.end(); vert++)
	{
		vert->color = color;
	}

	mesh->setPolySize(2);
	Vertex* vert = (Vertex*)mesh->GetPolyBuffer();
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
Generates cuboids
\param meshName
		the name of the cuboid
\param color
		the color of the cuboid
\param lengthX
		the x-length of the cuboid
\param lengthY
		the y-length of the cuboid
\param lengthZ
		the z-length of the cuboid
*/
/****************************************************************************/
void MeshBuilder::GenerateCube(Mesh* mesh, const Color& color, const float& lengthX, const float& lengthY, const float& lengthZ)
{
	Vertex v;
	std::vector<Vertex> vertex_buffer_data;

	v.pos.Set(-lengthX/2, -lengthY/2, -lengthZ/2);
	v.color = color;
	vertex_buffer_data.push_back(v);
	v.pos.Set(lengthX/2, -lengthY/2, -lengthZ/2);
	v.color = color;
	vertex_buffer_data.push_back(v);
	v.pos.Set(lengthX/2, lengthY/2, -lengthZ/2);
	v.color = color;
	vertex_buffer_data.push_back(v);
	v.pos.Set(-lengthX/2, lengthY/2, -lengthZ/2);
	v.color = color;
	vertex_buffer_data.push_back(v);
	v.pos.Set(-lengthX/2, -lengthY/2, lengthZ/2);
	v.color = color;
	vertex_buffer_data.push_back(v);
	v.pos.Set(lengthX/2, -lengthY/2, lengthZ/2);
	v.color = color;
	vertex_buffer_data.push_back(v);
	v.pos.Set(lengthX/2, lengthY/2, lengthZ/2);
	v.color = color;
	vertex_buffer_data.push_back(v);
	v.pos.Set(-lengthX/2, lengthY/2, lengthZ/2);
	v.color = color;
	vertex_buffer_data.push_back(v);
	
	mesh->setPolySize(12);
	Vertex* vert = (Vertex*)mesh->GetPolyBuffer();
	vert[0] = vertex_buffer_data[7];
	vert[0].normal.Set(0, 0, 1);
	vert[1] = vertex_buffer_data[4];
	vert[1].normal.Set(0, 0, 1);
	vert[2] = vertex_buffer_data[6];
	vert[2].normal.Set(0, 0, 1);
	vert[3] = vertex_buffer_data[5];
	vert[3].normal.Set(0, 0, 1);
	vert[4] = vertex_buffer_data[6];
	vert[4].normal.Set(0, 0, 1);
	vert[5] = vertex_buffer_data[4];
	vert[5].normal.Set(0, 0, 1);
	vert[6] = vertex_buffer_data[6];
	vert[6].normal.Set(1, 0, 0);
	vert[7] = vertex_buffer_data[5];
	vert[7].normal.Set(1, 0, 0);
	vert[8] = vertex_buffer_data[2];
	vert[8].normal.Set(1, 0, 0);
	vert[9] = vertex_buffer_data[1];
	vert[9].normal.Set(1, 0, 0);
	vert[10] = vertex_buffer_data[2];
	vert[10].normal.Set(1, 0, 0);
	vert[11] = vertex_buffer_data[5];
	vert[11].normal.Set(1, 0, 0);
	vert[12] = vertex_buffer_data[3];
	vert[12].normal.Set(0, 1, 0);
	vert[13] = vertex_buffer_data[7];
	vert[13].normal.Set(0, 1, 0);
	vert[14] = vertex_buffer_data[2];
	vert[14].normal.Set(0, 1, 0);
	vert[15] = vertex_buffer_data[6];
	vert[15].normal.Set(0, 1, 0);
	vert[16] = vertex_buffer_data[2];
	vert[16].normal.Set(0, 1, 0);
	vert[17] = vertex_buffer_data[7];
	vert[17].normal.Set(0, 1, 0);
	vert[18] = vertex_buffer_data[2];
	vert[18].normal.Set(0, 0, -1);
	vert[19] = vertex_buffer_data[1];
	vert[19].normal.Set(0, 0, -1);
	vert[20] = vertex_buffer_data[3];
	vert[20].normal.Set(0, 0, -1);
	vert[21] = vertex_buffer_data[0];
	vert[21].normal.Set(0, 0, -1);
	vert[22] = vertex_buffer_data[3];
	vert[22].normal.Set(0, 0, -1);
	vert[23] = vertex_buffer_data[1];
	vert[23].normal.Set(0, 0, -1);
	vert[24] = vertex_buffer_data[3];
	vert[24].normal.Set(-1, 0, 0);
	vert[25] = vertex_buffer_data[0];
	vert[25].normal.Set(-1, 0, 0);
	vert[26] = vertex_buffer_data[7];
	vert[26].normal.Set(-1, 0, 0);
	vert[27] = vertex_buffer_data[4];
	vert[27].normal.Set(-1, 0, 0);
	vert[28] = vertex_buffer_data[7];
	vert[28].normal.Set(-1, 0, 0);
	vert[29] = vertex_buffer_data[0];
	vert[29].normal.Set(-1, 0, 0);
	vert[30] = vertex_buffer_data[1];
	vert[30].normal.Set(0, -1, 0);
	vert[31] = vertex_buffer_data[5];
	vert[31].normal.Set(0, -1, 0);
	vert[32] = vertex_buffer_data[0];
	vert[32].normal.Set(0, -1, 0);
	vert[33] = vertex_buffer_data[4];
	vert[33].normal.Set(0, -1, 0);
	vert[34] = vertex_buffer_data[0];
	vert[34].normal.Set(0, -1, 0);
	vert[35] = vertex_buffer_data[5];
	vert[35].normal.Set(0, -1, 0);
}
/****************************************************************************/
/*!
\brief
Generates spheres
\param meshName
		the name of the sphere
\param color
		the color of the sphere
\param radius
		the radius of the sphere
\param nSegments
		the number of segments(verticals) the sphere has
\param nRings
		the number of rings(horizontals) the sphere has
*/
/****************************************************************************/
void MeshBuilder::GenerateSphere(Mesh* mesh, const Color& color, const float& radius, const int& nSegments, const int& nRings)
{
	std::vector<Vertex> vertex_buffer_data;

	vertex_buffer_data.resize((nRings + 1) * (nSegments + 1));
	for(int index = 0; index < (nRings + 1); index++)
	{
		double ringDegree =(Math::PI / nRings) * index;
		double y = cos(ringDegree) * radius;
		if(ringDegree > Math::HALF_PI)
		{
			ringDegree = Math::PI - ringDegree;
		}
		const double ringRadius = sin(ringDegree) * radius;
		std::vector<Vertex>::iterator begin = vertex_buffer_data.begin() + (index * (nSegments + 1));
		std::vector<Vertex>::iterator end = begin + (nSegments + 1);
		double degree = 0;
		double increment = Math::TWO_PI/nSegments;
		for(std::vector<Vertex>::iterator vert = begin; vert != end; vert++)
		{
			double x;
			double z;
			if(degree < Math::HALF_PI)
			{
				x = sin(degree) * ringRadius;
				z = cos(degree) * ringRadius;
				vert->pos.Set(x,y,z);
				vert->normal.Set(x,y,z);
				vert->color = color;
			}
			else if(degree < Math::PI)
			{
				x = sin(Math::PI - degree) * ringRadius;
				z = cos(Math::PI - degree) * ringRadius * -1;
				vert->pos.Set(x,y,z);
				vert->normal.Set(x,y,z);
				vert->color = color;
			}
			else if(degree < Math::PI + Math::HALF_PI)
			{
				x = cos(Math::PI + Math::HALF_PI - degree) * ringRadius * -1;
				z = sin(Math::PI + Math::HALF_PI - degree) * ringRadius * -1;
				vert->pos.Set(x,y,z);
				vert->normal.Set(x,y,z);
				vert->color = color;
			}
			else
			{
				x = sin(Math::TWO_PI - degree) * ringRadius * -1;
				z = cos(Math::TWO_PI - degree) * ringRadius;
				vert->pos.Set(x,y,z);
				vert->normal.Set(x,y,z);
				vert->color = color;
			}
			degree+= increment;
		}
	}

	mesh->setPolySize(nRings * nSegments * 2);
	int iFace = 0;
	Vertex* end = (Vertex*)(mesh->GetPolyBuffer() + mesh->GetNPolies());
	for(Vertex* vert = (Vertex*)mesh->GetPolyBuffer(); vert != end; iFace++)
	{
		for(int segment = 0; segment  < nSegments; segment++)
		{
			//Triangle #1
			*vert = vertex_buffer_data[iFace];
			++vert;
			*vert = vertex_buffer_data[iFace + (nSegments + 1)];
			++vert;
			*vert = vertex_buffer_data[iFace + (nSegments + 1) + 1];

			++vert;

			//Triangle #2
			*vert = vertex_buffer_data[iFace];
			++vert;
			*vert = vertex_buffer_data[iFace + (nSegments + 1) + 1];
			++vert;
			*vert = vertex_buffer_data[iFace + 1];
			++vert;
			iFace++;
		}
	}
}
/****************************************************************************/
/*!
\brief
Generates cones
\param meshName
		the name of the cone
\param color
		the color of the cone
\param height
		the height of the cone
\param radius
		the radius of the base of the cone
\param nSlices
		the number of slices(verticals) the cone has
*/
/****************************************************************************/
void MeshBuilder::GenerateCone(Mesh* mesh, const Color& color, const float& height, const float& radius, const int& nSlices)
{
	std::vector<Vertex> vertex_buffer_data;

	//two extra vertices for the tip of the cone and centre of the circle 
	vertex_buffer_data.resize((nSlices + 1) + 2);

	//vertices for the circle
	double degree = 0;
	double increment = Math::TWO_PI/nSlices;
	std::vector<Vertex>::iterator vert;
	for(vert = vertex_buffer_data.begin(); vert != vertex_buffer_data.end() - 2; vert++)
	{
		double x;
		double z;
		if(degree < Math::HALF_PI)
		{
			x = sin(degree) * radius;
			z = cos(degree) * radius;
			vert->pos.Set(x,-height/2,z);
			vert->color = color;
		}
		else if(degree < Math::PI)
		{
			x = sin(Math::PI - degree) * radius;
			z = cos(Math::PI - degree) * radius * -1;
			vert->pos.Set(x,-height/2,z);
			vert->color = color;
		}
		else if(degree < Math::PI + Math::HALF_PI)
		{
			x = cos(Math::PI + Math::HALF_PI - degree) * radius * -1;
			z = sin(Math::PI + Math::HALF_PI - degree) * radius * -1;
			vert->pos.Set(x,-height/2,z);
			vert->color = color;
		}
		else
		{
			x = sin(Math::TWO_PI - degree) * radius * -1;
			z = cos(Math::TWO_PI - degree) * radius;
			vert->pos.Set(x,-height/2,z);
			vert->color = color;
		}
		degree+= increment;
	}

	//vertex for centre of circle
	vert->pos.Set(0,-height/2,0);
	vert->color = color;
	vert++;

	//vertex for tip of cone
	vert->pos.Set(0,height/2,0);
	vert->color = color;


	//Where the actual verts are placed.
	mesh->setPolySize(nSlices * 2);
	//Index and other variables are defined outside so they can be reused in other loops
	Vertex* vertex;
	Vertex* end = ((Vertex*)mesh->GetPolyBuffer()) + nSlices * 3;
	int iCentre = nSlices + 1;
	int iFace = 0;

	//for loop for the base of the cone
	for(vertex = (Vertex*)mesh->GetPolyBuffer(); vertex != end; ++vertex)
	{
		*vertex = vertex_buffer_data[iFace];
		vertex->normal.Set(0.f, -1.f, 0.f);
		++vertex;
		*vertex = vertex_buffer_data[iCentre];
		vertex->normal.Set(0.f, -1.f, 0.f);
		++vertex;
		*vertex = vertex_buffer_data[iFace + 1];
		vertex->normal.Set(0.f, -1.f, 0.f);
		++iFace;
	}

	iFace = 0;
	++iCentre;
	end = (Vertex*)(mesh->GetPolyBuffer() + mesh->GetNPolies());

	//for loop for the sides of the cone
	for(; vertex != end; ++vertex)
	{
		*vertex = vertex_buffer_data[iFace + 1];
		vertex->normal = vertex->pos;
		vertex->normal.y = height;
		++vertex;
		*vertex = vertex_buffer_data[iCentre];
		vertex->normal = vertex->pos;
		++vertex;
		*vertex = vertex_buffer_data[iFace];
		vertex->normal = vertex->pos;
		vertex->normal.y = height;
		iFace++;
	}
}
/****************************************************************************/
/*!
\brief
Generates cylinders
\param meshName
		the name of the cylinder
\param color
		the color of the cylinder
\param height
		the height of the cylinder
\param radius
		the radius of the cylinder
\param thickness
		the thickness of the cylinder(a value of 1 gives a solid cylinder)
*/
/****************************************************************************/
void MeshBuilder::GenerateCylinder(Mesh* mesh, const Color& color, const float& height, const float& radius, const int& nSlices, const float& thickness)
{
	std::vector<Vertex> vertex_buffer_data;

	//two extra vertices for the two centres of the base and top of the cylinder
	vertex_buffer_data.resize((nSlices + 1)*2 + 2);

	//vertices for the circle
	{
		double y = -height/2;
		std::vector<Vertex>::iterator end = vertex_buffer_data.begin() + nSlices + 1;
		std::vector<Vertex>::iterator vert = vertex_buffer_data.begin();
		//for loop that loops twice to create the bottom and top of the cylinder
		for(int index = 0; index < 2; index++)
		{
			double degree = 0;
			double increment = Math::TWO_PI/nSlices;
			for(; vert != end; vert++)
			{
				double x;
				double z;
				if(degree < Math::HALF_PI)
				{
					x = sin(degree) * radius;
					z = cos(degree) * radius;
					vert->pos.Set(x,y,z);
					vert->color = color;
				}
				else if(degree < Math::PI)
				{
					x = sin(Math::PI - degree) * radius;
					z = cos(Math::PI - degree) * radius * -1;
					vert->pos.Set(x,y,z);
					vert->color = color;
				}
				else if(degree < Math::PI + Math::HALF_PI)
				{
					x = cos(Math::PI + Math::HALF_PI - degree) * radius * -1;
					z = sin(Math::PI + Math::HALF_PI - degree) * radius * -1;
					vert->pos.Set(x,y,z);
					vert->color = color;
				}
				else
				{
					x = sin(Math::TWO_PI - degree) * radius * -1;
					z = cos(Math::TWO_PI - degree) * radius;
					vert->pos.Set(x,y,z);
					vert->color = color;
				}
				degree+= increment;
			}
			//defining the centre
			vert->pos.Set(0,y,0);
			vert->color = color;
			vert++;
			y = height/2;
			end = vertex_buffer_data.end() - 1;
		}
	}
	
	mesh->setPolySize(nSlices * 4);
	//index and other variables are defined outside the loop so they can be reused
	Vertex* index = (Vertex*)mesh->GetPolyBuffer();
	Vertex* end = index + nSlices*3;
	int iFace = 0;
	int iCentre = nSlices + 1;
	//for loop for the bottom of the cylinder
	for(; index != end; index++)
	{
		*index = vertex_buffer_data[iFace];
		index->normal.Set(0.f, -1.f, 0.f);
		index++;
		*index = vertex_buffer_data[iCentre];
		index->normal.Set(0.f, -1.f, 0.f);
		index++;
		*index = vertex_buffer_data[iFace + 1];
		index->normal.Set(0.f, -1.f, 0.f);
		iFace++;
	}

	iFace+=2;
	iCentre = (nSlices + 1) * 2 + 1;
	end += nSlices*3;
	//for loop for top of the cylinder
	for(; index != end; index++)
	{
		*index = vertex_buffer_data[iFace + 1];
		index->normal.Set(0.f, -1.f, 0.f);
		index++;
		*index = vertex_buffer_data[iCentre];
		index->normal.Set(0.f, -1.f, 0.f);
		index++;
		*index = vertex_buffer_data[iFace];
		index->normal.Set(0.f, -1.f, 0.f);
		iFace++;
	}

	end = (Vertex*)(mesh->GetPolyBuffer() + mesh->GetNPolies());
	iFace = 0;

	//for loop for the sides of the cylinder
	for(; index != end; index++)
	{
		//Triangle #1
		*index = vertex_buffer_data[iFace + nSlices + 2];
		index->normal.x = index->pos.x;
		index->normal.z = index->pos.z;
		index++;
		*index = vertex_buffer_data[iFace];
		index->normal.x = index->pos.x;
		index->normal.z = index->pos.z;
		index++;
		*index = vertex_buffer_data[iFace + 1];
		index->normal.x = index->pos.x;
		index->normal.z = index->pos.z;
		index++;

		//Triangle #2
		*index = vertex_buffer_data[iFace + nSlices + 2];
		index->normal.x = index->pos.x;
		index->normal.z = index->pos.z;
		index++;
		*index = vertex_buffer_data[iFace + 1];
		index->normal.x = index->pos.x;
		index->normal.z = index->pos.z;
		index++;
		*index = vertex_buffer_data[iFace + nSlices + 3];
		index->normal.x = index->pos.x;
		index->normal.z = index->pos.z;
		iFace++;
	}
}
/****************************************************************************/
/*!
\brief
Generates rings
\param meshName
		the name of the ring
\param color
		the color of the ring
\param radius
		the radius of the ring
\param thickness
		the thickness of the ring
\param nSlices
		the number of slices(verticals) the ring has
*/
/****************************************************************************/
void MeshBuilder::GenerateRing(Mesh* mesh, const Color& color, const float& radius, const float& thickness, const int& nSlices)
{
	std::vector<Vertex> vertex_buffer_data;

	vertex_buffer_data.resize(nSlices * 2 + 2);
	double degree = 0;
	double increment = Math::TWO_PI/nSlices;
	for(std::vector<Vertex>::iterator vert = vertex_buffer_data.begin(); vert != vertex_buffer_data.end(); vert++)
	{
		double x;
		double z;
		if(degree < Math::HALF_PI)
		{
			x = sin(degree) * radius;
			z = cos(degree) * radius;
			vert->pos.Set(x, 0.0f, z);
			vert->color = color;
			vert->normal.Set(0.0f, 1.0f, 0.0f);
			vert++;
			x = sin(degree) * (radius - thickness);
			z = cos(degree) * (radius - thickness);
			vert->pos.Set(x, 0.0f, z);
			vert->color = color;
			vert->normal.Set(0.0f, 1.0f, 0.0f);
		}
		else if(degree < Math::PI)
		{
			x = cos(degree - Math::HALF_PI) * radius;
			z = sin(degree - Math::HALF_PI) * radius * -1;
			vert->pos.Set(x, 0.0f, z);
			vert->color = color;
			vert->normal.Set(0.0f, 1.0f, 0.0f);
			vert++;
			x = cos(degree - Math::HALF_PI) * (radius - thickness);
			z = sin(degree - Math::HALF_PI) * (radius - thickness) * -1;
			vert->pos.Set(x, 0.0f, z);
			vert->color = color;
			vert->normal.Set(0.0f, 1.0f, 0.0f);
		}
		else if(degree < Math::HALF_PI * 3)
		{
			x = abs(sin(degree - Math::PI)) * radius * -1;
			z = abs(cos(degree - Math::PI)) * radius * -1;
			vert->pos.Set(x, 0.0f, z);
			vert->color = color;
			vert->normal.Set(0.0f, 1.0f, 0.0f);
			vert++;
			x = abs(sin(degree - Math::PI)) * (radius - thickness) * -1;
			z = abs(cos(degree - Math::PI)) * (radius - thickness) * -1;
			vert->pos.Set(x, 0.0f, z);
			vert->color = color;
			vert->normal.Set(0.0f, 1.0f, 0.0f);
		}
		else
		{
			x = cos(degree - Math::HALF_PI * 3) * radius * -1;
			z = sin(degree - Math::HALF_PI * 3) * radius;
			vert->pos.Set(x, 0.0f, z);
			vert->color = color;
			vert->normal.Set(0.0f, 1.0f, 0.0f);
			vert++;
			x = cos(degree - Math::HALF_PI * 3) * (radius - thickness) * -1;
			z = sin(degree - Math::HALF_PI * 3) * (radius - thickness);
			vert->pos.Set(x, 0.0f, z);
			vert->color = color;
			vert->normal.Set(0.0f, 1.0f, 0.0f);
		}

		degree+= increment;
	}

	mesh->setPolySize(nSlices * 2);
	int iFace = 0;
	Vertex* end = (Vertex*)(mesh->GetPolyBuffer() + mesh->GetNPolies());
	for(Vertex* vertex = (Vertex*)mesh->GetPolyBuffer(); vertex != end; ++vertex)
	{
		if(Math::IsOdd(iFace))
		{
			*vertex = vertex_buffer_data[iFace];
			++vertex;
			*vertex = vertex_buffer_data[iFace + 1];
			++vertex;
			*vertex = vertex_buffer_data[iFace+2];
		}
		else
		{
			*vertex = vertex_buffer_data[iFace + 1];
			++vertex;
			*vertex = vertex_buffer_data[iFace];
			++vertex;
			*vertex = vertex_buffer_data[iFace+2];
		}
		iFace++;
	}
}
/****************************************************************************/
/*!
\brief
Generates circles
\param meshName
		the name of the circle
\param color
		the color of the circle
\param radius
		the radius of the circle
\param nSlices
		the number of slices the circle has
*/
/****************************************************************************/
void MeshBuilder::GenerateCircle(Mesh* mesh, const Color& color, const float& radius, const int& nSlices)
{
	GenerateRing(mesh, color, radius, radius, nSlices);
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

	mesh->setPolySize(2 * numRow * numCol);
	Vertex* vert = (Vertex*)mesh->GetPolyBuffer();

	for(unsigned y = 0; y < numRow; y++)
	{
		for(unsigned x = 0; x < numCol; x++)
		{
			vert->pos.Set(0, 1, 0);
			vert->color;
			vert->normal;
			vert->texCoord = TopLeft;
			vert++;

			vert->pos.Set(1, 0, 0);
			vert->color;
			vert->normal;
			vert->texCoord = BottomRight;
			vert++;

			vert->pos.Set(1, 1, 0);
			vert->color;
			vert->normal;
			vert->texCoord = TopRight;
			vert++;

			vert->pos.Set(0, 0, 0);
			vert->color;
			vert->normal;
			vert->texCoord = BottomLeft;
			vert++;

			vert->pos.Set(1, 0, 0);
			vert->color;
			vert->normal;
			vert->texCoord = BottomRight;
			vert++;

			vert->pos.Set(0, 1, 0);
			vert->color;
			vert->normal;
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
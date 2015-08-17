#include "Vertex.h"

Vertex::Vertex(const Vector3& pos, const Color& color, const Vector3& normal, const Vector2& texCoord)
	:
pos(pos),
color(color),
normal(normal),
texCoord(texCoord)
{
}

Vertex::~Vertex()
{
}

void Vertex::Set(const Vector3& pos, const Color& color, const Vector3& normal, const Vector2& texCoord)
{
	this->pos = pos;
	this->color = color;
	this->normal = normal;
	this->texCoord = texCoord;
}

bool Vertex::operator<(const Vertex& someOtherVertex) const
{
	return memcmp((void*)this, (void*)&someOtherVertex, sizeof(Vertex)) > 0;
};
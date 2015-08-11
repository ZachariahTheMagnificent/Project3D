#include "Material.h"

Material::Material(const Color& kAmbient, const Color& kDiffuse, const Color& kSpecular, const float& kShininess, const Texture* texture)
	:
kAmbient(kAmbient),
kDiffuse(kDiffuse),
kSpecular(kSpecular),
kShininess(kShininess),
texture(texture)
{
}

Material::~Material()
{
}

void Material::SetTo(const Color& kAmbient, const Color& kDiffuse, const Color& kSpecular, const float kShininess, const Texture* texture)
{
	this->kAmbient = kAmbient;
	this->kDiffuse = kDiffuse;
	this->kSpecular = kSpecular;
	this->kShininess = kShininess;
	this->texture = texture;
}
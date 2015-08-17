#include "D4DColor.h"

D4DColor::D4DColor(const unsigned char& red, const unsigned char& green, const unsigned char& blue, const unsigned char& alpha)
	:
red(red),
green(green),
blue(blue),
alpha(alpha)
{
}

D4DColor::~D4DColor()
{
}

void D4DColor::Set(const unsigned char& red, const unsigned char& green, const unsigned char& blue, const unsigned char& alpha)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = alpha;
}
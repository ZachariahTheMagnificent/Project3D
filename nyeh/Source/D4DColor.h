#pragma once

class D4DColor
{
public:
	D4DColor(const unsigned char& red = 0, const unsigned char& green = 0, const unsigned char& blue = 0, const unsigned char& alpha = 0);
	~D4DColor();
	void Set(const unsigned char& red, const unsigned char& green, const unsigned char& blue, const unsigned char& alpha);

	unsigned char red;
	unsigned char green;
	unsigned char blue;
	unsigned char alpha;
};
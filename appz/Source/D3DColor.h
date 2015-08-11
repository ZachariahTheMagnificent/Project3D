#pragma once

class Color
{
public:
	Color(float r = 1, float g = 1, float b = 1);
	~Color();
	void Set(float r, float g, float b);

	float r; 
	float g;
	float b;
};
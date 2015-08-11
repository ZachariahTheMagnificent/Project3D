struct D4DColor
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	unsigned char alpha;
	D4DColor(const unsigned char& red = 0, const unsigned char& green = 0, const unsigned char& blue = 0, const unsigned char& alpha = 0)
		:
	red(red),
	green(green),
	blue(blue),
	alpha(alpha)
	{
	}
};
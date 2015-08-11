#include <iostream>
#include <fstream>
#include "LoadTGA.h"

bool TGALoader::LoadTGA(std::wstring file_path, Texture* texture)	// load TGA file to memory
{
	std::ifstream fileStream(file_path, std::ios::binary);
	if(!fileStream.is_open())
	{
		std::cout << "Impossible to open " << file_path.c_str() << ". Are you in the right directory ?\n";
		return false;
	}

	unsigned char	header[ 18 ];									// first 6 useful header bytes
	unsigned		bytesPerPixel;									// number of bytes per pixel in TGA gile
	unsigned		imageSize;										// for setting memory
	unsigned		width, height;

	fileStream.read((char*)header, 18);
	width = header[12] + header[13] * 256;
	height = header[14] + header[15] * 256;

 	if(	width <= 0 ||												// is width <= 0
		height <= 0 ||												// is height <=0
		(header[16] != 24 && header[16] != 32))						// is TGA 24 or 32 Bit
	{
		fileStream.close();											// close file on failure
		std::cout << "File header error.\n";
		return false;										
	}

	bytesPerPixel	= header[16] / 8;								//divide by 8 to get bytes per pixel
	imageSize		= width * height * bytesPerPixel;				// calculate memory required for TGA data
	
	unsigned char*const data = new unsigned char[ imageSize ];

	fileStream.seekg(18, std::ios::beg);
	fileStream.read((char*)data, imageSize);
	fileStream.close();	

	texture->SetDimensions(width, height);

	if(bytesPerPixel == 3)
	{
		D4DColor* end = texture->GetBuffer() + texture->GetWidth() * texture->GetHeight();
		unsigned char* c = data;
		for(D4DColor* color = texture->GetBuffer(); color != end; ++color, c+=bytesPerPixel)
		{
			const char MAX_ALPHA = 255;
			memcpy(color, c, sizeof(unsigned char)*bytesPerPixel);
			color->alpha = MAX_ALPHA;
		}
	}
	else //bytesPerPixel == 4
	{
		memcpy(texture->GetBuffer(), data, sizeof(unsigned char)*bytesPerPixel*width*height);
	}

	//end of modifiable code

	delete []data;

	return true;						
}
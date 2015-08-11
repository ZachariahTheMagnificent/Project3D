#pragma once

#include <string>
#include "Texture.h"

class TGALoader
{
public:
	static bool LoadTGA(std::wstring file_path, Texture* texture);
};
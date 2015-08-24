#include "UIDataClient.h"
#include "StringData.h"
#include "DoubleData.h"
#include "FloatData.h"
#include "UnsignedData.h"
#include "IntData.h"
#include "CharData.h"

UIDataClient::UIDataClient(std::string* string)
	:
actualData(NULL)
{
	actualData = new StringData(string);
}

UIDataClient::UIDataClient(double* doub)
	:
actualData(NULL)
{
	actualData = new DoubleData(doub);
}

UIDataClient::UIDataClient(float* flt)
	:
actualData(NULL)
{
	actualData = new FloatData(flt);
}

UIDataClient::UIDataClient(unsigned* uns)
	:
actualData(NULL)
{
	actualData = new UnsignedData(uns);
}

UIDataClient::UIDataClient(int* integer)
	:
actualData(NULL)
{
	actualData = new IntData(integer);
}

UIDataClient::UIDataClient(char* character)
	:
actualData(NULL)
{
	actualData = new CharData(character);
}

UIDataClient::~UIDataClient()
{
	if(actualData)
	{
		delete actualData;
	}
}

std::ostream& operator<<(std::ostream& string, const UIDataClient& data)
{
	return data.actualData->PrintInfo(string);
}
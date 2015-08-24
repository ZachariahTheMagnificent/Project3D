#include "UIDataClient.h"
#include "StringData.h"
#include "DoubleData.h"
#include "FloatData.h"
#include "UnsignedData.h"
#include "IntData.h"
#include "CharData.h"

UIDataClient::UIDataClient()
	:
actualData(NULL)
{
}

UIDataClient::UIDataClient(const UIDataClient& data)
	:
actualData(NULL)
{
	StringData* isString = dynamic_cast<StringData*>(data.actualData);
	if(isString)
	{
		actualData = new StringData(*isString);
		return;
	}
	
	DoubleData* isDouble = dynamic_cast<DoubleData*>(data.actualData);
	if(isDouble)
	{
		actualData = new DoubleData(*isDouble);
		return;
	}
	
	FloatData* isFloat = dynamic_cast<FloatData*>(data.actualData);
	if(isFloat)
	{
		actualData = new FloatData(*isFloat);
		return;
	}
	
	UnsignedData* isUnsigned = dynamic_cast<UnsignedData*>(data.actualData);
	if(isUnsigned)
	{
		actualData = new UnsignedData(*isUnsigned);
		return;
	}
	
	IntData* isInt = dynamic_cast<IntData*>(data.actualData);
	if(isInt)
	{
		actualData = new IntData(*isInt);
		return;
	}
	
	CharData* isChar = dynamic_cast<CharData*>(data.actualData);
	if(isChar)
	{
		actualData = new CharData(*isChar);
		return;
	}
}
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

void UIDataClient::Set(std::string* string)
{
	if(actualData)
	{
		delete actualData;
		actualData = NULL;
	}

	actualData = new StringData(string);
}

void UIDataClient::Set(double* doub)
{
	if(actualData)
	{
		delete actualData;
		actualData = NULL;
	}

	actualData = new DoubleData(doub);
}

void UIDataClient::Set(float* flt)
{
	if(actualData)
	{
		delete actualData;
		actualData = NULL;
	}

	actualData = new FloatData(flt);
}

void UIDataClient::Set(unsigned* uns)
{
	if(actualData)
	{
		delete actualData;
		actualData = NULL;
	}

	actualData = new UnsignedData(uns);
}

void UIDataClient::Set(int* integer)
{
	if(actualData)
	{
		delete actualData;
		actualData = NULL;
	}

	actualData = new IntData(integer);
}

void UIDataClient::Set(char* character)
{
	if(actualData)
	{
		delete actualData;
		actualData = NULL;
	}

	actualData = new CharData(character);
}

UIDataClient::~UIDataClient()
{
	if(actualData)
	{
		delete actualData;
		actualData = NULL;
	}
}

void UIDataClient::operator=(const UIDataClient& data)
{
	StringData* isString = dynamic_cast<StringData*>(data.actualData);
	if(isString)
	{
		actualData = new StringData(*isString);
		return;
	}
	
	DoubleData* isDouble = dynamic_cast<DoubleData*>(data.actualData);
	if(isDouble)
	{
		actualData = new DoubleData(*isDouble);
		return;
	}
	
	FloatData* isFloat = dynamic_cast<FloatData*>(data.actualData);
	if(isFloat)
	{
		actualData = new FloatData(*isFloat);
		return;
	}
	
	UnsignedData* isUnsigned = dynamic_cast<UnsignedData*>(data.actualData);
	if(isUnsigned)
	{
		actualData = new UnsignedData(*isUnsigned);
		return;
	}
	
	IntData* isInt = dynamic_cast<IntData*>(data.actualData);
	if(isInt)
	{
		actualData = new IntData(*isInt);
		return;
	}
	
	CharData* isChar = dynamic_cast<CharData*>(data.actualData);
	if(isChar)
	{
		actualData = new CharData(*isChar);
		return;
	}
}

std::ostream& operator<<(std::ostream& string, const UIDataClient& data)
{
	if(data.actualData)
	{
		return data.actualData->PrintInfo(string);
	}

	return string;
}
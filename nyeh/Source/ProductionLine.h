#pragma once
#include <iostream>

template<class t>
class ProductionLine
{
public:
	ProductionLine(const unsigned& increment = 1);
	~ProductionLine();
	
	t* GetInstance();
	t* GetBegin();
	t* GetEnd();

	void SetIncrement(const unsigned& increment);
	unsigned GetCapacity();

protected:
	void IncreaseSize();

	const unsigned sizeIncrease;
	t* begin;
	t* end;
};


template<class t>
ProductionLine<t>::ProductionLine(const unsigned& increment)
	:
begin(NULL),
end(NULL),
sizeIncrease(increment)
{
}

template<class t>
ProductionLine<t>::~ProductionLine()
{
	if(begin)
	{
		delete [] begin;
		begin = NULL;
		end = NULL;
	}
}

template<class t>
t* ProductionLine<t>::GetInstance()
{
	for(t* gameObj = begin; gameObj != end; ++gameObj)
	{
		if(!gameObj->isUsed)
		{
			gameObj->isUsed = true;
			return gameObj;
		}
	}
	const unsigned lastGameObjIndex = GetCapacity();
	IncreaseSize();
	
	return begin + lastGameObjIndex;
}

template<class t>
t* ProductionLine<t>::GetBegin()
{
	return begin;
}

template<class t>
t* ProductionLine<t>::GetEnd()
{
	return end;
}

template<class t>
void ProductionLine<t>::SetIncrement(const unsigned& increment)
{
	sizeIncrease = increment;
}

template<class t>
void ProductionLine<t>::IncreaseSize()
{
	const unsigned oldCapacity = GetCapacity();
	const unsigned newCapacity = oldCapacity + sizeIncrease;

	t* buffer = new t[newCapacity];

	if(begin)
	{
		//transfer the previous asteroid data to the new memory
		memcpy(buffer, begin, sizeof(t) * oldCapacity);

		delete [] begin;
		begin = NULL;
		end = NULL;
	}

	begin = buffer;
	end = buffer + newCapacity;
}

template<class t>
unsigned ProductionLine<t>::GetCapacity()
{
	return end - begin;
}
#pragma once
#include <iostream>

template<class t>
class MyContainer
{
public:
	MyContainer(const unsigned& size = 0);
	virtual ~MyContainer();

	void SetSize(const unsigned& size);
	unsigned GetSize() const;
	t* GetBegin() const;
	t* GetEnd() const;

private:
	t* begin;
	t* end;
};

template<class t>
MyContainer<t>::MyContainer(const unsigned& size = 0)
	:
begin(NULL),
end(NULL)
{
	SetSize(size);
}

template<class t>
MyContainer<t>::~MyContainer()
{
	if(begin)
	{
		delete [] begin;
		begin = NULL;
		end = NULL;
	}
}

template<class t>
void MyContainer<t>::SetSize(const unsigned& size)
{
	if(begin)
	{
		delete [] begin;
		begin = NULL;
		end = NULL;
	}

	if(size != 0)
	{
		begin = new t[size];
		end = begin + size;
	}
}

template<class t>
unsigned MyContainer<t>::GetSize() const
{
	return end - begin;
}

template<class t>
t* MyContainer<t>::GetBegin() const
{
	return begin;
}

template<class t>
t* MyContainer<t>::GetEnd() const
{
	return end;
}
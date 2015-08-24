#pragma once

template<class t>
class Factory
{
public:
	Factory();
	virtual ~Factory();
	
	virtual t* GetInstance(unsigned type) = 0;
};

template<class t>
Factory<t>::Factory()
{
}

template<class t>
Factory<t>::~Factory()
{
}
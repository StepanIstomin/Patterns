#pragma once
#include "House.h"
class HouseBuilder
{
public:
	void SetHouse(House* _pHouse);

	House* GetResult() {
		return pHouse;
	}

	virtual void BuildPart1() = 0;
	virtual void BuildPart2() = 0;
	virtual void BuildPart3() = 0;
	virtual void BuildPart4() = 0;
	virtual void BuildPart5() = 0;
	virtual void BuildPart6() = 0;
	virtual void BuildPart7() = 0;

protected:
	House* pHouse;
};


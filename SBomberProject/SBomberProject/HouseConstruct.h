#pragma once
#include "House.h"
#include "HouseBuilderA.h"

class HouseConstruct
{
public:
	HouseConstruct() {
		HouseBuilderA houseBuilder;
	};
	void SetHouse(House* _pHouse);
	House* ConstructChimn();
	House* ConstructNoChimn();

private:
	HouseBuilderA houseBuilder;
};


#include "HouseConstruct.h"

void HouseConstruct::SetHouse(House* _pHouse)
{
    houseBuilder.SetHouse(_pHouse);
}

House* HouseConstruct::ConstructChimn()
{
    houseBuilder.BuildPart1();
    houseBuilder.BuildPart2();
    houseBuilder.BuildPart3();
    houseBuilder.BuildPart4();
    houseBuilder.BuildPart5();
    houseBuilder.BuildPart6();
    houseBuilder.BuildPart7();

    return houseBuilder.GetResult();
}

House* HouseConstruct::ConstructNoChimn()
{
    houseBuilder.BuildPart1();
    houseBuilder.BuildPart2();
    houseBuilder.BuildPart3();
    houseBuilder.BuildPart4();
    houseBuilder.BuildPart5();
    houseBuilder.BuildPart6();

    return houseBuilder.GetResult();
}

#include <cstring>

#include "HouseBuilderA.h"

void HouseBuilderA::BuildPart1()
{
    strcpy_s(pHouse->look[0], "#__________#");
}

void HouseBuilderA::BuildPart2()
{
    strcpy_s(pHouse->look[1], "#          #");
}

void HouseBuilderA::BuildPart3()
{
    strcpy_s(pHouse->look[2], "#          #");
}

void HouseBuilderA::BuildPart4()
{
    strcpy_s(pHouse->look[3], "#----------#");
}

void HouseBuilderA::BuildPart5()
{
    strcpy_s(pHouse->look[4], "##        ##");
}

void HouseBuilderA::BuildPart6()
{
    strcpy_s(pHouse->look[5], "  ########  ");
}

void HouseBuilderA::BuildPart7()
{
    strcpy_s(pHouse->look[6], "       ||   ");
}

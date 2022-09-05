#include <iostream>
#include <vector>

#include "Bomb.h"
#include "MyTools.h"
#include "Tank.h"
#include "House.h"

using namespace std;
using namespace MyTools;

void Bomb::Draw() const
{
    MyTools::SetColor(CC_LightMagenta);
    GotoXY(x, y);
    cout << "*";
}

void Bomb::AddObserver(GameObject* gameObject)
{
    Tank* pTank = dynamic_cast<Tank*>(gameObject);
    if (pTank != nullptr)
    {
        groundObjects.push_back(pTank);
    }
    House* pHouse = dynamic_cast<House*>(gameObject);
    if (pHouse != nullptr)
    {
        groundObjects.push_back(pHouse);
    }
}

void Bomb::RemoveObserver(DestroyableGroundObject* pObj)
{
    auto it = groundObjects.begin();
    for (; it != groundObjects.end(); it++)
    {
        if (*it == pObj)
        {
            groundObjects.erase(it);
            break;
        }
    }
}

DestroyableGroundObject* __fastcall Bomb::CheckDestroyableObjects()
{
    for (size_t i = 0; i < groundObjects.size(); i++)
    {
        if (groundObjects[i]->HandleInsideCheck(this)) {
            
            return groundObjects[i];
        }
    }
    return nullptr;
}

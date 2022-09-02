#include "CollisionDetector.h"
#include "SBomber.h"

using namespace std;

bool CollisionDetector::CheckPlaneAndLevelGUI(double PlaneX, double GuiX)
{
    return (PlaneX > GuiX);
}

//уничтожает бомбы
void CollisionDetector::CheckBombsAndGround(
    vector<Bomb*> vecBombs,
    Ground* pGround,
    vector<DestroyableGroundObject*> vecDestoyableObjects,
    vector<DynamicObject*>& vecDynamicObj,
    vector<GameObject*>& vecStaticObj,
    int16_t* pScore) 
{
    const double y = pGround->GetY();
    for (size_t i = 0; i < vecBombs.size(); i++)
    {
        if (vecBombs[i]->GetY() >= y) // Пересечение бомбы с землей
        {
            pGround->AddCrater(vecBombs[i]->GetX());
            CheckDestroyableObjects(vecBombs[i], vecDestoyableObjects, vecStaticObj, pScore); // <----тут уничтожает объект если он попал под бомбу из vecBombs[i]
            CommandDeleteDynamicObj* command = new CommandDeleteDynamicObj(vecBombs[i], vecDynamicObj);
            command->execute();
            delete command;
        }
    }
}

//уничтожает объекты
void CollisionDetector::CheckDestroyableObjects(
    Bomb* pBomb,
    vector<DestroyableGroundObject*> vecDestoyableObjects,
    vector<GameObject*>& vecStaticObj,
    int16_t* pScore) 
{
    const double size = pBomb->GetWidth();
    const double size_2 = size / 2;
    for (size_t i = 0; i < vecDestoyableObjects.size(); i++)
    {
        const double x1 = pBomb->GetX() - size_2;
        const double x2 = x1 + size;
        if (vecDestoyableObjects[i]->isInside(x1, x2))
        {
            *pScore += vecDestoyableObjects[i]->GetScore();
            CommandDeleteStaticObj* command = new CommandDeleteStaticObj(vecDestoyableObjects[i], vecStaticObj);
            command->execute();
            delete command; 
        }
    }
}

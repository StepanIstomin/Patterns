#include "Command.h"
#include "FileLogger.h"
#include "SBomber.h"
#include "BombDecorator.h"

void __fastcall CommandDeleteDynamicObj::execute()
{
    auto it = vecDynamicObj.begin();
    for (; it != vecDynamicObj.end(); it++)
    {
        if (*it == pDynamicObj)
        {
            vecDynamicObj.erase(it);
            break;
        }
    }
}

void __fastcall CommandDeleteStaticObj::execute()
{
    auto it = vecStaticObj.begin();
    for (; it != vecStaticObj.end(); it++)
    {
        if (*it == pStaticObj)
        {
            vecStaticObj.erase(it);
            break;
        }
    }
}

void CommandDropBomb :: execute() {
    if (bombsNumber > 0)
    {
        FileLoggerSingletone::getInstance().WriteToLog(string(__FUNCTION__) + " was invoked");

        double x = pPlane->GetX() + 4;
        double y = pPlane->GetY() + 2;

        Bomb* pBomb = new Bomb;
        pBomb->SetDirection(0.3, 1);
        pBomb->SetSpeed(bombSpeed);
        pBomb->SetPos(x, y);
        pBomb->SetWidth(craterSize);

        vecDynamicObj.push_back(pBomb);
        bombsNumber--;
        score -= Bomb::BombCost;
    }
}

void CommandDropBombDecor::execute()
{
    if (bombsNumber > 0)
    {
        FileLoggerSingletone::getInstance().WriteToLog(string(__FUNCTION__) + " was invoked");

        double x = pPlane->GetX() + 4;
        double y = pPlane->GetY() + 2;

        BombDecorator* pBomb = new BombDecorator;
        pBomb->SetDirection(0.3, 1);
        pBomb->SetSpeed(bombSpeed);
        pBomb->SetPos(x, y);
        pBomb->SetWidth(craterSize);

        vecDynamicObj.push_back(pBomb);
        bombsNumber--;
        score -= Bomb::BombCost;
    }
}

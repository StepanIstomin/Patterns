
#include <conio.h>
#include <windows.h>

#include "MyTools.h"
#include "SBomber.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
#include "House.h"
#include "FileLogger.h"

using namespace std;
using namespace MyTools;

SBomber::SBomber()
    : pSBomberImpl(new SBomberImpl())
{}

SBomber::~SBomber()
{
    delete pSBomberImpl;
}

void SBomber::ProcessKBHit()
{
    pSBomberImpl->ProcessKBHit();
}

void SBomber::TimeStart()
{
    pSBomberImpl->TimeStart();
}

void SBomber::TimeFinish()
{
    pSBomberImpl->TimeFinish();
}

void SBomber::DrawFrame()
{
    pSBomberImpl->DrawFrame();
}

void SBomber::MoveObjects()
{
    pSBomberImpl->MoveObjects();
}

void SBomber::CheckObjects()
{
    pSBomberImpl->CheckObjects();
}

void SBomber::CheckPlaneAndLevelGUI()
{
    pSBomberImpl->CheckPlaneAndLevelGUI();
}

void SBomber::CheckBombsAndGround()
{
    pSBomberImpl->CheckBombsAndGround();
}

void __fastcall SBomber::CheckDestoyableObjects(Bomb* pBomb)
{
    pSBomberImpl->CheckDestoyableObjects(pBomb);
}

void __fastcall SBomber::DeleteDynamicObj(DynamicObject* pBomb)
{
    pSBomberImpl->DeleteDynamicObj(pBomb);
}

void __fastcall SBomber::DeleteStaticObj(GameObject* pObj)
{
    pSBomberImpl->DeleteStaticObj(pObj);
}

Ground* SBomber::FindGround() const
{
    return pSBomberImpl->FindGround();
}

Plane* SBomber::FindPlane() const
{
    return pSBomberImpl->FindPlane();
}

LevelGUI* SBomber::FindLevelGUI() const
{
    return pSBomberImpl->FindLevelGUI();
}

std::vector<DestroyableGroundObject*> SBomber::FindDestoyableGroundObjects() const
{
    return pSBomberImpl->FindDestoyableGroundObjects();
}

std::vector<Bomb*> SBomber::FindAllBombs() const
{
    return pSBomberImpl->FindAllBombs();
}

void SBomber::DropBomb()
{
    pSBomberImpl->DropBomb();
}


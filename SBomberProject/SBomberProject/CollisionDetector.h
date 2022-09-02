#pragma once

#include <vector>

#include "Bomb.h"
#include "Ground.h"
#include "DestroyableGroundObject.h"

using namespace std;

class CollisionDetector
{
public:
	CollisionDetector(){};
	bool CheckPlaneAndLevelGUI(double PlaneX, double GuiX);
	void CheckBombsAndGround(
		vector<Bomb*> vecBombs, 
		Ground* pGround, 
		vector<DestroyableGroundObject*> vecDestoyableObjects,
		vector<DynamicObject*>& vecDynamicObj,
		vector<GameObject*>& vecStaticObj,
		int16_t* pScore);
	void CheckDestroyableObjects(
		Bomb* pBomb, 
		vector<DestroyableGroundObject*> vecDestoyableObjects, 
		vector<GameObject*>& vecStaticObj, 
		int16_t* pScore);
};


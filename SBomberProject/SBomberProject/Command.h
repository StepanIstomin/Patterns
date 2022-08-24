#pragma once

#include <vector>

#include "SBomber.h"
#include "Plane.h"

class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;
};
class CommandDeleteDynamicObj : public Command
{
public:
	CommandDeleteDynamicObj(DynamicObject* _DynamicObj, std::vector<DynamicObject*>& _vecDynamicObj) :pDynamicObj(_DynamicObj), vecDynamicObj(_vecDynamicObj) {}
	void __fastcall execute();
private:
	DynamicObject* pDynamicObj;
	std::vector<DynamicObject*>& vecDynamicObj;
};
class CommandDeleteStaticObj : public Command
{
public:
	CommandDeleteStaticObj(GameObject* _StaticObj, std::vector<GameObject*>& _vecStaticObj) :pStaticObj(_StaticObj), vecStaticObj(_vecStaticObj) {}
	void __fastcall execute();
private:
	GameObject* pStaticObj;
	std::vector<GameObject*>& vecStaticObj;
};
class CommandDropBomb : public Command
{
public:
	CommandDropBomb(Plane* const _plane, std::vector<DynamicObject*>& _vecDynamicObj, uint16_t& _bombsNumber, int16_t& _score, int16_t _bombSpeed = 2, CraterSize _craterSize = SMALL_CRATER_SIZE)
		:pPlane(_plane), vecDynamicObj(_vecDynamicObj), bombsNumber(_bombsNumber), score(_score),bombSpeed(_bombSpeed), craterSize(_craterSize){};
	void execute();
protected:
	Plane* pPlane;
	std::vector<DynamicObject*>& vecDynamicObj;
	uint16_t& bombsNumber;
	int16_t& score;
	int16_t bombSpeed;
	CraterSize craterSize;
};
class CommandDropBombDecor : public CommandDropBomb
{
public:
	CommandDropBombDecor(Plane* const _plane, std::vector<DynamicObject*>& _vecDynamicObj, uint16_t& _bombsNumber, int16_t& _score, int16_t _bombSpeed = 2, CraterSize _craterSize = SMALL_CRATER_SIZE)
		:CommandDropBomb(_plane, _vecDynamicObj, _bombsNumber, _score) {};
	void execute();
};

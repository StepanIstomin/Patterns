#include "BombIterator.h"
#include "DynamicObject.h"

void BombIterator::reset()
{
	curIndex = -1;
	ptr = nullptr;
}

BombIterator& BombIterator::operator++()
{
	curIndex++;
	if (curIndex == -1)
		curIndex = 0;
	Bomb* pBomb;
	for (; curIndex < vecDynamicObj.size(); curIndex++)
	{
		pBomb = dynamic_cast<Bomb*>(vecDynamicObj[curIndex]);
		if (pBomb != nullptr)
		{
			ptr = vecDynamicObj[curIndex];
			break;
		}
	}
	if (curIndex == vecDynamicObj.size())
	{
		curIndex = -1;
		ptr = nullptr;
	}
	return *this;
}
BombIterator& BombIterator::operator--()
{
	if (curIndex == -1)
		curIndex = vecDynamicObj.size() - 1;
	Bomb* pBomb;
	for (; curIndex >= 0 ; curIndex--)
	{
		pBomb = dynamic_cast<Bomb*>(vecDynamicObj[curIndex]);
		if (pBomb != nullptr)
		{
			ptr = vecDynamicObj[curIndex];
			break;
		}
	}
	if (curIndex == -1)
	{
		ptr = nullptr;
	}
	return *this;
}
DynamicObject* BombIterator::operator*()
{
	return vecDynamicObj[curIndex];
}

bool BombIterator::operator==(BombIterator it)
{
	if (curIndex == it.curIndex && ptr == it.ptr && vecDynamicObj == it.vecDynamicObj)
	{
		return true;
	}
	return false;
}
bool BombIterator::operator!=(BombIterator it)
{
	return !(*this == it);
}

#include "DestroyableGroundObject.h"

bool DestroyableGroundObject::HandleInsideCheck(Bomb* pBomb)
{
    const double size = pBomb->GetWidth();
    const double x1 = pBomb->GetX() - size / 2;
    const double x2 = x1 + size;
    if (this->isInside(x1, x2))
    {
        return true;
    }
	return false;
}

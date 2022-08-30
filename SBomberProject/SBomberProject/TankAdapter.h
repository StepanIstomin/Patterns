#pragma once
#include "DestroyableGroundObject.h"
#include "TankAdaptee.h"
class TankAdapter : public DestroyableGroundObject
{
public:
    void SetPos(double nx, double ny);
    void SetWidth(uint16_t widthN);

    double GetY() const;
    double GetX() const;
    uint16_t GetWidth() const;
    uint16_t GetScore() const override;

    void Draw() const;
    bool __fastcall isInside(double x1, double x2) const;

private:
    TankAdaptee tank;
};


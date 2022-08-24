#pragma once

#include "DynamicObject.h"
#include "Bomb.h"

class BombDecorator : public DynamicObject
{
public:

    void Move(uint16_t time) override;
    void Draw() const override;

    void SetPos(double nx, double ny) override;
    void SetWidth(uint16_t widthN) override;
    void SetSpeed(double sp) override;
    void SetDirection(double dx, double dy) override;

    uint16_t GetWidth() const override;
    double GetY() const override;
    double GetX() const override;

private:
    Bomb bomb;
};
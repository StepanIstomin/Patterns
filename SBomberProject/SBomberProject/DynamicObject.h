#pragma once

#include <stdint.h>

#include "GameObject.h"

class Visitor;

class DynamicObject : public GameObject 
{
public:

    DynamicObject() : speed(0.0), xDirection(0.0), yDirection(0) { }

    inline void SetSpeed(double sp) { speed = sp; }
    inline void SetDirection(double dx, double dy) { xDirection = dx; yDirection = dy; }

    double GetSpeed() { return speed; };
    double GetDirectionX() { return xDirection; }
    double GetDirectionY() { return yDirection; }
    
    virtual void Move(uint16_t time) { x += xDirection * speed * time * 0.001; y += yDirection * speed * time * 0.001; };
    virtual void __fastcall Accept(const Visitor& v) = 0;

protected:

    double speed;
    double xDirection, yDirection;

};
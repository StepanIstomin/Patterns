#include "BombDecorator.h"
#include "MyTools.h"

using namespace MyTools;

void BombDecorator::Move(uint16_t time)
{
	bomb.Move(time * 1.6);
}

void BombDecorator::Draw() const
{
	bomb.Draw();
	GotoXY(bomb.GetX(), bomb.GetY() - 1);
	std::cout << "|";
}

void BombDecorator::SetPos(double nx, double ny) 
{ 
	bomb.SetPos(nx, ny); 
}

void BombDecorator::SetWidth(uint16_t widthN)
{
	bomb.SetWidth(widthN);
}

void BombDecorator::SetSpeed(double sp)
{
	bomb.SetSpeed(sp);
}

void BombDecorator::SetDirection(double dx, double dy) 
{
	bomb.SetDirection(dx, dy);
}

uint16_t BombDecorator::GetWidth() const 
{ 
	return bomb.GetWidth(); 
}

double BombDecorator::GetY() const {
	return bomb.GetY();
}

double BombDecorator::GetX() const {
	return bomb.GetX();
}
#include <string>
#include <iostream>

#include "LogVisitor.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void LogVisitor::log(Bomb obj) const
{
	WriteToLog("Bomb coordinates: X:" + to_string(obj.GetX()) + " Y:" + to_string(obj.GetY()));
	WriteToLog("Bomb direction: X:" + to_string(obj.GetDirectionX()) + " Y:" + to_string(obj.GetDirectionY()));
	WriteToLog("Bomb speed = ", obj.GetSpeed());
}

void LogVisitor::log(Plane obj) const
{
	WriteToLog("Plane coordinates: X:" + to_string(obj.GetX()) + " Y:" + to_string(obj.GetY()));
	WriteToLog("Plane direction: X:" + to_string(obj.GetDirectionX()) + " Y:" + to_string(obj.GetDirectionY()));
	WriteToLog("Plane speed = ", obj.GetSpeed());
}

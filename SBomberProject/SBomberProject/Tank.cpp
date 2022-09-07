
#include <iostream>

#include "Tank.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

bool Tank::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

void Tank::Draw() const
{
	MyTools::SetColor(CC_Brown);
	GotoXY(x, y - 3);
	cout << "    #####";
	GotoXY(x-2, y - 2);
	cout << "#######   #";
	GotoXY(x, y - 1);
	cout << "    #####";
	GotoXY(x,y);
	cout << " ###########";
	int seed = rand() % 200;
	string message;
	switch (seed)
	{
	case 1:
		message = "You smeared!";
		break;
	case 2:
		message = "Come get some!";
		break;
	case 3:
		message = "The armor is strong and our tanks are fast!";
		break;
	case 4:
		message = "We'll shoot you down!";
		break;

	default:
		message = "";
		break;
	}
	if (message != "")
		mediator.SendMessage(message);
}
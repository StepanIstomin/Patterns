#include "ColorPlane.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void ColorPlane::DrawBody() const
{
	MyTools::SetColor(CC_White);
	GotoXY(x, y);
	cout << "=========>";
}

void ColorPlane::DrawWings() const
{
	MyTools::SetColor(CC_Blue);
	GotoXY(x + 3, y - 1);
	cout << "\\\\\\\\";
	GotoXY(x + 3, y + 1);
	cout << "////";
}

void ColorPlane::DrawTail() const
{
	MyTools::SetColor(CC_Red);
	GotoXY(x - 2, y - 1);
	cout << "===";
}
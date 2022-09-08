#include "BigPlane.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void BigPlane::DrawBody() const
{
    MyTools::SetColor(CC_LightBlue);
    GotoXY(x, y);
    cout << "===========>";

}

void BigPlane::DrawWings() const
{
    GotoXY(x + 3, y - 2);
    cout << "\\\\";
    GotoXY(x + 3, y - 1);
    cout << "\\\\\\\\";
    GotoXY(x + 3, y + 1);
    cout << "////";
    GotoXY(x + 3, y + 2);
    cout << "//";

}

void BigPlane::DrawTail() const
{
    GotoXY(x - 2, y - 1);
    cout << "=====";

}
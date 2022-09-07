#include <conio.h>
#include "Windows.h"

#include "SBomber.h"
#include "MyTools.h"
#include "FileLogger.h"

using namespace std;

//========================================================================================================================

Mediator Tank::mediator;
std::queue <std::string> LevelGUI::tankMessages;

int main(void)
{
    srand((unsigned)time(NULL));
    FileLoggerSingletone::getInstance().OpenLogFile("log.txt");

    SBomber game;

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

        MyTools::ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();

        game.TimeFinish();
        Sleep(3);
    } while (!game.GetExitFlag());

    FileLoggerSingletone::getInstance().CloseLogFile();

    return 0;
}

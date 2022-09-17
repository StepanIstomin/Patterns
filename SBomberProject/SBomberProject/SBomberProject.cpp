
#include <conio.h>

#include "SBomber.h"
#include "MyTools.h"
#include "FileLogger.h"

using namespace std;

//========================================================================================================================

int main(void)
{
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

    } while (!game.GetExitFlag());
    game.AnimateScrolling();
    FileLoggerSingletone::getInstance().CloseLogFile();

    return 0;
}

#include <conio.h>
#include "Windows.h"

#include "SBomber.h"
#include "MyTools.h"
#include "FileLogger.h"

using namespace std;

//========================================================================================================================

int main(void)
{
    FileLoggerSingletone::getInstance().OpenLogFile("log.txt");
    srand(time(NULL));
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

#include "Mediator.h"

void Mediator::SendMessage(std::string message)
{
	LevelGUI::tankMessages.push(message);
}

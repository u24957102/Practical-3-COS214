#include "LogMessageCommand.h"
#include "ChatRoom.h"
#include "Users.h"

void LogMessageCommand::execute()
{
    // Call the ChatRoom's saveMessage method (Command pattern)
    room->saveMessage(message, fromUser);
}
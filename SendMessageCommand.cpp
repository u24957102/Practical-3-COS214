#include "SendMessageCommand.h"
#include "ChatRoom.h"
#include "Users.h"

void SendMessageCommand::execute()
{
    // Call the ChatRoom's sendMessage method (Command pattern)
    room->sendMessage(message, fromUser);
}
//LogMessageCommand.h
#ifndef LOGMESSAGECOMMAND_H
#define LOGMESSAGECOMMAND_H

#include "Command.h"
#include "ChatRoom.h"
#include "Users.h"

class LogMessageCommand : public Command
{
public:
    LogMessageCommand(ChatRoom* chatRoom, string msg, Users* user)
        : Command(chatRoom, msg, user) {}
    
    void execute() override;
};

#endif
#ifndef SENDMESSAGECOMMAND_H
#define SENDMESSAGECOMMAND_H

#include "Command.h"
#include "ChatRoom.h"
#include "Users.h"

class SendMessageCommand : public Command
{
public:
    SendMessageCommand(ChatRoom* chatRoom, string msg, Users* user)
        : Command(chatRoom, msg, user) {}
    
    void execute() override;
};

#endif

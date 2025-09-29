#ifndef CHATROOM_H
#define CHATROOM_H

#include <string>

#include "Users.h"

using namespace std;

class ChatRoom
{
private:
    Users *users;
    string *chatHistory;

public:
    virtual void registerUser(Users user);
    virtual void sendMessage(string message, Users fromUser);
    virtual void saveMessage(string message, Users fromUser);
    virtual void removeUser(Users user);
};

#endif
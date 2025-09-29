//chatroom.cpp
#include "ChatRoom.h"

vector<Users *> &ChatRoom::getUsers()
{
    return users;
}

vector<string> &ChatRoom::getChatHistory()
{
    return chatHistory;
}
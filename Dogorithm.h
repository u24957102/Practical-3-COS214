#ifndef DOGORITHM_H
#define DOGORITHM_H

#include "ChatRoom.h"

class Dogorithm : public ChatRoom
{
public:
    void registerUser(Users* user) override;
    void removeUser(Users* user) override;
    void sendMessage(string message, Users* fromUser) override;
    void saveMessage(string message, Users* fromUser) override;
};

#endif
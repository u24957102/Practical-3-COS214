#ifndef CTRLCAT_H
#define CTRLCAT_H

#include "ChatRoom.h"

class CtrlCat : public ChatRoom{
public:
    void registerUser(Users user);
    void sendMessage(string message, Users fromUser);
    void saveMessage (string message, Users fromUser);
    void removeUser(Users user);
};

#endif
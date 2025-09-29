#ifndef NAME1_H
#define NAME1_H

#include "Users.h"

class Name1 : public Users
{
public:
    Name1(string userName) : Users(userName) {}
};

#endif
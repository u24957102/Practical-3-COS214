#ifndef NAME2_H
#define NAME2_H

#include "Users.h"

class Name2 : public Users
{
public:
    Name2(string userName) : Users(userName) {}
};

#endif
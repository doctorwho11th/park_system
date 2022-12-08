#pragma once
#include "user.h"
#include <string>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//管理员类  添加，修改，删除

class Admin : public User{

public:
    void Manager();
};



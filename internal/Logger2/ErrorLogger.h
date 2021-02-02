#pragma once
#include "Logger2.h"
class ErrorLogger :
    public Logger2
{
private:
    const int el_type = 2;
public:
    ErrorLogger(string ID) : Logger2(ID) {}
    void log(int l_type, string l_args);
};


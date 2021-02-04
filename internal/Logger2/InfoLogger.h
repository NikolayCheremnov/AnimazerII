#pragma once
#include "Logger2.h"
class InfoLogger :
    public Logger2
{
private:
    const int il_type = 3;
public:
    InfoLogger(string ID) : Logger2(ID) {}
    void log(int l_type, string l_args);
};


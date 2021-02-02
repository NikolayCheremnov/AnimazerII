#pragma once
#include "Logger2.h"
class PatternLogger :
    public Logger2
{
private:
    const int pl_type = 1;
public:
    PatternLogger(string ID) : Logger2(ID) {}
    void log(int l_type, string l_args);
};


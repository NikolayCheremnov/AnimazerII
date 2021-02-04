#pragma once
#include "Logger2BuilderI.h"
#include "PatternLogger.h"
#include "ErrorLogger.h"
#include "InfoLogger.h"

using namespace std;

class StandardLogger2Builder :
    public Logger2BuilderI
{
private:
    PatternLogger* pl;
public:
    StandardLogger2Builder(string ID) : Logger2BuilderI(ID) { pl = nullptr; }
    void MakeLoggersChain();
    Logger2* getResult() { return pl; };

};


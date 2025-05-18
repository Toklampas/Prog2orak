#pragma once
#include <string>

//#include "memtrace.h"

using namespace std;

class UserInputHandler {
public:
    static int getValidatedChoice();
    static string getValidatedString(const string& prompt);
};
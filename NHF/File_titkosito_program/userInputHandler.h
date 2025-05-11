#pragma once
#include <string>
using namespace std;

class UserInputHandler {
public:
    static int getValidatedChoice();
    static string getValidatedString(const string& prompt);
};
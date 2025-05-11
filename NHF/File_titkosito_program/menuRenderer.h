#pragma once
#include <iostream>
#include <string>
using namespace std;

class MenuRenderer {
public:
    static void displayMenu(bool isFileLoaded, const string& loadedFileName);
};


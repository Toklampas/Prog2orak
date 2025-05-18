#pragma once
#include <iostream>
#include <string>

#include "memtrace.h"

using namespace std;

class MenuRenderer {
public:
    static void displayMenu(bool isFileLoaded, const string& loadedFileName);
};
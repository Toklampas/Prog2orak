#pragma once
#include <stdexcept>
#include "list.h"
#include "menuRenderer.h"
#include "fileManager.h"
#include "userInputHandler.h"
using namespace std;

class MenuSystem {
private:
    List list;
    bool isFileLoaded = false;
    string loadedFileName;

    void handleUserChoice(int choice);

public:
    void run();
};
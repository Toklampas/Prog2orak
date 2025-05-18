#include "menuRenderer.h"

#include "memtrace.h"

void MenuRenderer::displayMenu(bool isFileLoaded, const string& loadedFileName) {
    cout << "========================================" << endl;
    if (isFileLoaded)
        cout << "Current Loaded File: " << loadedFileName << endl;
    else
        cout << "Please load a file." << endl;
    cout << "========================================" << endl;
    cout << "Menu Options:" << endl;
    if (isFileLoaded) {
        cout << "1. Load Words from File\t(Already loaded)" << endl;
        cout << "2. Save Words to File" << endl;
        cout << "3. Encode Loaded File" << endl;
        cout << "4. Visualize Word List" << endl;
        cout << "5. Search for Word Code" << endl;
        cout << "6. Clear Loaded Data" << endl;
    }
    else {
        cout << "1. Load Words from File" << endl;
        cout << "2. Save Words to File\t(Unavailable)" << endl;
        cout << "3. Encode Loaded File\t(Unavailable)" << endl;
        cout << "4. Visualize Word List\t(Unavailable)" << endl;
        cout << "5. Search for Word Code\t(Unavailable)" << endl;
        cout << "6. Clear Loaded Data\t(Unavailable)" << endl;
    }
    cout << "7. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Enter your choice: ";
}
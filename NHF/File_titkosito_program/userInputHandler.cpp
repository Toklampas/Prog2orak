#include "userInputHandler.h"
#include <iostream>
#include <limits>

int UserInputHandler::getValidatedChoice() {
    int choice;
    cin >> choice;
    if (cin.fail())
    {
	    cin.clear(); // clear the error flag
	    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid (non numeric) input
        return -1;
    }
    return choice;
}

string UserInputHandler::getValidatedString(const string& input_prompt) {
    cout << input_prompt;
    string input;
    cin >> input;
    return input;
}
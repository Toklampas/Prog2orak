#include "menuSystem.h"
#include <iostream>
#include <conio.h> // For _getch()

using namespace std;

void MenuSystem::clearScreen() {
    system("cls");
}

void MenuSystem::handleUserChoice(int choice) {
    try
    {
        switch (choice) {
        case 1: { // Load Words from File
            if (isFileLoaded)
                throw logic_error("A file is already loaded. Clear the data first to load a new file.");

            string fileName = UserInputHandler::getValidatedString("Enter the input file name: ");
            if (FileManager::loadWords(fileName, list))
            {
                isFileLoaded = true;
                loadedFileName = fileName;
				clearScreen();
                cout << "Words loaded into the list from " << loadedFileName << "." << endl << endl;
            }
            else
                throw runtime_error("Failed to load words from the file.");
            break;
        }

        case 2: { // Save Words to File
            if (!isFileLoaded)
                throw logic_error("No file is loaded. Please load a file first.");

            string fileName = UserInputHandler::getValidatedString("Enter the output file name: ");
            if (FileManager::saveWords(fileName, list))
            {
				clearScreen();
                cout << "Words saved to the file: " << fileName << "." << endl << endl;
            }
            else
                throw runtime_error("Failed to save words to the file.");
            break;
        }

        case 3: { // Encode Loaded File
            if (!isFileLoaded)
                throw logic_error("No file is loaded. Please load a file first.");

            string outputFileName = UserInputHandler::getValidatedString("Enter the output file name for encoded text: ");
            if (FileManager::encodeFile(loadedFileName, outputFileName, list))
            {
				clearScreen();
                cout << "File encoded and saved to: " << outputFileName << "." << endl << endl;
            }
            else
                throw runtime_error("Failed to encode the file.");
            break;
        }

        case 4: { // Visualize Word List
            if (!isFileLoaded)
                throw logic_error("No file is loaded. Please load a file first.");

			clearScreen();
            list.visualize();
            cout << endl << "Visualization complete. Press ENTER to return to the menu!";
            char a = _getch(); // wait for a charachter to be pressed
			clearScreen();
            break;
        }

        case 5: { // Search for Word Code
            if (!isFileLoaded)
                throw logic_error("No file is loaded. Please load a file first.");

            string word = UserInputHandler::getValidatedString("Enter the word to search for: ");
            int code = list.getWordCode(word);
			clearScreen();
            if (code != 0)
                cout << "The code for '" << word << "' is: " << code << endl << endl;
            else
                cout << "Word not found in the list." << endl << endl;
            break;
        }

        case 6: { // Clear Loaded Data
            if (!isFileLoaded)
                throw logic_error("No data to clear. Please load a file first.");

            list = List();
            isFileLoaded = false;
            loadedFileName.clear();
			clearScreen();
            cout << "Loaded data has been cleared." << endl << endl;
            break;
        }

        case 7: { // Exit
			clearScreen();
            cout << "Exiting the program." << endl;
            break;
        }

        default:
            throw invalid_argument("Invalid choice. Please try again.");
        }
    }
    catch (const exception& ex)
    {
		clearScreen();
        cerr << "Error: " << ex.what() << endl << endl;
    }
}

void MenuSystem::run() {
    try
    {
        int choice;
        do
        {
            MenuRenderer::displayMenu(isFileLoaded, loadedFileName);
            choice = UserInputHandler::getValidatedChoice();
            handleUserChoice(choice);
        }
        while (choice != 7);
    }
    catch (const exception& ex)
    {
        cerr << "An error occurred in the menu system: " << ex.what() << endl;
    }
}
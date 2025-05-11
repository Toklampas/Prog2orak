#pragma once
#include "list.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <conio.h> // getch() miatt
using namespace std;

class MenuSystem {
private:
    List list;
    bool isFileLoaded = false; // Flag to track if a file has been loaded
    string loadedFileName; // Stores the name of the loaded file

    void displayMenu() const {
        cout << "========================================" << endl;
        if (isFileLoaded)
            cout << "Current Loaded File: " << loadedFileName << endl;
        else
            cout << "No file loaded yet." << endl;
        cout << "========================================" << endl;
        cout << "Menu Options:" << endl;
        
        if (isFileLoaded)
        {
            cout << "1. Load Words from File\t(Already loaded)" << endl;
            cout << "2. Save Words to File" << endl;
            cout << "3. Encode Loaded File" << endl;
            cout << "4. Visualize Word List" << endl;
            cout << "5. Search for Word Code" << endl;
            cout << "6. Clear Loaded Data" << endl;
		}
		else
		{
            cout << "1. Load Words from File" << endl;
			cout << "2. Save Words to File\t(No file)" << endl;
			cout << "3. Encode Loaded File\t(No file)" << endl;
			cout << "4. Visualize Word List\t(No file)" << endl;
			cout << "5. Search for Word Code\t(No file)" << endl;
			cout << "6. Clear Loaded Data\t(No file)" << endl;
		}
        cout << "7. Exit" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
    }

    void loadWordsFromFile()
    {
        if (isFileLoaded)
        {
            system("cls");
            cerr << "A file is already loaded. Please clear the loaded data first to load a new file." << endl << endl;
            return;
        }

        string inputFileName;
        cout << "Enter the input file name: ";
        cin >> inputFileName;

        ifstream inputFile(inputFileName);
        if (!inputFile)
        {
            system("cls");
            cerr << "Failed to open input file!" << endl << endl;
        }
        else
        {
            inputFile >> list;
            inputFile.close();
            isFileLoaded = true;
            loadedFileName = inputFileName; // Store the loaded file name
            system("cls");
            cout << "Words loaded into the list from " << loadedFileName << "." << endl << endl;
        }
    }

    void saveWordsToFile() const
    {
        if (!isFileLoaded)
        {
            system("cls");
            cerr << "You must load a file first!" << endl << endl;
            return;
        }

        string outputFileName;
        cout << "Enter the output file name: ";
        cin >> outputFileName;

        ofstream outputFile(outputFileName);
        if (!outputFile)
        {
            system("cls");
            cerr << "Failed to open output file!" << endl << endl;
        }
        else
        {
            outputFile << list;
            outputFile.close();
            system("cls");
            cout << "Words saved to the file: " << outputFileName << "." << endl << endl;
        }
    }

    void encodeFile() const
    {
        if (!isFileLoaded)
        {
            system("cls");
            cerr << "You must load a file first!" << endl << endl;
            return;
        }

        string outputFileName;
        cout << "Enter the output file name for encoded text: ";
        cin >> outputFileName;

        list.encodeFile(loadedFileName, outputFileName);
        system("cls");
        cout << "File encoded and saved to: " << outputFileName << "." << endl << endl;
    }

    void visualizeWordList() const
    {
        if (!isFileLoaded)
        {
            cerr << "You must load a file first!" << endl;
            return;
        }

		system("cls"); // Clear the console screen

        list.visualize();

        cout << endl << "Visualization complete. Press ENTER to return to the menu!";
        auto a = _getch(); // Wait for user input
        system("cls");
    }

    void searchForWordCode() const
    {
        if (!isFileLoaded)
        {
            system("cls");
            cerr << "You must load a file first!" << endl << endl;
            return;
        }

        string word;
        cout << "Enter the word to search for: ";
        cin >> word;

        int code = list.getWordCode(word);

        system("cls");
        if (code != 0)
            cout << "The code for '" << word << "' is: " << code << endl << endl;
        else
            cout << "Word not found in the list." << endl << endl;
    }

    void clearLoadedData()
    {
        if (!isFileLoaded)
        {
            system("cls");
            cerr << "No data to clear. Please load a file first." << endl << endl;
            return;
        }

        list = List();
        isFileLoaded = false;
        loadedFileName.clear();

        system("cls");
        cout << "Loaded data has been cleared." << endl << endl;
    }

public:
    void run()
    {
        int choice;
        do
        {
            displayMenu();
            cin >> choice;
            if (cin.fail()) // Handle invalid input
            {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                system("cls");
                cerr << "Invalid input. Please enter a number." << endl << endl;
                continue;
            }

            switch (choice)
            {
            case 1: loadWordsFromFile(); break;
            case 2:
                if (isFileLoaded) saveWordsToFile();
                else {
                    system("cls");
                    cerr << "Invalid choice. Please load a file first." << endl << endl;
                }
                break;
            case 3:
                if (isFileLoaded) encodeFile();
                else {
                    system("cls");
                    cerr << "Invalid choice. Please load a file first." << endl << endl;
                }
                break;
            case 4:
                if (isFileLoaded) visualizeWordList();
                else {
                    system("cls");
                    cerr << "Invalid choice. Please load a file first." << endl << endl;
                }
                break;
            case 5:
                if (isFileLoaded) searchForWordCode();
                else {
                    system("cls");
                    cerr << "Invalid choice. Please load a file first." << endl << endl;
                }
                break;
            case 6:
                if (isFileLoaded) clearLoadedData();
                else {
                    system("cls");
                    cerr << "Invalid choice. Please load a file first." << endl << endl;
                }
                break;
            case 7:
                cout << "Exiting the program." << endl << endl;
                break;
            default:
                system("cls");
                cerr << "Invalid choice. Please try again." << endl << endl;
                break;
            }
        } while (choice != 7);
    }
};
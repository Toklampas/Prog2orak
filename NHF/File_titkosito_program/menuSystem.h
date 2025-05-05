#pragma once
#include "list.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

class MenuSystem {
private:
    List list;
    bool isFileLoaded = false; // Flag to track if a file has been loaded
    std::string loadedFileName; // Stores the name of the loaded file

    void displayMenu() const {
        std::cout << "\n=====================================\n";
        if (isFileLoaded) {
            std::cout << "Current Loaded File: " << loadedFileName << "\n";
        }
        else {
            std::cout << "No file loaded yet.\n";
        }
        std::cout << "=====================================\n";
        std::cout << "Menu Options:\n";
        std::cout << "1. Load Words from File\n";
        if (isFileLoaded) {
            std::cout << "2. Save Words to File\n";
            std::cout << "3. Encode a File\n";
            std::cout << "4. Visualize Word List\n";
            std::cout << "5. Search for Word Code\n";
        }
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
    }

    void loadWordsFromFile() {
        std::string inputFileName;
        std::cout << "Enter the input file name: ";
        std::cin >> inputFileName;

        std::ifstream inputFile(inputFileName);
        if (!inputFile) {
            std::cerr << "Failed to open input file!\n";
        }
        else {
            inputFile >> list;
            inputFile.close();
            isFileLoaded = true;
            loadedFileName = inputFileName; // Store the loaded file name
            std::cout << "Words loaded into the list from " << loadedFileName << ".\n";
        }
    }

    void saveWordsToFile() const {
        if (!isFileLoaded) {
            std::cerr << "You must load a file first!\n";
            return;
        }

        std::string outputFileName;
        std::cout << "Enter the output file name: ";
        std::cin >> outputFileName;

        std::ofstream outputFile(outputFileName);
        if (!outputFile) {
            std::cerr << "Failed to open output file!\n";
        }
        else {
            outputFile << list;
            outputFile.close();
            std::cout << "Words saved to the file: " << outputFileName << ".\n";
        }
    }

    void encodeFile() const {
        if (!isFileLoaded) {
            std::cerr << "You must load a file first!\n";
            return;
        }

        std::string inputFileName, outputFileName;
        std::cout << "Enter the input file name to encode: ";
        std::cin >> inputFileName;
        std::cout << "Enter the output file name for encoded text: ";
        std::cin >> outputFileName;

        list.encodeFile(inputFileName, outputFileName);
        std::cout << "File encoded and saved to: " << outputFileName << ".\n";
    }

    void visualizeWordList() const {
        if (!isFileLoaded) {
            std::cerr << "You must load a file first!\n";
            return;
        }

        list.visualize();
    }

    void searchForWordCode() const {
        if (!isFileLoaded) {
            std::cerr << "You must load a file first!\n";
            return;
        }

        std::string word;
        std::cout << "Enter the word to search for: ";
        std::cin >> word;

        int code = list.getWordCode(word);
        if (code != 0) {
            std::cout << "The code for '" << word << "' is: " << code << '\n';
        }
        else {
            std::cout << "Word not found in the list.\n";
        }
    }

public:
    void run() {
        int choice;
        do {
            displayMenu();
            std::cin >> choice;

            switch (choice) {
            case 1: loadWordsFromFile(); break;
            case 2:
                if (isFileLoaded) saveWordsToFile();
                else std::cerr << "Invalid choice. Please load a file first.\n";
                break;
            case 3:
                if (isFileLoaded) encodeFile();
                else std::cerr << "Invalid choice. Please load a file first.\n";
                break;
            case 4:
                if (isFileLoaded) visualizeWordList();
                else std::cerr << "Invalid choice. Please load a file first.\n";
                break;
            case 5:
                if (isFileLoaded) searchForWordCode();
                else std::cerr << "Invalid choice. Please load a file first.\n";
                break;
            case 6: std::cout << "Exiting the program. Goodbye!\n"; break;
            default: std::cerr << "Invalid choice. Please try again.\n"; break;
            }
        } while (choice != 6);
    }
};



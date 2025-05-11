#include "fileManager.h"
#include <fstream>
#include <iostream>

bool FileManager::loadWords(const string& fileName, List& list) {
    ifstream inputFile(fileName);
    if (!inputFile) {
        system("cls");
        cerr << "Failed to open input file!" << endl << endl;
        return false;
    }
    inputFile >> list;
    inputFile.close();
    return true;
}

bool FileManager::saveWords(const string& fileName, const List& list) {
    ofstream outputFile(fileName);
    if (!outputFile) {
        system("cls");
        cerr << "Failed to open output file!" << endl << endl;
        return false;
    }
    outputFile << list;
    outputFile.close();
    return true;
}

bool FileManager::encodeFile(const string& inputFileName, const string& outputFileName, const List& list) {
    ifstream inputFile(inputFileName);
    if (!inputFile)
    {
        system("cls");
        cerr << "Failed to open input file: " << inputFileName << endl << endl;
        return false;
    }
    ofstream outputFile(outputFileName);
    if (!outputFile)
    {
        system("cls");
        cerr << "Failed to open output file: " << outputFileName << endl << endl;
        return false;
    }
    list.encodeFile(inputFileName, outputFileName);
    return true;
}
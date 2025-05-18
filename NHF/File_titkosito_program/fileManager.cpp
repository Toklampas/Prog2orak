#include "fileManager.h"
#include <fstream>
#include <iostream>

#include "memtrace.h"

bool FileManager::loadWords(const string& fileName, List& list) {
    ifstream inputFile(fileName);
    if (!inputFile)
        throw std::runtime_error("Failed to open input file: " + fileName);
    inputFile >> list;
    inputFile.close();
    return true;
}

bool FileManager::saveWords(const string& fileName, const List& list) {
    ofstream outputFile(fileName);
    if (!outputFile)
        throw std::runtime_error("Failed to open output file: " + fileName);
    outputFile << list;
    outputFile.close();
    return true;
}

bool FileManager::encodeFile(const string& inputFileName, const string& outputFileName, const List& list) {
    ifstream inputFile(inputFileName);
    if (!inputFile)
        throw std::runtime_error("Failed to open input file: " + inputFileName);
    ofstream outputFile(outputFileName);
    if (!outputFile)
        throw std::runtime_error("Failed to open output file: " + outputFileName);
    list.encodeFile(inputFileName, outputFileName);
    return true;
}
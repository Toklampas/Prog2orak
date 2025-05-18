#pragma once
#include "list.h"
#include <string>

#include "memtrace.h"

using namespace std;

class FileManager {
public:
    static bool loadWords(const string& fileName, List& list);
    static bool saveWords(const string& fileName, const List& list);
    static bool encodeFile(const string& inputFileName, const string& outputFileName, const List& list);
};
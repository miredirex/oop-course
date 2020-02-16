#include "replacer.h"
#include <iostream>

using namespace std;

Replacer::Replacer(const char *filename) {
    inputFile = ifstream(filename);
    if (!inputFile.is_open()) {
        printf("Input file not found\n");
        exit(NOT_FOUND_ERROR_CODE);
    }
}

bool Replacer::ParseLine(string& outputLine) {
    string exportString;
    getline(inputFile, exportString);
    if (exportString.empty() || exportString == "\n") {
        return false;
    } else {
        outputLine = exportString;
    }
    return true;
}

std::string Replacer::ReplaceAllOccurrences(string target, const char* searchString, const char* replaceString) {
    char similar[] = "";

    for (const char c : target) {
        //todo: finish here
    }
}

void Replacer::AppendResult(const char* outputFilename, std::string line) {
    if (!outputFile.is_open()) {
        outputFile = ofstream(outputFilename);
    }
    outputFile << line;
}

Replacer::~Replacer() {
    inputFile.close();
    outputFile.close();
}
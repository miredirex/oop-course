#include "replacer.h"
#include <iostream>
#include <cstring>

using namespace std;

Replacer::Replacer(const char *filename) {
    inputFile = ifstream(filename);
    if (!inputFile.is_open()) {
        printf("Input file not found\n");
        exit(NOT_FOUND_ERROR_CODE);
    }
}

bool Replacer::ParseLine(string &outputLine) {
    string exportString;
    getline(inputFile, exportString);
    if (exportString.empty() || exportString == "\n") {
        return false;
    } else {
        outputLine = exportString;
    }
    return true;
}

std::string Replacer::ReplaceAllOccurrences(const string &target, const char *searchString, const char *replaceString) {
    if (searchString[0] == '\0') return target;

    string result;
    unsigned int cursorPosition = 0;

    while (cursorPosition <= target.length()) {
        if (target[cursorPosition] == searchString[0]) {
            if (IsFullWordMet(target, searchString, cursorPosition)) {
                result += replaceString;
                // Jump ahead of the word after replacement
                cursorPosition += strlen(searchString);
            }
        }
        result += target[cursorPosition];
        cursorPosition++;
    }

    return result;
}

bool Replacer::IsFullWordMet(const std::string &target, const char *searchString, unsigned int pos) {
    for (unsigned int i = 0; i < strlen(searchString); i++) {
        auto scanPosition = pos + i;
        if (target[scanPosition] != searchString[i]) {
            return false;
        }
    }
    return true;
}

void Replacer::AppendResult(const char *outputFilename, const std::string &line) {
    if (!outputFile.is_open()) {
        outputFile = ofstream(outputFilename);
    }
    outputFile << line;
}

Replacer::~Replacer() {
    inputFile.close();
    outputFile.close();
}
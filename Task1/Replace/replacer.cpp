#include "replacer.h"
#include <iostream>
#include <cstring>

Replacer::Replacer(const char *filename) {
    inputFile = std::ifstream(filename);

    if (!inputFile.is_open()) {
        printf("Input file not found\n");
        exit(NOT_FOUND_ERROR_CODE);
    }
}

bool Replacer::ParseLine(std::string &outputLine) {
    std::string exportString;

    if (!getline(inputFile, exportString)) {
        return false;
    } else {
        outputLine = exportString;
    }

    return true;
}

std::string Replacer::ReplaceAllOccurrences(const std::string &target, const char *searchString, const char *replaceString) {
    if (searchString[0] == '\0') return target;

    std::string result;
    unsigned int cursorPosition = 0;

    while (cursorPosition <= target.length()) {
        if (target[cursorPosition] == searchString[0]) {
            if (HasFullWordMet(target, searchString, cursorPosition)) {
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

bool Replacer::HasFullWordMet(const std::string &target, const char *searchString, unsigned int cursorPosition) {
    for (unsigned int i = 0; i < strlen(searchString); i++) {
        auto scanPosition = cursorPosition + i;
        if (target[scanPosition] != searchString[i]) {
            return false;
        }
    }
    return true;
}

void Replacer::AppendResult(const char *outputFilename, const std::string &line) {
    if (!outputFile.is_open()) {
        outputFile = std::ofstream(outputFilename);
    }
    outputFile << line;
}

Replacer::~Replacer() {
    // End I/O work
    if (inputFile.bad()) {
        printf("Error: can not read from input file\n");
        exit(IO_ERROR_CODE);
    }
    inputFile.close();
    if(!outputFile.flush()) {
        printf("Error: can not write to output file\n");
        exit(IO_ERROR_CODE);
    }
    outputFile.close();
}
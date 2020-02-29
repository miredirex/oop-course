#include <iostream>
#include "replacer.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: replace.exe <input file> <output file> <search string> <replace string>\n");
        return 1;
    }
    const char *inputFile = argv[1];
    const char *outputFile = argv[2];

    const char *searchString = argv[3];
    const char *replaceString = argv[4];

    Replacer replacer(inputFile);
    string newLine;

    while (replacer.ParseLine(newLine)) {
        string modified = replacer.ReplaceAllOccurrences(newLine, searchString, replaceString);
        replacer.AppendResult(outputFile, modified);
    }
    return 0;
}

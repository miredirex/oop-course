#ifndef REPLACER_H
#define REPLACER_H

#include <string>
#include <fstream>

class Replacer {
private:
    const int NOT_FOUND_ERROR_CODE = 404;

    std::ifstream inputFile;
    std::ofstream outputFile;
public:
    Replacer(const char* filename);
    ~Replacer();
    bool ParseLine(std::string& outputLine);
    std::string ReplaceAllOccurrences(std::string target, const char* searchString, const char* replaceString);
    void AppendResult(const char* outputFilename, std::string line);
};
#endif //REPLACER_H
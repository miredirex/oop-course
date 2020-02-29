#ifndef REPLACER_H
#define REPLACER_H

#include <string>
#include <fstream>

class Replacer {
private:
    const int NOT_FOUND_ERROR_CODE = 404;
    const int IO_ERROR_CODE = 2;

    std::ifstream inputFile;
    std::ofstream outputFile;

    static bool HasFullWordMet(const std::string &target, const char *searchString, unsigned int cursorPosition);

public:
    Replacer(const char *filename);

    ~Replacer();

    bool ParseLine(std::string &outputLine);

    static std::string ReplaceAllOccurrences(const std::string &target, const char *searchString, const char *replaceString);

    void AppendResult(const char *outputFilename, const std::string &line);
};

#endif //REPLACER_H
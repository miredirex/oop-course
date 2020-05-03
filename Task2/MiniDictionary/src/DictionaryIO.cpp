#include <dictionary/DictionaryIO.h>

bool DeserializeDictionaryFromFile(const char* filename, Dictionary& dict)
{
    std::ifstream inputFile(filename);
    if (inputFile.is_open() && !inputFile.bad())
    {
        dict.Deserialize(inputFile, true);
        inputFile.close();
        return true;
    }
    return false;
}

bool SerializeDictionaryToFile(const char* filename, const Dictionary& dict)
{
    std::ofstream outputFile(filename);
    bool isOutputSuccessful = true;
    if (outputFile.is_open() && !outputFile.bad())
    {
        dict.Serialize(outputFile);
    }
    if (!outputFile.flush())
    {
        isOutputSuccessful = false;
    }
    outputFile.close();
    return isOutputSuccessful;
}
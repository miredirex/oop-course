#pragma once

#include "Dictionary.h"

bool DeserializeDictionaryFromFile(const char* filename, Dictionary& dict);

bool SerializeDictionaryToFile(const char* filename, const Dictionary& dict);

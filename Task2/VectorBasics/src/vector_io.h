#ifndef VECTOR_IO_H
#define VECTOR_IO_H

#include <istream>
#include <vector>
#include <sstream>
#include <iterator>
#include <iostream>
#include <iomanip>

void SeparatedValuesToVector(const std::string& line, std::vector<double>& vec);

void PrintVector(const std::vector<double>& vec, std::ostream& outStream, const char* delimiter = " ");

#endif //VECTOR_IO_H

#include "read/fileReader.hpp"

#include <string>
#include <fstream>

using namespace read;

FileReader::FileReader() {}

FileReader::~FileReader() {}

std::string* FileReader::readFile(std::string filePath, int numberOfLinesToRead) {
    std::string* fileLines = new std::string[numberOfLinesToRead];

    std::ifstream file;
    file.open(filePath);
    std::string line;

    int counter = 0;

    if (file.is_open()) {
        while (counter < numberOfLinesToRead && getline(file, line)) {
            fileLines[counter] = line;
            counter++;
        }
        file.close();
    }

    return fileLines;
}

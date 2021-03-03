#include "read/converter.hpp"
#include <string>
#include <sstream>

using namespace read;

Converter::Converter(std::string* fileLines, int numberOfLinesToRead) {
    this->fileLines = fileLines;
    this->numberOfLinesToRead = numberOfLinesToRead;
}

Converter::~Converter() {
    delete this->fileLines;
    this->numberOfLinesToRead = 0;
}

returnToEarth::Base* Converter::convertLineToPlanet(std::string line) {
    std::istringstream lineOfFile(line);
    std::string value;

    returnToEarth::Base* newPlanet = new returnToEarth::Base();

    int counter = 0;

    while (getline(lineOfFile, value, ' ')) {
        if (value.empty()) {
            break;
        }

        if (counter == 0) {
            newPlanet->setName(value);
        } else {
            newPlanet->setDistanceFromEarth(std::stoi(value));
        }

        counter++;
    }

    return newPlanet;
}

returnToEarth::Base* Converter::convertFileLinesToListOfPlanets() {
    returnToEarth::Base* list = new returnToEarth::Base[this->numberOfLinesToRead];

    for (int i = 0; i < this->numberOfLinesToRead; i++) {
        returnToEarth::Base* newPlanet = this->convertLineToPlanet(this->fileLines[i]);
        list[i] = *newPlanet;
    }

    return list;
}

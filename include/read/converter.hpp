#ifndef CONVERTER
#define CONVERTER

#include <string>
#include "return-to-earth/listOfPlanets.hpp"

namespace read {
    class Converter {
        private:
            std::string* fileLines;
            int numberOfLinesToRead;

            returnToEarth::Planet* convertLineToPlanet(std::string line);
        
        public:
            Converter(std::string* fileLines, int numberOfLinesToRead);
            ~Converter();

            returnToEarth::Planet* convertFileLinesToListOfPlanets();
    };
}

#endif

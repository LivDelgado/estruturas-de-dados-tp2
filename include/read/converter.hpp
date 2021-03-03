#ifndef CONVERTER
#define CONVERTER

#include <string>
#include "return-to-earth/base.hpp"

namespace read {
    class Converter {
        private:
            std::string* fileLines;
            int numberOfLinesToRead;

            returnToEarth::Base* convertLineToPlanet(std::string line);
        
        public:
            Converter(std::string* fileLines, int numberOfLinesToRead);
            ~Converter();

            returnToEarth::Base* convertFileLinesToListOfPlanets();
    };
}

#endif

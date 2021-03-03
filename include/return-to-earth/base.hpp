#include <string>

#ifndef PLANET
#define PLANET

namespace returnToEarth {
    class Base {
        private:
            std::string name;
            int distanceFromEarth;
        public:
            Base(std::string name, int distanceFromEarth);
            Base();
            ~Base();

            void setName(std::string name);
            void setDistanceFromEarth(int distanceFromEarth);

            std::string getName();
            int getDistanceFromEarth();
    };
}

#endif

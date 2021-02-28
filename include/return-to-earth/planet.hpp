#include <string>

#ifndef PLANET
#define PLANET

namespace returnToEarth {
    class Planet {
        private:
            std::string name;
            int distanceFromEarth;
        public:
            Planet(std::string name, int distanceFromEarth);
            Planet();
            ~Planet();

            void setName(std::string name);
            void setDistanceFromEarth(int distanceFromEarth);

            std::string getName();
            int getDistanceFromEarth();
    };
}

#endif

#ifndef LIST_OF_PLANETS
#define LIST_OF_PLANETS

#include "return-to-earth/planetNode.hpp"

namespace returnToEarth {
    class ListOfPlanets {
        private:
            PlanetNode* firstPlanet;
            PlanetNode* lastPlanet;
            int size;

            void clearList();

            void validatePositionTooSmall(int position);
            void validatePositionGreaterThanSize(int position);
            void validatePosition(int position);
            void validateEmptyList();

            void incrementSize();
            void decrementSize();
        public:
            ListOfPlanets();
            ~ListOfPlanets();

            int length();

            PlanetNode* getNodeAtPosition(int position);
            
            void addPlanet(Planet* planet, int position);
            void addPlanetAtTheBeginning(Planet* planet);
            void addPlanetAtTheEnd(Planet* planet);

            Planet* removePlanet(int position);
            Planet* removeFirstPlanet();
            Planet* removeLastPlanet();
            
            Planet* getFirstPlanet();
            Planet* getLastPlanet();
            Planet* getPlanet(int position);
    };
}

#endif

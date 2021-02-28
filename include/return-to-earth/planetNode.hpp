#ifndef PLANET_NODE
#define PLANET_NODE

#include "return-to-earth/planet.hpp"

namespace returnToEarth {
    class PlanetNode {
        private:
            PlanetNode* nextPlanetNode;
            PlanetNode* previousPlanetNode;

            Planet* planet;

        public:
            PlanetNode();
            PlanetNode(Planet* planet);
            ~PlanetNode();

            void setNextPlanetNode(PlanetNode* nextPlanetNode);
            void setPreviousPlanetNode(PlanetNode* previousPlanetNode);
            void setPlanet(Planet* planet);
            
            PlanetNode* getNextPlanetNode();
            PlanetNode* getPreviousPlanetNode();
            Planet* getPlanet();

    };
}

#endif
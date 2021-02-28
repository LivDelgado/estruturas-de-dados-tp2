#include "return-to-earth/planetNode.hpp"
#include "return-to-earth/planet.hpp"

using namespace returnToEarth;


PlanetNode::PlanetNode() {
    this->planet = nullptr;
    this->nextPlanetNode = nullptr;
    this->previousPlanetNode = nullptr;
}

PlanetNode::PlanetNode(Planet* planet) {
    this->planet = planet;
    this->nextPlanetNode = nullptr;
    this->previousPlanetNode = nullptr;
}

PlanetNode::~PlanetNode() {
    delete this->planet;
    delete this->previousPlanetNode;
    delete this->nextPlanetNode;
}

void PlanetNode::setNextPlanetNode(PlanetNode* nextPlanetNode) {
    this->nextPlanetNode = nextPlanetNode;
}

void PlanetNode::setPreviousPlanetNode(PlanetNode* previousPlanetNode) {
    this->previousPlanetNode = previousPlanetNode;
}

void PlanetNode::setPlanet(Planet* planet) {
    this->planet = planet;
}

PlanetNode* PlanetNode::getNextPlanetNode() {
    return this->nextPlanetNode;
}

PlanetNode* PlanetNode::getPreviousPlanetNode() {
    return this->previousPlanetNode;
}

Planet* PlanetNode::getPlanet() {
    return this->planet;
}

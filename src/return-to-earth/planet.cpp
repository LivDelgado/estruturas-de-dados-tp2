#include "return-to-earth/planet.hpp"
#include <string>

using namespace returnToEarth;

Planet::Planet(std::string name, int distanceFromEarth) {
    this->name = name;
    this-> distanceFromEarth = distanceFromEarth;
}

Planet::Planet() : Planet("", 0) {}

Planet::~Planet() {}

void Planet::setName(std::string name) {
    this->name = name;
}

void Planet::setDistanceFromEarth(int distanceFromEarth) {
    this->distanceFromEarth = distanceFromEarth;
}

std::string Planet::getName() {
    return this->name;
}

int Planet::getDistanceFromEarth() {
    return this->distanceFromEarth;
}

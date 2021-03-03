#include "return-to-earth/base.hpp"
#include <string>

using namespace returnToEarth;

Base::Base(std::string name, int distanceFromEarth) {
    this->name = name;
    this-> distanceFromEarth = distanceFromEarth;
}

Base::Base() : Base("", 0) {}

Base::~Base() {}

void Base::setName(std::string name) {
    this->name = name;
}

void Base::setDistanceFromEarth(int distanceFromEarth) {
    this->distanceFromEarth = distanceFromEarth;
}

std::string Base::getName() {
    return this->name;
}

int Base::getDistanceFromEarth() {
    return this->distanceFromEarth;
}

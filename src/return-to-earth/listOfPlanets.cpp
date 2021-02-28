#include "return-to-earth/listOfPlanets.hpp"

using namespace returnToEarth;

ListOfPlanets::ListOfPlanets() {
    this->firstPlanet = nullptr;
    this->lastPlanet = nullptr;
    this->size = 0;
}

ListOfPlanets::~ListOfPlanets() {
    this->clearList();
    delete this->firstPlanet;
    delete this->lastPlanet;
}

void ListOfPlanets::clearList() {
    while (this->size > 0) {
        this->removeLastPlanet();
    }
}

PlanetNode* ListOfPlanets::getNodeAtPosition(int position) {
    int counter = 1;
    PlanetNode* currentPlanet = this->firstPlanet;

    while (counter < position) {
        currentPlanet = currentPlanet->getNextPlanetNode();
        counter++;
    }

    return currentPlanet;
}

void ListOfPlanets::validatePositionTooSmall(int position) {
    if (position < 1) {
        throw "Posição inválida: deve ser maior que 1";
    }
}

void ListOfPlanets::validatePositionGreaterThanSize(int position) {
    if (position > this->size) {
        throw "Posição inválida: deve ser menor que o tamanho atual da lista";
    }
}

void ListOfPlanets::validatePosition(int position) {
    this->validatePositionTooSmall(position);
    this->validatePositionGreaterThanSize(position);
}

void ListOfPlanets::validateEmptyList() {
    if (this->size == 0) {
        throw "Lista vazia!";
    }
}

void ListOfPlanets::incrementSize() {
    this->size++;
}

void ListOfPlanets::decrementSize() {
    this->size--;
}

int ListOfPlanets::length() {
    return this->size;
}

void ListOfPlanets::addPlanet(Planet* planet, int position) {
    this->validatePosition(position);

    if (position == 1) {
        this->addPlanetAtTheBeginning(planet);
    } else {
        PlanetNode* newPlanet = new PlanetNode(planet);

        PlanetNode* currentPlanetAtPosition = getNodeAtPosition(position);
        PlanetNode* previousNode = currentPlanetAtPosition->getPreviousPlanetNode();

        previousNode->setNextPlanetNode(newPlanet);
        newPlanet->setPreviousPlanetNode(previousNode);

        currentPlanetAtPosition->setPreviousPlanetNode(newPlanet);
        newPlanet->setNextPlanetNode(currentPlanetAtPosition);

        this->incrementSize();
    }
}

void ListOfPlanets::addPlanetAtTheBeginning(Planet* planet) {
    PlanetNode* newPlanet = new PlanetNode(planet);
    this->firstPlanet = newPlanet;
    this->lastPlanet = newPlanet;
    this->incrementSize();
}

void ListOfPlanets::addPlanetAtTheEnd(Planet* planet) {
    PlanetNode* newPlanet = new PlanetNode(planet);
    PlanetNode* currentLastPlanet = this->lastPlanet;

    this->lastPlanet = newPlanet;
    currentLastPlanet->setNextPlanetNode(newPlanet);
    newPlanet->setPreviousPlanetNode(currentLastPlanet);

    this->incrementSize();
}

Planet* ListOfPlanets::removePlanet(int position) {
    this->validatePosition(position);

    if (position == 1) {
        return this->removeFirstPlanet();
    } else if (position == this->size) {
        return this->removeLastPlanet();
    } else {
        PlanetNode* planetToRemove = this->getNodeAtPosition(position);

        PlanetNode* nextPlanet = planetToRemove->getNextPlanetNode();
        PlanetNode* previousPlanet = planetToRemove->getPreviousPlanetNode();

        previousPlanet->setNextPlanetNode(nextPlanet);
        nextPlanet->setPreviousPlanetNode(previousPlanet);
        Planet* planet = planetToRemove->getPlanet();
        
        delete planetToRemove;
        this->decrementSize();

        return planet;
    }
}

Planet* ListOfPlanets::removeFirstPlanet() {
    PlanetNode* planetToRemove = this->firstPlanet;
    this->firstPlanet = planetToRemove->getNextPlanetNode();
    this->firstPlanet->setPreviousPlanetNode(nullptr);

    Planet* planet = planetToRemove->getPlanet();

    delete planetToRemove;
    this->decrementSize();

    return planet;
}

Planet* ListOfPlanets::removeLastPlanet() {
    PlanetNode* planetToRemove = this->lastPlanet;
    this->lastPlanet = planetToRemove->getPreviousPlanetNode();
    this->lastPlanet->setNextPlanetNode(nullptr);

    Planet* planet = planetToRemove->getPlanet();

    delete planetToRemove;
    this->decrementSize();

    return planet;
}

Planet* ListOfPlanets::getFirstPlanet() {
    this->validateEmptyList();
    return this->firstPlanet->getPlanet();
}

Planet* ListOfPlanets::getLastPlanet() {
    this->validateEmptyList();
    return this->lastPlanet->getPlanet();
}

Planet* ListOfPlanets::getPlanet(int position) {
    this->validateEmptyList();
    this->validatePosition(position);
    return this->getNodeAtPosition(position)->getPlanet();
}
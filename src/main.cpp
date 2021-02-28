#include <cstdlib>
#include <iostream>

#include "return-to-earth/listOfPlanets.hpp"
#include "return-to-earth/planet.hpp"

int main(int argc, char* argv[]) {
    std::system("clear");

    if (argc < 3) {
        std::cout << "Número de parâmetros insuficiente!" << std::endl;
        std::cout << "Devem ser informados o caminho do arquivo com os dados de distância e o número de linhas a ler." << std::endl;
        return 1;
    }

    std::string caminhoArquivoMapa = argv[1];
    std::string caminhoArquivoComandos = argv[2];

    try {
        returnToEarth::Planet* planet1 = new returnToEarth::Planet("a", 1);
        returnToEarth::Planet* planet2 = new returnToEarth::Planet("b", 2);
        returnToEarth::Planet* planet3 = new returnToEarth::Planet("c", 3);
        returnToEarth::ListOfPlanets* list = new returnToEarth::ListOfPlanets();
        list->addPlanetAtTheBeginning(planet1);
        list->addPlanetAtTheEnd(planet3);
        list->addPlanet(planet2, 2);

        returnToEarth::Planet* current = list->getPlanet(3);
        std::cout << current->getName() << std::endl;

        // returnToEarth::Planet* current = list->getPlanet(1);
        // std::cout << current->getName() << std::endl;

        // current = list->getPlanet(2);
        // std::cout << current->getName() << std::endl;

        // current = list->getPlanet(3);
        // std::cout << current->getName() << std::endl;
    } catch (char const* excecao){
        std::cout << excecao << std::endl;
        return 0;
    }
}
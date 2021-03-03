#include <cstdlib>
#include <iostream>

#include "read/fileReader.hpp"
#include "read/converter.hpp"
#include "sort/performanceMeasure.hpp"
#include "sort/quickSortOptimized.hpp"

#define NUMBER_OF_LINES_TO_PRINT 7
#define MAXIMUM 200000

int main(int argc, char* argv[]) {
    std::system("clear");

    if (argc < 3) {
        std::cout << "Número de parâmetros insuficiente!" << std::endl;
        std::cout << "Devem ser informados o caminho do arquivo com os dados de distância e o número de linhas a ler." << std::endl;
        return 1;
    }

    std::string filePath = argv[1];
    int numberOfLinesToRead = std::stoi(argv[2]);

    try {
        read::FileReader* fileReader = new read::FileReader();

        if (argc == 4 && std::stoi(argv[3]) == 1) {
            std::string* linesOfFile = fileReader->readFile(filePath, MAXIMUM);
            read::Converter* converter = new read::Converter(linesOfFile, MAXIMUM);
            returnToEarth::Base* list = converter->convertFileLinesToListOfPlanets();

            sort::PerformanceMeasure* performanceMeasure = new sort::PerformanceMeasure();
            performanceMeasure->measurePerformanceForAllCases(list);
        } else {
            std::string* linesOfFile = fileReader->readFile(filePath, numberOfLinesToRead);

            read::Converter* converter = new read::Converter(linesOfFile, numberOfLinesToRead);
            returnToEarth::Base* list = converter->convertFileLinesToListOfPlanets();

            sort::CombSort* sorter = new sort::CombSort();
            returnToEarth::Base* ordered = sorter->sort(list, numberOfLinesToRead);

            for (int i = 0; i < NUMBER_OF_LINES_TO_PRINT; i++) {
                std::cout << (&ordered[i])->getName() << " " << (&ordered[i])->getDistanceFromEarth() << std::endl;
            }
        }
    } catch (char const* excecao){
        std::cout << excecao << std::endl;
        return 0;
    }
}
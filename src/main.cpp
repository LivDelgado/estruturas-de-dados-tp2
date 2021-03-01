#include <cstdlib>
#include <iostream>

#include "read/fileReader.hpp"
#include "read/converter.hpp"
#include "sort/insertionSort.hpp"
#include "sort/mergeSort.hpp"
#include "sort/quickSortOptimized.hpp"
#include "sort/quickSort.hpp"
#include "sort/combSort.hpp"

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
        std::string* linesOfFile = fileReader->readFile(filePath, numberOfLinesToRead);

        read::Converter* converter = new read::Converter(linesOfFile, numberOfLinesToRead);
        returnToEarth::Planet* list = converter->convertFileLinesToListOfPlanets();

        sort::CombSort* sorter = new sort::CombSort();
        returnToEarth::Planet* ordered = sorter->sort(list, numberOfLinesToRead);

        for (int i = 0; i < numberOfLinesToRead; i++) {
            std::cout << (&ordered[i])->getName() << ", " << (&ordered[i])->getDistanceFromEarth() << std::endl;
        }

    } catch (char const* excecao){
        std::cout << excecao << std::endl;
        return 0;
    }
}
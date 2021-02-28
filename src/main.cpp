#include <cstdlib>
#include <iostream>

#include "read/fileReader.hpp"
#include "read/converter.hpp"
#include "sort/mergeSort.hpp"

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

        sort::MergeSort* sorter = new sort::MergeSort();
        returnToEarth::Planet* ordered = sorter->sort(list, numberOfLinesToRead);

        std::cout << (&ordered[0])->getName() << std::endl;
        std::cout << (&ordered[1])->getName() << std::endl;
        std::cout << (&ordered[2])->getName() << std::endl;
        std::cout << (&ordered[3])->getName() << std::endl;
        std::cout << (&ordered[4])->getName() << std::endl;
    } catch (char const* excecao){
        std::cout << excecao << std::endl;
        return 0;
    }
}
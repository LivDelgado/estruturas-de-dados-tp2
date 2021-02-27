#include <cstdlib>
#include <iostream>


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
        std::cout << "Hello World" << std::endl;
    } catch (char const* excecao){
        std::cout << excecao << std::endl;
        return 0;
    }
}
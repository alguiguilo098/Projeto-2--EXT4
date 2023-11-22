#include <iostream>
#include <fstream>
#include "ext_4 _estrutura.hpp"
using namespace std;
void prints::print_super_block(super_block_t* block){
    
}
int main()
{
    // Cria um objeto ifstream
    std::ifstream inputFile;

    // Abre um arquivo para leitura binária
    inputFile.open("images_ext4/myext4image1k.img", std::ios::binary);
    inputFile.seekg(1024);
    // Verifica se o arquivo foi aberto com sucesso
    if (!inputFile.is_open())
    {
        std::cerr << "Não foi possível abrir o arquivo." << std::endl;
        return 1; // Retorna um código de erro
    }

    // Determina o tamanho do buffer de leitura
    const int bufferSize = 1024;
    char buffer[bufferSize];

    // Lê dados do arquivo
    inputFile.read(buffer, bufferSize);

    // Obtém o número de bytes lidos
    std::streamsize bytesRead = inputFile.gcount();

    // Verifica se a leitura foi bem-sucedida
    if (bytesRead > 0)
    {
        std::cout << "Bytes lidos: " << bytesRead << std::endl;
        std::cout.write(buffer,bufferSize);
    }
    else
    {
        std::cout << "Nenhum dado foi lido." << std::endl;
    }

    // Fecha o arquivo
    inputFile.close();

    return 0;
}
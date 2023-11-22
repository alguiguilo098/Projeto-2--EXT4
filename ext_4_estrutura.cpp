#include <iostream>
#include <fstream>
#include "ext4_estrutura.hpp"
using namespace std;
void prints::print_super_block(super_block_t* block){
    cout <<"Total inode count:"<<block->s_inodes_count<<endl;
    cout <<"Total block count."<<block->s_blocks_count_lo<<endl;
    cout <<"This number of blocks can only be allocated by the super-user."<<block->s_r_blocks_count_lo<<endl;
    cout << "Free block count: "<<block->s_free_inodes_count<<endl;
    cout <<"First data block. This must be at least 1 for 1k-block filesystems and is typically 0 for all other block sizes."<<block->s_first_data_block<<endl;
    cout << "Block size is 2 ^ (10 + s_log_block_size)."<<block->s_log_block_size<<endl;
    cout <<"Cluster size is (2 ^ s_log_cluster_size) blocks if bigalloc is enabled. Otherwise s_log_cluster_size must equal s_log_block_size."<<block->s_log_cluster_size<<endl;
    cout <<"Blocks per group."<<block->s_blocks_per_group<<endl;
    cout <<"Clusters per group, if bigalloc is enabled. Otherwise s_clusters_per_group must equal s_blocks_per_group"<<block->s_clusters_per_group<<endl;
    cout <<"Inodes per group."<< block->s_inodes_per_group<<endl;
    cout <<"Mount time, in seconds since the epoch."<<block->s_mtime<<endl;
    cout <<"Write time, in seconds since the epoch."<<block->s_wtime<<endl;
    cout << "Number of mounts since the last fsck. "<<block->s_mnt_count<<endl;
    cout << "Number of mounts beyond which a fsck is needed."<<block->s_max_mnt_count<<endl;
    cout << "Magic signature, 0xEF53"<<block->s_magic<<endl;
    cout <<"File system state. Valid values are: 0x0001 Cleanly umounted ,0x0002 	Errors detected, 0x0004 Orphans being recovered "<<block->s_state<<endl;
    cout << "Behaviour when detecting errors. One of: 1 Continue,2 	Remount read-only 3 	Panic "

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
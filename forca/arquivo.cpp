using namespace std;
#include <iostream>
#include <fstream>
#include <ctime>
#include "arquivo.hpp"

extern std::string palavra_secreta;

vector<string> le_arquivo(){
    
    std::ifstream arquivo;
    arquivo.open("palavras.txt");

    if(arquivo.is_open()){

        int quantidade_palavras;
        arquivo >> quantidade_palavras;
        std::vector<std::string> palavras_do_arquivo;

        for(int i =0;i<quantidade_palavras;i++){
            std::string palavra_lida;
            arquivo >> palavra_lida;
            palavras_do_arquivo.push_back(palavra_lida);
        }
        arquivo.close();
        return palavras_do_arquivo;
    
    }
    else{
        std::cout<<"Banco de dados não encontrado, o Jogo será fechado :( "<<std::endl;
        exit(0);
    }

}

void sorteia_palavra(){
    std::vector<std::string> palavras = le_arquivo();

    srand(time(0));
    int indice_sorteado = rand() % palavras.size();
    palavra_secreta = palavras[indice_sorteado];
}

void salva_arquivo(vector<string> lista_palavras){
    
    std::ofstream arquivo;
    arquivo.open("palavras.txt");

    if(arquivo.is_open()){
        
        arquivo<< lista_palavras.size()<<std::endl;
        
        for(string palavra: lista_palavras){
            arquivo << palavra <<std::endl;
        }

        arquivo.close();
    }
    else{
        std::cout<<"Banco de dados não encontrado, o Jogo será fechado :( "<<std::endl;
        exit(0);

    }

}

void adiciona_palavra(){
    std::cout<<"Digite a nova palavra usando letras maíscula: "<<std::endl;
    std::string nova_palavra;
    std::cin>>nova_palavra;

    std::vector<std::string> lista_palavras = le_arquivo();
    lista_palavras.push_back(nova_palavra);
    salva_arquivo(lista_palavras);
}

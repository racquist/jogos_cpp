#include "dificuldade.hpp"

int define_dificuldade(){
    std::cout<<"Escolha seu nível de dificuldade"<<std::endl;
    std::cout<<"Fácil (F) - Médio(M) - Díficil (D): ";

    char dificuldade;
    int numero_de_tentativas;

    std::cin>> dificuldade;

    if(dificuldade == 'F'){
        numero_de_tentativas = 15;
    }
    else if(dificuldade == 'M'){
        numero_de_tentativas = 10;
    }
    else{
        numero_de_tentativas = 5;
    }

    return numero_de_tentativas;
}
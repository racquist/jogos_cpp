#include "compara.hpp"
#include "numero.hpp"
#include "dificuldade.hpp"

bool nao_acertou = true;
int tentativa = 0;
double pontos = 1000.0;

void compara_chute_numero_secreto(){

    int attempt = define_dificuldade();
    int number = define_numero_secreto();

    for(tentativa = 1; tentativa <= attempt; tentativa++){

        int chute;
        std::cout<<"Tentativa: " <<tentativa<< std::endl;
   
        std::cout<< "QUal o valor do seu chute? ";
        std::cin >> chute;
        std::cout << "O valor do seu chute é: " <<chute<< std::endl;

        double pontos_perdidos = abs(chute - number)/2.0;
        pontos = pontos - pontos_perdidos;
    
        bool acertou = chute == number;
        bool maior = chute > number;

        if(acertou){
            std::cout << "Parabéns! Você acertou o Número Secreto!"<<std::endl;
            nao_acertou = false;
            break;
        }
        else if(maior){
            std::cout << "Seu chute foi maior"<<std::endl;
        }
        else{
            std::cout << "seu chute foi menor"<<std::endl;
        }
    }

    
    
}

void placar_final(){
    
    std::cout<< "Fim de Jogo!"<<std::endl;



    if(nao_acertou){
        std::cout<<"Você perdeu! Tente novamente"<<std::endl;
    }
    else{
        std::cout<< "Você acertou em " <<tentativa<< " tentativas"<<std::endl;
        std::cout.precision(2);
        std::cout << fixed;
        std::cout<< "Você fez " <<pontos<< " pontos"<<std::endl;
    }
}
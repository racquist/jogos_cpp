using namespace std;
#include "imprime.hpp"
#include "arquivo.hpp"
#include "condicional.hpp"

extern std:: string palavra_secreta;
extern std:: vector <char> chutes_errados;
extern std:: map <char, bool> chutou;

void imprime_cabecalho(){
    std::cout << "*******************************"<<std::endl;
    std::cout << "**Bem vindo ao Jogo da Forca!**"<<std::endl;
    std::cout << "*******************************"<<std::endl;
    std::cout <<std::endl;
}

void imprime_erros(){
    std::cout<< "Chutes errados: ";
    for(char letra:chutes_errados){
            std::cout<<letra<< " ";
    }
    std::cout<<std::endl;
}

void imprime_palavra(){
    for(char letra : palavra_secreta){
        if(chutou[letra]){
           std::cout<< letra << " " ;
        }
        else{
            std::cout<< "_ ";
        }
    }
}

void mensagem_final(){
    std::cout<<"Fim de Jogo!"<<std::endl;
    std::cout<<"A Palavra secreta é: "<< palavra_secreta<<std::endl;

    if(nao_acertou()){
        std::cout<<"Você não acertou! Tente novamente!"<<std::endl;

    }
    else{
        std::cout<<"Parabéns você acertou!"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Como prêmio você pode adicionar uma palavra ao Banco de dados"<<std::endl;
        std::cout<<"Você quer adicionar uma palavra? (S/N) ";
        char resposta;
        std::cin>>resposta;
        if(resposta == 'S'){
            adiciona_palavra();
        }

    }
}
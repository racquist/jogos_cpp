#include <iostream>
#include <locale.h>
#include <time.h>
#include <cstdlib>
using namespace std;

int main(){
    
    setlocale(LC_ALL, "Portuguese");

    cout << "*************************************"<<endl;
    cout << "**Bem vindo ao Jogo de Adivinhação!**"<<endl;
    cout << "*************************************"<<endl;

    cout<<"Escolha seu nível de dificuldade"<<endl;
    cout<<"Fácil (F) - Médio(M) - Díficil (D): ";

    char dificuldade;

    cin>> dificuldade;

    int numero_de_tentativas;

    if(dificuldade == 'F'){
        numero_de_tentativas = 15;
    }
    else if(dificuldade == 'M'){
        numero_de_tentativas = 10;
    }
    else{
        numero_de_tentativas = 5;
    }
    
    srand(time(0));
    const int NUMERO_SECRETO = rand() % 100;
    
    bool nao_acertou = true;
    int tentativa = 0;
    double pontos = 1000.0;

    for(tentativa = 1; tentativa <= numero_de_tentativas; tentativa++){

        int chute;
        cout<<"Tentativa: " <<tentativa<< endl;
   
        cout<< "QUal o valor do seu chute? ";
        cin >> chute;
        cout << "O valor do seu chute é: " <<chute<< endl;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos = pontos - pontos_perdidos;
    
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if(acertou){
            cout << "Parabéns! Você acertou o Número Secreto!"<<endl;
            nao_acertou = false;
            break;
        }
        else if(maior){
            cout << "Seu chute foi maior"<<endl;
        }
        else{
            cout << "seu chute foi menor"<<endl;
        }
    }

    cout<< "Fim de Jogo!"<<endl;

    if(nao_acertou){
        cout<<"Você perdeu! Tente novamente"<<endl;
    }
    else{
        cout<< "Você acertou em " <<tentativa<< " tentativas"<<endl;
        cout.precision(2);
        cout << fixed;
        cout<< "Você fez " <<pontos<< " pontos"<<endl;
    }
    

}

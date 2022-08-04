using namespace std;
#include <iostream>
#include <string>
#include <locale.h>
#include <cstdlib>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include "arquivo.hpp"
#include "chute.hpp"
#include "condicional.hpp"
#include "imprime.hpp"

string palavra_secreta;
vector <char> chutes_errados;
map <char, bool> chutou;

int main(){

    setlocale(LC_ALL, "Portuguese");
    imprime_cabecalho();
    sorteia_palavra();

    while(nao_acertou() && nao_enforcou()){
        
        imprime_erros();
        imprime_palavra();
        chuta();

    }

    mensagem_final();
        
}
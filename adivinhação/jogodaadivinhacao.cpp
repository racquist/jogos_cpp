using namespace std;
#include <iostream>
#include <locale.h>
#include <time.h>
#include <cstdlib>
#include "mensagem.hpp"
#include "dificuldade.hpp"
#include "numero.hpp"
#include "compara.hpp"

int main(){
    
    setlocale(LC_ALL, "Portuguese");
    mensagem_abertura();
    compara_chute_numero_secreto();
    placar_final();
    
}

using namespace std;
#include "condicional.hpp"
#include "chute.hpp"

extern std:: string palavra_secreta;
extern std:: vector <char> chutes_errados;
extern std:: map <char, bool> chutou;


bool letra_existe(char chute){
    
    for(char letra : palavra_secreta){
        if(chute == letra){
            return true;
        }
    }
    return false;
}

bool nao_acertou(){
    for(char letra: palavra_secreta){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}

bool nao_enforcou(){
    return chutes_errados.size() < 5;
}

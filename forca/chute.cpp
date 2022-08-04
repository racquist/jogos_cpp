using namespace std;
#include "chute.hpp"
#include "condicional.hpp"

extern std:: string palavra_secreta;
extern std:: vector <char> chutes_errados;
extern std:: map <char, bool> chutou;

void chuta(){
    std::cout<<std::endl;
    std::cout<<"De o seu chute: ";
    char chute;
    std::cin>>chute;
    chutou[chute] = true; 
    std::cout<<std::endl;
    if(letra_existe(chute)){
        std::cout<<"Seu chute está na palavra"<<std::endl;
    }
    else{
        std::cout<<"seu chute não está na palavra"<<std::endl;
        chutes_errados.push_back(chute);
    }
    std::cout<<std::endl;
}
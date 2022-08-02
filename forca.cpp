#include <iostream>
#include <string>
#include <locale.h>
#include <cstdlib>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;
string palavra_secreta;
map <char, bool> chutou;
vector<char> chutes_errados;

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

void imprime_cabecalho(){
    cout << "*******************************"<<endl;
    cout << "**Bem vindo ao Jogo da Forca!**"<<endl;
    cout << "*******************************"<<endl;
    cout <<endl;
}

void imprime_erros(){
    cout<< "Chutes errados: ";
    for(char letra:chutes_errados){
            cout<<letra<< " ";
    }
    cout<<endl;
}

void imprime_palavra(){
    for(char letra : palavra_secreta){
        if(chutou[letra]){
           cout<< letra << " " ;
        }
        else{
            cout<< "_ ";
        }
    }
}

void chuta(){
    cout<<endl;
    cout<<"De o seu chute: ";
    char chute;
    cin>>chute;
    chutou[chute] = true; 
    cout<<endl;
    if(letra_existe(chute)){
        cout<<"Seu chute está na palavra"<<endl;
    }
    else{
        cout<<"seu chute não está na palavra"<<endl;
        chutes_errados.push_back(chute);
    }
    cout<<endl;
}

vector<string> le_arquivo(){
    
    ifstream arquivo;
    arquivo.open("palavras.txt");

    if(arquivo.is_open()){

        int quantidade_palavras;
        arquivo >> quantidade_palavras;
        vector<string> palavras_do_arquivo;

        for(int i =0;i<quantidade_palavras;i++){
            string palavra_lida;
            arquivo >> palavra_lida;
            palavras_do_arquivo.push_back(palavra_lida);
        }
        arquivo.close();
        return palavras_do_arquivo;
    
    }
    else{
        cout<<"Banco de dados não encontrado, o Jogo será fechado :( "<<endl;
        exit(0);
    }

}

void sorteia_palavra(){
    vector<string> palavras = le_arquivo();

    srand(time(0));
    int indice_sorteado = rand() % palavras.size();
    palavra_secreta = palavras[indice_sorteado];
}

void salva_arquivo(vector<string> lista_palavras){
    
    ofstream arquivo;
    arquivo.open("palavras.txt");

    if(arquivo.is_open()){
        
        arquivo<< lista_palavras.size()<<endl;
        
        for(string palavra: lista_palavras){
            arquivo << palavra <<endl;
        }

        arquivo.close();
    }
    else{
        cout<<"Banco de dados não encontrado, o Jogo será fechado :( "<<endl;
        exit(0);

    }

}

void adiciona_palavra(){
    cout<<"Digite a nova palavra usando letras maíscula: "<<endl;
    string nova_palavra;
    cin>>nova_palavra;

    vector<string> lista_palavras = le_arquivo();
    lista_palavras.push_back(nova_palavra);
    salva_arquivo(lista_palavras);
}

void mensagem_final(){
    cout<<"Fim de Jogo!"<<endl;
    cout<<"A Palavra secreta é: "<< palavra_secreta<<endl;

    if(nao_acertou()){
        cout<<"Você não acertou! Tente novamente!"<<endl;

    }
    else{
        cout<<"Parabéns você acertou!"<<endl;
        cout<<endl;
        cout<<"Como prêmio você pode adicionar uma palavra ao Banco de dados"<<endl;
        cout<<"Você quer adicionar uma palavra? (S/N) ";
        char resposta;
        cin>>resposta;
        if(resposta == 'S'){
            adiciona_palavra();
        }

    }
}

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
#include "numero.hpp"

int define_numero_secreto(){
    srand(time(0));
    int numero_secreto = rand() % 100;
    return numero_secreto;
}
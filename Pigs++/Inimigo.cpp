#include "Inimigo.h"

using namespace PigsCpp::Entidades::Personagens;

Inimigo::Inimigo(const float v): Personagem(v), direcao(1), nivel_maldade(0){
    
}

Inimigo::Inimigo():Personagem(), direcao(1), nivel_maldade(0){
   
}

Inimigo::~Inimigo(){
    setMaldade(-1);
}



const int Inimigo::getMaldade() const {
    return nivel_maldade;
}
void Inimigo::setMaldade(const int m){
    nivel_maldade = m;
}

void Inimigo::inverterDir() {
    direcao *= -1;
}
void Inimigo::salvarDataBuffer(){        // terminar

}

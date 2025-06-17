#include "Inimigo.h"

using namespace PigsCpp::Entidades::Personagens;


Inimigo::Inimigo(const float vel, const int dir) :
    Personagem(vel), 
    nivel_maldade(0), 
    direcao(dir) {
    
}

Inimigo::Inimigo():Personagem(), nivel_maldade(0), direcao(0){
   
}

Inimigo::~Inimigo(){
    setMaldade(-1);
}



const int Inimigo::getMaldade() const {
    return nivel_maldade;
}
void Inimigo::setMaldade(int m){
    nivel_maldade = m;
}
void Inimigo::salvarDataBuffer(){        // terminar

}



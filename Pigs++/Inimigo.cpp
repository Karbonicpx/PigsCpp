#include "Inimigo.h"

using namespace PigsCpp::Entidades::Personagens;

Inimigo::Inimigo():Personagem(), nivel_maldade(0){
    // Colocando cor só pra ver o inimigo
    corpo.setFillColor(sf::Color::Red);

}

Inimigo::~Inimigo(){
    setMaldade(-1);
}

const int Inimigo::getMaldade() const {
    return nivel_maldade;
}
const void Inimigo::setMaldade(int m){
    nivel_maldade = m;
}
const void Inimigo::salvarDataBuffer(){        // terminar

}

#pragma once
#include "Inimigo.h"

using namespace PigsCpp;
using namespace Entidades;

Inimigo::Inimigo():Personagem(), nivel_maldade(0){
    // Colocando cor s� pra ver o inimigo
    corpo.setFillColor(sf::Color::Red);

}

Inimigo::~Inimigo(){
    setMaldade(-1);
}

int Inimigo::getMaldade(){
    return nivel_maldade;
}
void Inimigo::setMaldade(int m){
    nivel_maldade = m;
}
void Inimigo::salvarDataBuffer(){        // terminar

}
void Inimigo::mover() {
    // Implementar logica de movimento do inimigo
}
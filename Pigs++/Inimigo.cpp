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

const int Inimigo::getMaldade(){
    return nivel_maldade;
}
const void Inimigo::setMaldade(int m){
    nivel_maldade = m;
}
const void Inimigo::salvarDataBuffer(){        // terminar

}

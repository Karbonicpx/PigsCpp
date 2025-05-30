#pragma once
#include "Inimigo.h"

using namespace PigsCpp;
using namespace Entidades;

Inimigo::Inimigo():Personagem(){    // setar maldade

}

Inimigo::~Inimigo(){        // maldade -1
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
virtual void Inimigo::exercutar() = 0{}

virtual void Inimigo::danificar(Jogador* p) = 0{}
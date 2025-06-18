#pragma once 
#include "Bomba.h"

using namespace PigsCpp::Entidades;
using namespace sf;


// Construtor padrão, sem inicializações
Bomba::Bomba():
    Entidade(),
    velocidade(0.f),
    direcao(sf::Vector2f(0.f, 0.f)),
    ativo(false)
{

}
Bomba::Bomba(float x, float y, float vel, sf::Vector2f dir):
    Entidade(), velocidade(vel), direcao(dir), ativo(true), forma(5.0f) { 
        setPos(x, y); // Isso aqui já faz a função de setar a posição inicial
        forma.setFillColor(sf::Color::Yellow);
    }

Bomba::~Bomba() {}

void Bomba::mover() {  // Mover o projétil na direção especificada
    if (ativo) {
        x += direcao.x * velocidade;
        y += direcao.y * velocidade;
        forma.setPosition(sf::Vector2f(x,y));
    }
}

const bool Bomba::isAtivo() const {return ativo;}

// True para false, ou false para true
void Bomba::inverterAtivo() { ativo = !ativo; }

const float Bomba::getVel() const { return velocidade; }

void Bomba::executar(){
    mover();
    // Quando for desativada (tocar no jogador, chão ou parede), a bomba é removida do jogo
    if (ativo == false) {
        delete this;
    }
}

void Bomba::salvar(){
    // Implementar lógica de salvamento
}


#pragma once 
#include "Projetil.h"

using namespace PigsCpp;
using namespace Entidades;
using namespace sf;

Projetil::Projetil(float x, float y, float vel, sf::Vector2f dir):
    Entidade(), velocidade(vel), direcao(dir), ativo(true), forma(5.0f) { 
        setPos(x, y); // Isso aqui já faz a função de setar a posição inicial
        forma.setFillColor(sf::Color::Yellow);
    }

Projetil::~Projetil() {}

const void Projetil::mover() {  // Mover o projétil na direção especificada
    if (ativo) {
        x += direcao.x * velocidade;
        y += direcao.y * velocidade;
        forma.setPosition(sf::Vector2f(x,y));
    }
}

const void Projetil::desativar() {
    ativo = false;
}

const bool Projetil::isAtivo() const {return ativo;}

const void Projetil::executar(sf::RenderWindow& window){
    mover();
    window.draw(forma);
}

const void Projetil::salvar(){
    // Implementar lógica de salvamento
}
#pragma once 
#include "Projetil.h"

using namespace PigsCpp;
using namespace Entidades;
using namespace sf;

Projetil::Projetil(float x, float y, float vel, sf::Vector2f dir)  
        : Entidade(), velocidade(vel), direcao(dir), ativo(true), forma(5.0f) { 
        setPos(x, y);
        forma.setFillColor(sf::Color::Yellow);
        forma.setPosition(x, y);
    }

virtual Projetil::~Projetil() {}

const void Projetil::mover() {  // Mover o projétil na direção especificada
    if (ativo) {
        x += direcao.x * velocidade;
        y += direcao.y * velocidade;
        forma.setPosition(x, y);
    }
}

const void Projetil::desativar() {
    ativo = false;
}

const bool Projetil::isAtivo() const {return ativo;}

const void Projetil::executar(sf::RenderWindow& window) override {
    mover();
    window.draw(forma);
}

const void Projetil::salvar() override {
    // Implementar lógica de salvamento
}
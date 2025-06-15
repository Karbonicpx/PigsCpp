#pragma once
#include "Leitao.h"

using namespace PigsCpp;
using namespace Entidades;
using namespace Personagens;

Leitao::Leitao() : Inimigo(), raio(15), velocidade(2){
    // Cor do leitao para visualizacao
    corpo.setFillColor(sf::Color::Magenta);
    setMaldade(1);
}
Leitao::~Leitao() {

}
void Leitao::executar() {
    // Comportamento do leitao aqui
}
void Leitao::danificar(Jogador* p) {
    // Dano ao jogador
    if (p) {
        p->setVidas(p->getVidas() - getMaldade());
    }
}
void Leitao::salvar() {
    // Implementar logica de salvamento
}
void Leitao::mover(){
    static int direcao = 1; // 1 para direita, -1 para esquerda
    static float posInicial = -1.0f;

    sf::Vector2f pos = corpo.getPosition();

    // Salva a posição inicial na primeira chamada
    if (posInicial < 0.0f)
        posInicial = pos.x;

    pos.x += velocidade * direcao;

    // Limites de patrulha baseados no raio
    float limiteDireita = posInicial + raio;
    float limiteEsquerda = posInicial - raio;

    if (pos.x >= limiteDireita) {
        pos.x = limiteDireita;
        direcao = -1;
    }
    else if (pos.x <= limiteEsquerda) {
        pos.x = limiteEsquerda;
        direcao = 1;
    }

    corpo.setPosition(pos);
}


#include "Leitao.h"

using namespace PigsCpp::Entidades::Personagens;

Leitao::Leitao() : Inimigo(), raio(40), velocidade(0.1f), direcao(1) {
    // Cor do leitao para visualizacao
    corpo.setFillColor(sf::Color::Magenta);
    setMaldade(1);
    posInicial = corpo.getPosition().x;
}
Leitao::~Leitao() {

}
void Leitao::executar() {
    mover();
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
void Leitao::mover() {
    sf::Vector2f pos = corpo.getPosition();
    pos.x += velocidade * direcao;

    float limite = posInicial + direcao * raio;

    // Inverte direção se passar do limite
    if ((direcao == 1 && pos.x >= limite) ||
        (direcao == -1 && pos.x <= limite)) {

        pos.x = limite;     // Corrige posição
        direcao *= -1;      // Inverte direção
    }

    corpo.setPosition(pos);
}


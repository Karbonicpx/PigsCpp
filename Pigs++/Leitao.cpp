#include "Leitao.h"

using namespace PigsCpp::Entidades::Personagens;

Leitao::Leitao() : Inimigo(1.5f), raio(5.0f){
    // Cor do leitao para visualizacao
    corpo.setFillColor(sf::Color::Magenta);
    setMaldade(1);
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

    
    sf::Vector2f deslocamento(velocidade * direcao, 0.f);
    corpo.move(deslocamento);

    float posX = corpo.getPosition().x;
    float limite = posInicial + direcao * raio;

    if ((direcao == 1 && posX >= limite) || (direcao == -1 && posX <= limite)) {
        corpo.setPosition(sf::Vector2f(limite, corpo.getPosition().y));
        inverterDir();
    }
}



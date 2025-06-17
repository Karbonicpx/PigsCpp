#include "Baconzilla.h"

using namespace PigsCpp::Entidades::Personagens;

Baconzilla::Baconzilla(): Inimigo(1.5f, 1), tamanho(1), forca(8), tempoTrocaDirecao(2.0f) {
    // Cor do Baconzilla para visualizacao
    corpo.setFillColor(sf::Color::Red);
    setMaldade(10);
};
Baconzilla::~Baconzilla() {

};


void Baconzilla::executar() {
    mover();
    // atirarProjetil();
};

void Baconzilla::danificar(Jogador* p) { // chamado quando o projetil colidir com o jogador
    // Dano ao jogador
    if (p) {
        p->setVidas(p->getVidas() - (forca + getMaldade() + tamanho));
    }
};
void Baconzilla::salvar() {
    // Implementar logica de salvamento
};


void Baconzilla::mover() {

    sf::Vector2f deslocamento(velocidade * direcao, 0);
    corpo.move(deslocamento);

    // Relógio: se passou tempo suficiente, checa troca de direção
    if (relogio.getElapsedTime().asSeconds() >= tempoTrocaDirecao) {
        relogio.restart();

        // Gera 0 ou 1 aleatório
        int troca = rand() % 2;

        if (troca == 1) {
            direcao *= -1; // inverte direção
        }
    }
}
void Baconzilla::atirarProjetil() {


    sf::Vector2f origem = corpo.getPosition();
    float velocidade = 5.0f;
    Bomba* p = new Bomba(origem.x, origem.y, velocidade, sf::Vector2f(origem.x, origem.y));
}



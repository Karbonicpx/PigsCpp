
#include "Toucinho.h"

using namespace PigsCpp;
using namespace Entidades;
using namespace Personagens;

Toucinho::Toucinho() : Inimigo(), forca(5), tempoAtaque(0) {
    // Cor do tocinho para visualizacao
    corpo.setFillColor(sf::Color::Cyan);
    setMaldade(5);
}
Toucinho::~Toucinho() {

}
void Toucinho::executar() {
    // Fica parado
    mover();

    // Lança bomba a cada 2 segundos (supondo 60 FPS)
    if (++tempoAtaque > 120) {
        tacarBomba();
        tempoAtaque = 0;
    }
}
void Toucinho::danificar(Jogador* p) { // chamado quando o projetil colidir com o jogador
    // Dano ao jogador
    if (p) {
        int dano = 15; // Exemplo de dano
        p->setVidas(p->getVidas() - (forca + getMaldade()));
    }
}
void Toucinho::salvar() {
    // Implementar logica de salvamento
}
void Toucinho::mover() {
    // fica parado
}
void Toucinho::tacarBomba() {
    sf::Vector2f origem = corpo.getPosition();
    sf::Vector2f dir(0.f, 1.f); // para baixo
    bombas.push_back(Projetil(origem.x, origem.y, 4.0, dir));
}

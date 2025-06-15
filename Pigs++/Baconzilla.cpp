#include "Baconzilla.h"

using namespace PigsCpp;
using namespace Entidades;
using namespace Personagens;

Baconzilla::Baconzilla():tamanho(1), forca(8) {
    // Cor do Baconzilla para visualizacao
    corpo.setFillColor(sf::Color::Red);
    setMaldade(10);
};
Baconzilla::~Baconzilla() {

};
void Baconzilla::executar(Jogador* j, std::vector<Projetil*>& projeteis) {
    mover(j);
	atirarProjetil(j, projeteis);
};
void Baconzilla::danificar(Jogador* p) { // chamado quando o projetil colidir com o jogador
    // Dano ao jogador
    if (p) {
        p->setVidas(p->getVidas() - (forca + getMaldade() + tamanho));
    }
};
void Baconzilla::salva() {
    // Implementar logica de salvamento
};
void Baconzilla::mover(Jogador* j) {
    if (!j) return;

    sf::Vector2f posJogador = j->getPosition();
    sf::Vector2f posBacon = corpo.getPosition();
    float velocidade = 2.f;
    sf::Vector2f movimento(0.f, 0.f);

    if (posJogador.x > posBacon.x)
        movimento.x = velocidade;
    else if (posJogador.x < posBacon.x)
        movimento.x = -velocidade;

    if (posJogador.y > posBacon.y)
        movimento.y = velocidade;
    else if (posJogador.y < posBacon.y)
        movimento.y = -velocidade;

    corpo.move(movimento);
};
void Baconzilla::atirarProjetil(Jogador* alvo, std::vector<Projetil*>& projeteis) {
    if (!alvo) return;

    sf::Vector2f origem = corpo.getPosition();
    sf::Vector2f destino = alvo->getPosition();
    sf::Vector2f direcao = destino - origem;
    float comprimento = std::sqrt(direcao.x * direcao.x + direcao.y * direcao.y);
    if (comprimento != 0)
        direcao /= comprimento;

    float velocidade = 5.0f;
    Projetil* p = new Projetil(origem.x, origem.y, velocidade, direcao);
    projeteis.push_back(p);
}



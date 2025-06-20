#include "Baconzilla.h"

using namespace PigsCpp::Entidades::Personagens;

Baconzilla::Baconzilla() : Inimigo(1.5f), tamanho(5), forca(8), tempoTrocaDirecao(2.0f) {
    // Cor do Baconzilla para visualizacao
    corpo.setFillColor(sf::Color::Red);
    setMaldade(10);
};
Baconzilla::~Baconzilla() {

};

// Método virtual puro
void Baconzilla::executar() {
    mover();
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


void Baconzilla::atirarProjetil(Jogador* alvo, std::vector<Bomba*>& projeteis) {
    if (!alvo) return;

    sf::Vector2f origem = corpo.getPosition();
    sf::Vector2f destino = alvo->getCorpo().getPosition();
    sf::Vector2f direcao = destino - origem;
    float comprimento = std::sqrt(direcao.x * direcao.x + direcao.y * direcao.y);
    if (comprimento != 0)
        direcao /= comprimento;

    float velocidade = 5.0f;
    Bomba* p = new Bomba(origem.x, origem.y, velocidade, direcao);
    projeteis.push_back(p);
}



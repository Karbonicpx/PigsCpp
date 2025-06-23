#include "Baconzilla.h"

using namespace PigsCpp::Entidades::Personagens;

Baconzilla::Baconzilla() : 
    Inimigo("textures/Baconzilla.png", 45.0f, 45.0f, gerarAleatorioFloat(0.2f, 0.25f), 3),
    tempoTrocaDirecao(gerarAleatorioFloat(0.5, 1.0f)),
    tamanho((rand() % 3) + 1), // 1 a 3
    forca((rand() % 5) + 1) // 1 a 5
{
    velocidade = gerarAleatorioFloat(0.1f, 0.2f);
    direcao = -1;
    
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
void Baconzilla::salvar(std::ofstream& arq) {
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
            inverterDir(); // inverte direção
        }
    }
}


void Baconzilla::atirarProjetil() {
    sf::Vector2f origem = corpo.getPosition();
    sf::Vector2f dir(0.f, 1.f); // para baixo
    Bomba* bomba = new Bomba(origem.x, origem.y, 4.0, dir);
    bomba->executar();
}



#include "Toucinho.h"

using namespace PigsCpp::Entidades::Personagens;

Toucinho::Toucinho() : 
    Inimigo("textures/Toucinho.png", 35.0f, 35.0f, 0.f, 2),
    tempoAtaque(0), 
    forca((rand() % 5) + 1) {
    
  
}

/*Toucinho::Toucinho() : Inimigo(0.f), forca(5), tempoAtaque(0) {
    // Cor do tocinho para visualizacao
    corpo.setFillColor(sf::Color::Cyan);
}*/
Toucinho::~Toucinho() {
    while (!filaBombas.empty()) {
        delete filaBombas.front();
        filaBombas.pop();
    }
}
void Toucinho::executar() {
    // Fica parado
    mover();
    
}

void Toucinho::danificar(Jogador* p) { // chamado quando o projetil colidir com o jogador
    // Dano ao jogador
    if (p) {
        p->setVidas(p->getVidas() - (forca + getMaldade()));
    }
}
void Toucinho::salvar() {
    // Implementar logica de salvamento
}
void Toucinho::mover() {
    // fica parado
    if (++tempoAtaque > 120) {
        tacarBomba();
        tempoAtaque = 0;
    }
}
void Toucinho::tacarBomba() {
    sf::Vector2f origem = corpo.getPosition();
    sf::Vector2f dir(0.f, 1.f); // Direção para baixo

    filaBombas.push(new Bomba(origem.x, origem.y, 4.0, dir));
}

void Toucinho::executar() {
    tempoAtaque++;

    if (tempoAtaque >= 120) {
        tacarBomba();
        tempoAtaque = 0;
    }

    // Percorrer bombas
    int tamanho = static_cast<int>(filaBombas.size());
    for (int i = 0; i < tamanho; i++) {
        Bomba* b = filaBombas.front();
        filaBombas.pop();

        b->executar();

        if (!b->isAtivo()) {
            filaBombas.push(b); // Continua na fila se não explodiu (desativou)
        }
        else {
            delete b; // Desativou, remove
        }
    }
}
    /*sf::Vector2f dir(0.f, 1.f); // para baixo
    Bomba* bomba = new Bomba(origem.x, origem.y, 4.0, dir);
    bombas.push_back(bomba);
    bomba->executar();
}*/



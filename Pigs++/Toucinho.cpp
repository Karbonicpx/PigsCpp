#include "Toucinho.h"

using namespace PigsCpp::Entidades::Personagens;

Toucinho::Toucinho(ListaEntidades* lista) :
    Inimigo("textures/Toucinho.png", 35.0f, 35.0f, 0.f, 2),
    tempoAtaque(0),
    forca((rand() % 5) + 1),
    listaEntidades(lista)

{
    direcao = -1;
}

Toucinho::~Toucinho() {
    while (!filaBombas.empty()) {
        delete filaBombas.front();
        filaBombas.pop();
    }
}


void Toucinho::danificar(Jogador* p) {
    if (p) {
        p->setVidas(p->getVidas() - (forca + getMaldade()));
    }
}
    void Toucinho::salvar(std::ofstream & arq) {
    arq << "TOUCINHO ";
    Inimigo::salvarDataBuffer(arq);
    arq << forca << " " << tempoAtaque << std::endl;
}

void Toucinho::mover() {
    
}

void Toucinho::tacarBomba() {
    sf::Vector2f origem = corpo.getPosition();

    float dirX = direcao * 3.0f;
    float dirY = -5.5f;

    sf::Vector2f vel(dirX, dirY);

    // Cria a bomba
    Bomba* b = new Bomba(origem.x + corpo.getSize().x / 2, origem.y, vel);

    // Adiciona na lista de entidades
    listaEntidades->listaEntidades.incluir(b);
}

void Toucinho::executar() {
    tempoAtaque++;
    if (tempoAtaque >= 120) {
        tacarBomba();
        tempoAtaque = 0;
    }
}
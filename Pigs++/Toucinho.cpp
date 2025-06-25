#include "Toucinho.h"

using namespace PigsCpp::Entidades::Personagens;

Toucinho::Toucinho(ListaEntidades* lista) :
    Inimigo("textures/Toucinho.png", 35.0f, 35.0f, 0.f, 2),
    Atirador(120, lista),
    forca((rand() % 5) + 1)

{
    direcao = -1;
}

Toucinho::~Toucinho() {
  
    listaEntidades = nullptr;
}

void Toucinho::danificar(Jogador* p) {
    if (p) {
        p->setVidas(p->getVidas() - (forca + getMaldade()));
    }
}

void Toucinho::salvar(std::ofstream& arq) {
    arq << "TOUCINHO ";
    Inimigo::salvarDataBuffer(arq);
    arq << forca << " " << tempoProjetil << std::endl;
}

void Toucinho::mover() {
    
}

void Toucinho::atirarProjetil() {
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
    if (numVidas > 0) {
        projetilRecarga();
    }
    else {
        nivel_maldade = 0;
        forca = 0;
        corpo.setFillColor(sf::Color(255, 255, 255, 0));
    }
    
}
#include "Bomba.h"

using namespace PigsCpp::Entidades;
using namespace sf;

Bomba::Bomba(float x, float y, sf::Vector2f vel) :
    Entidade("textures/Bomba.png", 13.f, 16.f, false, true),
    velocidade(vel),
    aceleracao(0.f, 0.3f), // Simula gravidade
    ativo(true),
    dano(1)

{
    setPos(x, y);
}

Bomba::Bomba() :
    Entidade("textures/Bomba.png", 13.f, 16.f, false, true),
    velocidade(0.f, 0.f),
    aceleracao(0.f, 0.35f),
    ativo(false),
    dano(0)
{
}

Bomba::~Bomba() {}

int Bomba::explodir() {
    return dano;
}
void Bomba::mover() {
    
    velocidade += aceleracao;
    corpo.move(velocidade);
}

void Bomba::executar() {
    if (ativo) {
        mover();
    }
    else {

        dano = 0;
        corpo.setFillColor(sf::Color(255, 255, 255, 0));
    }
}

void Bomba::salvar(std::ofstream& arq) {
    Entidade::salvarDataBuffer(arq);
    arq << " " << ativo << " " << dano << std::endl;
}
const bool Bomba::isAtivo() const {
    return ativo;
}

void Bomba::desativar() {
    ativo = false;
}
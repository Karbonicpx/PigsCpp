#include "Bomba.h"

using namespace PigsCpp::Entidades;
using namespace sf;

Bomba::Bomba(float x, float y, sf::Vector2f vel) :
    Projetil("textures/Bomba.png", 13.f, 16.f, x, y, vel, 1),
    aceleracao(0.f, 0.3f)
{

}

Bomba::Bomba() :
    Projetil("textures/Bomba.png", 13.f, 16.f, x, y, sf::Vector2f(0.f, 0.f), 1),
    aceleracao(0.f, 0.0f)
{
}

Bomba::~Bomba() {}


void Bomba::mover() {

    velocidade += aceleracao;
    corpo.move(velocidade);
}

void Bomba::salvar(std::ofstream& arq) {
<<<<<<< Updated upstream
    Entidade::salvarDataBuffer(arq);
    arq << " " << ativo << " " << dano << std::endl;
=======
    arq << aceleracao.x << aceleracao.y << std::endl;
>>>>>>> Stashed changes
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

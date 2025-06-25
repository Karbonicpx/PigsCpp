#include "Martelo.h"

using namespace PigsCpp::Entidades;

Martelo::Martelo(float x, float y, sf::Vector2f vel) :
	Projetil("textures/Martelo.png", 33.0f, 13.0f, x, y, vel, 1),
	velocidadeGiro(10.f)
{
	
}
Martelo::~Martelo() {}

void Martelo::mover() 
{
	corpo.move(velocidade);
}

void Martelo::salvar(std::ofstream& arq) {
	Entidade::salvarDataBuffer(arq);
	arq << velocidade.x << " "
	<< velocidade.y << " " 
	<< ativo << " " 
	<< dano << std::endl;
}

void Martelo::executar() {

	if (ativo) mover();
	else {
		dano = 0;
		corpo.setFillColor(sf::Color(255, 255, 255, 0));
	}
}
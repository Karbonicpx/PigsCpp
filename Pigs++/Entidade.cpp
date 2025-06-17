#include "Entidade.h"

using namespace PigsCpp;
using namespace Entidades;


Entidade::Entidade() :
	x(0.f),
	y(0.f),
	posInicial(0.f)
{
	
};

Entidade::~Entidade() {

}


void Entidade::setPos(const float x, const float y) {

	this->x = x;
	this->y = y;

	corpo.setPosition(sf::Vector2f(this->x, this->y));

	posInicial = x; // Sempre que definir posição, já salva
}

void Entidade::setTamanho(const float largura, const float altura) {
	corpo.setSize(sf::Vector2f(largura, altura));
}

// Implementar depois
void Entidade::salvarDataBuffer() {

}


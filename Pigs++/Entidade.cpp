#include "Entidade.h"

using namespace PigsCpp::Entidades;

Entidade::Entidade(const bool sG, const bool sV) :
	x(0.f),
	y(0.f),
	posInicial(0.f),
	sofreGravidade(sG),
	spriteVisivel(sV)
{

};

Entidade::Entidade() :
	x(0.f),
	y(0.f),
	posInicial(0.f),
	sofreGravidade(false),
	spriteVisivel(false)
{};

Entidade::~Entidade() {

}

void Entidade::setPos(const float x, const float y) {

	this->x = x;
	this->y = y;

	corpo.setPosition(sf::Vector2f(this->x, this->y));

	posInicial = x; // Sempre que definir posição, já salva
}


bool Entidade::getSofreGravidade() const {
	return sofreGravidade;
}

void Entidade::setSofreGravidade(const bool sG) {
	sofreGravidade = sG;
}

void Entidade::setSpriteVisivel(const bool sV) {
	spriteVisivel = sV;
}

// Implementar depois
void Entidade::salvarDataBuffer() {

}


#include "Entidade.h"

using namespace PigsCpp::Entidades;

Entidade::Entidade(const std::string texturePath, const float bodyX, const float bodyY, const bool sV, const bool sG) :
	Ente(texturePath, bodyX, bodyY, sV),
	x(0.f),
	y(0.f),
	posInicial(0.f),
	sofreGravidade(sG)
{

};

Entidade::Entidade() :
	x(0.f),
	y(0.f),
	posInicial(0.f),
	sofreGravidade(false)
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



// Implementar depois
void Entidade::salvarDataBuffer(std::ofstream& arq) {
	arq << corpo.getPosition().x << " " << corpo.getPosition().y << " ";
}


#include "Projetil.h"

using namespace PigsCpp::Entidades;


Projetil::Projetil(const std::string texturePath, const float bodyX, const float bodyY, const float posX, const float posY, sf::Vector2f vel, const int d):
	Entidade(texturePath, bodyX, bodyY, true, false),
	dano(d),
	ativo(true),
	velocidade(vel)
{
	setPos(posX, posY);
}

Projetil::~Projetil(){}

void Projetil::salvar() {

}

int Projetil::colidir() {
	return dano;
}

const bool Projetil::isAtivo() const {
	return ativo;
}

void Projetil::desativar() {
	ativo = false;
}

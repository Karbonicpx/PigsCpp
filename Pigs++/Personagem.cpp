#include "Personagem.h"


using namespace PigsCpp::Entidades::Personagens;

Personagem::Personagem(const float vel) :
	Entidade(true, true),
	numVidas(3),
	velocidade(vel)
{

}
Personagem::Personagem() :
	Entidade(),
	numVidas(3),
	velocidade(0.f)
{

}
Personagem::~Personagem() {}

const int Personagem::getVidas() const {
	return numVidas;
}

void Personagem::setVidas(const int v)  {
	numVidas = v;
}

float Personagem::getVelX() {
	return velocidade;
}

void Personagem::salvarDataBuffer() {

}
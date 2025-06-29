#include "Personagem.h"


using namespace PigsCpp::Entidades::Personagens;

Personagem::Personagem(const std::string texturePath, const float bodyX, const float bodyY, const float vel, const int vida) :
	Entidade(texturePath, bodyX, bodyY, true, true),
	numVidas(vida),
	velocidade(vel)
{

}
Personagem::Personagem() :
	Entidade(),
	numVidas(-1),
	velocidade(0.f)
{

}
Personagem::~Personagem() {}

const int Personagem::getVidas() const {
	return numVidas;
}

void Personagem::setVidas(const int v) {
	numVidas = v;
}

float Personagem::getVelX() {
	return velocidade;
}

void Personagem::salvarDataBuffer(std::ofstream& arq) {
	Entidade::salvarDataBuffer(arq);
	arq << numVidas << " " << velocidade << " ";
}

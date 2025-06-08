#include "Personagem.h"


using namespace PigsCpp::Entidades::Personagens;

Personagem::Personagem():
	Entidade(),
	numVidas(3)
{

}
Personagem::~Personagem() {}

void Personagem::mover() {

	// Atenção: Essa vai ser a implementação padrão do método mover CASO ele não seja 
	// Redefinido nas classes que herdaram esta
	corpo.move(sf::Vector2f(0.1f, 0.f));
}

const int Personagem::getVidas() const {
	return numVidas;
}

void Personagem::setVidas(const int v)  {
	numVidas = v;
}

void Personagem::salvarDataBuffer() {

}
#include "Personagem.h"


using namespace PigsCpp::Entidades::Personagens;

Personagem::Personagem():
	Entidade(),
	numVidas(3)
{

}
Personagem::~Personagem() {}

const void Personagem::mover() {

	// Aten��o: Essa vai ser a implementa��o padr�o do m�todo mover CASO ele n�o seja 
	// Redefinido nas classes que herdaram esta
	corpo.move(sf::Vector2f(0.1f, 0.f));
}

const int Personagem::getVidas() const {
	return numVidas;
}

const void Personagem::setVidas(const int v)  {
	numVidas = v;
}
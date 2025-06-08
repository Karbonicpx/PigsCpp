#include "Entidade.h"

using namespace PigsCpp;
using namespace Entidades;

// Chamando a construtora da classe pai para que ela registre os IDs + body
Entidade::Entidade() :
	Ente(), 
	x(0.f),
	y(0.f)
{
	
};

Entidade::~Entidade() {

}

// Função que vai redefinir as coordenadas inicias X e Y
// E vai redefinir a posição inicial do objeto
void Entidade::setPos(const float xP, const float yP) {
	
	x = xP;
	y = yP;
	corpo.setPosition(sf::Vector2f(x, y));
}

// Implementar depois
void Entidade::salvarDataBuffer() {

}


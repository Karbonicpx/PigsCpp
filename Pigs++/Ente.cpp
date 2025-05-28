#include "Ente.h"

using namespace PigsCpp;

Ente::Ente() :
	corpo(sf::Vector2f(100.f, 100.f))
{
	this->operator++();
	printf("%d", id);

};

Ente::~Ente() {
	delete this;
};

const void Ente::operator++() { id++; };

const void Ente::desenhar() {

}
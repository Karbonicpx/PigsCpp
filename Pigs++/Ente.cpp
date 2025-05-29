#include "Ente.h"

// Usando isso aqui pra n�o precisar chama "PigsCpp::" toda hora
using namespace PigsCpp;


// Aqui ele vai definir o body como um quadrado 100x100
// E o operator vai incrementar a ID em 1, e mostrar na tela
Ente::Ente() :
	corpo(sf::Vector2f(100.f, 100.f))
{
	//
	this->operator++();
	printf("%d", id);

};
// Definindo aqui fora por ser est�tico
int Ente::id(0);

// Deleta o objeto quando for removido
Ente::~Ente() {
	delete this;
};

// Sobrecarga do ++, que vai aumentar o id (� privado, ent�o s� vai ser usado aqui)
const void Ente::operator++() { id++; };

// Aqui ele vai apontar o campo janela para uma janela qualquer
const void Ente::setJanela(sf::RenderWindow* j) {
	janela = j;
}

// E aqui o ente est� apontando desenhar� ele mesmo
const void Ente::desenhar() {
	janela->draw(corpo);
}

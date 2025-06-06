#include "Ente.h"

// Usando isso aqui pra n�o precisar chama "PigsCpp::" toda hora
using namespace PigsCpp;
using namespace PigsCpp::Gerenciadores;



// Aqui ele vai definir o body como um quadrado 100x100
// E o operator vai incrementar a ID em 1, e mostrar na tela
Ente::Ente() :
	corpo(sf::Vector2f(100.f, 100.f))
{
	this->operator++();
	printf("%d\n", id);

};

// Definindo fora da construtora por ser estático
int Ente::id(0);
Gerenciador_Grafico* Ente::pGG = nullptr;


Ente::~Ente() {
	
};

const int Ente::getId() const {
	return id;
};

const sf::RectangleShape Ente::getCorpo() const {
	return corpo;
};

// Sobrecarga do ++, que vai aumentar o id (� privado, ent�o s� vai ser usado aqui)
const void Ente::operator++() { id++; };


// E aqui, o ente vai servir de parâmetro pro gerenciador gráfico desenhar ele
const void Ente::desenhar() {
	pGG->setCorpo(corpo);
	pGG->desenhar();
};

// Setando a instância do gerenciador gráfico dentro da classe ente
// Como o pGG é um ponteiro estático, todos os objetos que derivam da classe ente
// Vão apontar para o mesmo gerenciador gráfico
const void Ente::setGG(Gerenciador_Grafico* gg) {
	pGG = gg;
}
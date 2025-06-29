#include "Ente.h"
#include <iostream>

// Usando isso aqui pra não precisar chama "PigsCpp::" toda hora
using namespace PigsCpp;
using namespace PigsCpp::Gerenciadores;


Ente::Ente(const std::string texturePath, const float bodyX, const float bodyY, const bool sV) :
	corpo(sf::Vector2f(bodyX, bodyY)),
	spriteVisivel(sV),
	idIndividual(-1), // Setando como -1, por que entidades com valor do id >= 0 vão ser usadas para checagem de colisão entre blocos.
	textura(new Texture(texturePath))
{
	corpo.setTexture(textura);
};

Ente::Ente() :
	corpo(sf::Vector2f(32.0f, 32.0f)),
	idIndividual(-1),
	spriteVisivel(false),
	textura(new Texture("textures/Template.png"))

{
	corpo.setTexture(textura);
};

// Definindo fora da construtora por ser estático
int Ente::id(-1);
Gerenciador_Grafico* Ente::pGG(nullptr);


Ente::~Ente() {

	delete textura;
	textura = nullptr;
};

const int Ente::getId() const {
	return id;
};

// Não tem const pois vamos manipular a gravidade do corpo
sf::RectangleShape& Ente::getCorpo() {
	return corpo;
};

bool Ente::getSpriteVisivel() const {
	return spriteVisivel;
}

void Ente::setSpriteVisivel(const bool sV) {
	spriteVisivel = sV;
}

// Sobrecarga do ++, que vai aumentar o id
void Ente::operator++()
{
	idIndividual = id;
	id++;
};


// E aqui, o ente vai servir de parâmetro pro gerenciador gráfico desenhar ele
void Ente::desenhar() {
	pGG->desenharEnte(this);
};

// Setando a instância do gerenciador gráfico dentro da classe ente
// Como o pGG é um ponteiro estático, todos os objetos que derivam da classe ente
// Vão apontar para o mesmo gerenciador gráfico
void Ente::setGG(Gerenciador_Grafico* gg) {
	pGG = gg;
}

// Usado em casos que é preciso randomizar o valor de algum atributo em uma entidade
float Ente::gerarAleatorioFloat(const float min, const float max) {
	return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

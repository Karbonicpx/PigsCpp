#include "Martelo.h"

using namespace PigsCpp::Entidades;

Martelo::Martelo(float x, float y, float vel, sf::Vector2f dir) :
	Entidade(false, true), dano(10), velocidade(vel), direcao(dir), ativo(true) {
	setPos(x, y);
	corpo.setFillColor(sf::Color::Blue);
	this->desenhar();
}
Martelo::~Martelo(){}
void Martelo::mover() {
	if (ativo) {
		x += direcao.x * velocidade;
		y += direcao.y * velocidade;
		corpo.setPosition(sf::Vector2f(x, y));
	}
}
const bool Martelo::isAtivo() const {
	return ativo;
}
void Martelo::executar() {
	mover();
	// Quando for desativado (tocar no jogador, chão ou parede), o martelo é removido do jogo
	if (!ativo) {
		delete this;
	}
}
void Martelo::salvar() {
	// Implementar lógica de salvamento
}
const float Martelo::getDano() const {
	return dano;
}
void Martelo::desativar() {
	ativo = false;
	corpo.setFillColor(sf::Color::Transparent); // Torna invisível
}
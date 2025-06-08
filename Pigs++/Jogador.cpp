#include "Jogador.h"

using namespace PigsCpp::Entidades::Personagens;


Jogador::Jogador() :
	Personagem(),
	pontos(0)
{
	// Colocando cor só pra ver o jogador
	if (getId() == 1) {
		corpo.setFillColor(sf::Color::Green);
	}
	else {
		corpo.setFillColor(sf::Color::Red);
	}
};
Jogador::~Jogador() {

}

// Método que vai realizar comportamento de mover o jogador para uma direção
// Através de uma tecla escolhida e uma "velocidade"
void Jogador::apertarTecla(Key tecla, float spdX, float spdY) {

	if (isKeyPressed(tecla)) {

		corpo.move(Vector2f(spdX, spdY));
	}
}

// Redefinição do método mover de personagem!
void Jogador::mover() {

	// Mude a velocidade vertical e horizontal como desejar
	float spdX = 0.1f;
	float spdY = 0.1f;

	// Movendo pra direita no D
	apertarTecla(Key::D, spdX, 0.f);
	// Movendo pra esquerda no A
	apertarTecla(Key::A, -spdX, 0.f);
	// Movendo pra cima no W
	apertarTecla(Key::W, 0.f, -spdY);
	// Movendo pra baixo no S
	apertarTecla(Key::S, 0.f, spdY);
}

// Executando o mover, e futuros eventos relacionados ao jogador
void Jogador::executar() {
	mover();
}

// Implementar depois
void Jogador::salvar() {

}
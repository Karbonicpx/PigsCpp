#include "Jogador.h"

using namespace PigsCpp::Entidades::Personagens;

Jogador::Jogador() :
	Personagem(1.5f),
	pontos(0)

{
	// Colocando cor só pra ver o jogador
	corpo.setFillColor(Color::Green);
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
	float spdX = 0.1f * velocidade;
	float spdY = 0.1f * velocidade;

	// Movendo pra direita no D
	apertarTecla(Key::D, spdX, 0.f);
	// Movendo pra esquerda no A
	apertarTecla(Key::A, -spdX, 0.f);
}

// Executando o mover, e futuros eventos relacionados ao jogador
void Jogador::executar() {
	mover();
}

// Implementar depois
void Jogador::salvar() {

}
sf::Vector2f Jogador::getPosition() const {
	return corpo.getPosition();
}
void Jogador::setVelocidade(float v) {velocidade = v;}
#include "Jogador.h"

using namespace PigsCpp::Entidades::Personagens;


Jogador::Jogador(const std::string jTexturePath, const bool ehJ1) :
	Personagem(jTexturePath, 47.0f, 36.0f, 3.0f, 1),
	pontos(0),
	alturaMaximaPulo(140.0f),
	deslocamentoPulo(0.f),
	relogioPulo(),
	podePular(true),
	pisandoPoca(false),
	ehJogador1(ehJ1)
	

{
	
};
Jogador::Jogador() :
	Personagem(),
	pontos(0),
	alturaMaximaPulo(140.0f),
	deslocamentoPulo(0.f),
	relogioPulo(),
	podePular(true),
	pisandoPoca(false),
	ehJogador1(true)

{
	
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

	
	if (pisandoPoca) { velocidade = 2.0f; }
	else { velocidade = 3.0f; }

	
	// Jogador 1
	if (ehJogador1) {

		// Movendo pra direita no D
		apertarTecla(Key::D, velocidade, 0.f);
		// Movendo pra esquerda no A
		apertarTecla(Key::A, -velocidade, 0.f);

		// Lógica do pulo
		if (isKeyPressed(Key::W) && podePular) {
			pisandoPoca = false;
			iniciarPulo();
		}

		if (podePular == false) { atualizarPulo(); }
	}
	// Jogador 2
	else {
		// Movendo pra direita na seta da esquerda
		apertarTecla(Key::Right, velocidade, 0.f);
		// Movendo pra esquerda na seta da direita
		apertarTecla(Key::Left, -velocidade, 0.f);

		// Lógica do pulo
		if (isKeyPressed(Key::Up) && podePular) {
			pisandoPoca = false;
			iniciarPulo();
		}

		if (podePular == false) { atualizarPulo(); }
		
	}
	

	
}

void Jogador::iniciarPulo() {
	podePular = false;
	deslocamentoPulo = 0.0f;
	relogioPulo.restart();
	setSofreGravidade(false);
	
}



void Jogador::atualizarPulo() {

	float tempo = relogioPulo.getElapsedTime().asSeconds();
	float duracao = 0.7f;

	if (tempo <= duracao) {
		float progresso = tempo / duracao;

		// Calcula o deslocamento desejado neste frame
		float novoDeslocamento = alturaMaximaPulo * (1.0f - (2.0f * progresso - 1.0f) * (2.0f * progresso - 1.0f));

		// Move apenas a diferença desde o último frame
		float diferenca = novoDeslocamento - deslocamentoPulo;
		corpo.move(sf::Vector2f(0, -diferenca));  // Move para cima (eixo Y negativo)

		deslocamentoPulo = novoDeslocamento;
	}
	else {
		// Finalização do pulo
		setSofreGravidade(true);
	}
}

// Executando o mover, e futuros eventos relacionados ao jogador
void Jogador::executar() {
	mover();
}

// Implementar depois
void Jogador::salvar() {

}

void Jogador::setVelocidade(float v) {velocidade = v;}

void Jogador::setPisandoPoca(const bool pP) { pisandoPoca = pP; }

void Jogador::setPodePular(const bool pP) { podePular = pP; }
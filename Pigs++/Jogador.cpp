#include "Jogador.h"

using namespace PigsCpp::Entidades::Personagens;


Jogador::Jogador(const bool ehJ1) :
	Personagem(3.0f, 1),
	pontos(0),
	alturaMaximaPulo(140.0f),
	deslocamentoPulo(0.f),
	relogioPulo(),
	estaPulando(false),
	podePular(true),
	pisandoPoca(false),
	ehJogador1(ehJ1),
	direcaoMartelo(1.0f)

{
	// Colocando cor só pra ver o jogador

	if (ehJogador1) { corpo.setFillColor(Color::Green); }
	else { corpo.setFillColor(Color::Red); }
	
};
Jogador::Jogador() :
	Personagem(3.0f, 1),
	pontos(0),
	alturaMaximaPulo(140.0f),
	deslocamentoPulo(0.f),
	relogioPulo(),
	estaPulando(false),
	podePular(true),
	pisandoPoca(false),
	ehJogador1(true), 
	direcaoMartelo(1.0f) 

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
		if (spdX > 0) direcaoMartelo = 1.f;
		else if (spdX < 0) direcaoMartelo = -1.f;
	}
}

// Redefinição do método mover de personagem!
void Jogador::mover() {

	
	if (pisandoPoca) { velocidade = 2.0f; }
	else { velocidade = 3.0f; }

	static bool pressionouAtaque = false;

	
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
		if (isKeyPressed(Key::Space)) {
			if (!pressionouAtaque) {
				Martelo* martelo = usarMartelo(8.0f);
				// Adicione o martelo à sua lista de entidades global aqui!
				// Exemplo: listaEntidades->listaEntidades.inserir(martelo);
				pressionouAtaque = true;
			}
		}
		else {
			pressionouAtaque = false;
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
		if (isKeyPressed(Key::Enter)) {
			if (!pressionouAtaque) {
				Martelo* martelo = usarMartelo(8.0f);
				// Adicione o martelo à sua lista de entidades global aqui!
				pressionouAtaque = true;
			}
		}
		else {
			pressionouAtaque = false;
		}

		if (podePular == false) { atualizarPulo(); }
		
	}
	

	
}

void Jogador::iniciarPulo() {
	podePular = false;
	estaPulando = true;
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

		// Detecta quando começa a descer (atingiu altura máxima)
		if (novoDeslocamento < deslocamentoPulo) {
			setSofreGravidade(true);
		}
		deslocamentoPulo = novoDeslocamento;
	}
	else {
		// Finalização do pulo
		estaPulando = false;
		setSofreGravidade(true);
		podePular = true;
	}
}
Martelo* Jogador::usarMartelo(float velocidade) {
	sf::Vector2f origem = corpo.getPosition();
	sf::Vector2f direcao(direcaoMartelo, 0.f); // horizontal
	return new Martelo(origem.x, origem.y, velocidade, direcao);
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
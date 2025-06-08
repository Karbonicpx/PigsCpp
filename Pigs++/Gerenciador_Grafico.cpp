#include "Gerenciador_Grafico.h"

using namespace PigsCpp::Gerenciadores;
using namespace sf;

// Inicializa o ponteiro estático com null
Gerenciador_Grafico* Gerenciador_Grafico::instancia(nullptr);

Gerenciador_Grafico::Gerenciador_Grafico() {

	// Criando a janela onde vai aparecer o jogo, tamanho 800, 600
	janela = new RenderWindow(VideoMode(Vector2u{ 800, 600 }), "PigsCpp");
	// janela->setFramerateLimit(60); // Limitando os frames por segundo 
	corpo.setPosition(Vector2f(0, 0)); // Definindo a posição inicial do corpo
};


Gerenciador_Grafico::~Gerenciador_Grafico() {
	
};

// Retornando instancia estática
Gerenciador_Grafico* Gerenciador_Grafico::getInstancia(){
	if (instancia == nullptr) {
		instancia = new Gerenciador_Grafico();
	}
	return instancia;
}

// Deletando instancia estática
void Gerenciador_Grafico::destruirInstancia() {
	if (instancia != nullptr) {
		delete instancia;
		instancia = nullptr;
	}
}


// Código para facilitar o retorno da janela
RenderWindow* Gerenciador_Grafico::getWindow() const
{
	return janela;
}

void Gerenciador_Grafico::setCorpo(RectangleShape c) {
	corpo = c;
}

// Verifica se a janela está aberta
const bool Gerenciador_Grafico::estaAberta() const {
	return janela->isOpen();
}

// Faz a janela mostrar as entidades que foram desenhadas
void Gerenciador_Grafico::mostrar() {
	janela->display();
}


// Desenha o corpo (RectangleShape, sem textura)
void Gerenciador_Grafico::desenhar() {
	janela->draw(corpo);
}

// Desenha a textura do corpo
void Gerenciador_Grafico::desenhar(const Texture* textura) {
	corpo.setTexture(textura); // Define a textura do corpo
}

// Limpa a janela
void Gerenciador_Grafico::clear() {
	janela->clear();
}

// Fechar a janela (Literalmente fecha o jogo)
void Gerenciador_Grafico::fechar() {
	janela->close();
}
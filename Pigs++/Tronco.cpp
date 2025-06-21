#include "Tronco.h"

using namespace PigsCpp::Entidades;
                                                // 5 - 10
Tronco::Tronco():Obstaculo(true, false), altura((rand() % 5) + 5){
    corpo.setFillColor(sf::Color::Yellow);
}
Tronco::~Tronco() {

}
void Tronco::executar() {

}
void Tronco::obstaculizar(Jogador* p) {
    
    sf::Vector2f posTronco = corpo.getPosition();

    // Altura influencia diretamente no tamanho do tronco
    sf::Vector2f tamTronco = sf::Vector2f(corpo.getSize().x, corpo.getSize().y - altura);

    sf::Vector2f posJogador = p->getCorpo().getPosition();
    sf::Vector2f tamJogador = p->getCorpo().getSize();

    float jogadorBase = posJogador.y + tamJogador.y;
    float troncoTopo = posTronco.y;

    if (jogadorBase > troncoTopo && posJogador.y < troncoTopo) {
        // Posiciona o jogador em cima do tronco
        p->setPos(posJogador.x, troncoTopo - tamJogador.y);

		// Permite que o jogador pule novamente
		p->setPodePular(true);

    }
    else if (posJogador.x + tamJogador.x > posTronco.x && posJogador.x < posTronco.x) {
        // Colisão pela esquerda
        p->setPos(posTronco.x - tamJogador.x, posJogador.y);
    }
    else if (posJogador.x < posTronco.x + tamTronco.x && posJogador.x > posTronco.x) {
        // Colisão pela direita
        p->setPos(posTronco.x + tamTronco.x, posJogador.y);
    }
    
}
void Tronco::salvar() {

}
void Tronco::salvarDataBuffer() {

}
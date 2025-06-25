#include "Tronco.h"

using namespace PigsCpp::Entidades;
                                                
Tronco::Tronco():
    Obstaculo("textures/Tronco.png", 64.0f, 64.0f, false),
    altura((rand() % 5) + 5)  // 5 - 10

{ 
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

// Mesma coisa que obstaculizar, porém para inimigos
void Tronco::obstaculizarIni(Inimigo* ini) {
    sf::Vector2f posTronco = corpo.getPosition();

    // Altura influencia diretamente no tamanho do tronco
    sf::Vector2f tamTronco = sf::Vector2f(corpo.getSize().x, corpo.getSize().y - altura);

    sf::Vector2f posInimigo = ini->getCorpo().getPosition();
    sf::Vector2f tamInimigo = ini->getCorpo().getSize();

    float jogadorBase = posInimigo.y + tamInimigo.y;
    float troncoTopo = posTronco.y;

    if (jogadorBase > troncoTopo && posInimigo.y < troncoTopo) {
        // Posiciona o jogador em cima do tronco
        ini->setPos(posInimigo.x, troncoTopo - tamInimigo.y);

    }
    else if (posInimigo.x + tamInimigo.x > posTronco.x && posInimigo.x < posTronco.x) {
        

        if (dynamic_cast<Leitao*>(ini) != nullptr) 
        { 
            ini->inverterDir();
            dynamic_cast<Leitao*>(ini)->setRaio(dynamic_cast<Leitao*>(ini)->getRaio() + 1.f);
        }
        // Colisão pela esquerda
        ini->setPos(posTronco.x - tamInimigo.x, posInimigo.y);
    }
    else if (posInimigo.x < posTronco.x + tamTronco.x && posInimigo.x > posTronco.x) {
        

        if (dynamic_cast<Leitao*>(ini) != nullptr)
        {
            ini->inverterDir();
            dynamic_cast<Leitao*>(ini)->setRaio(dynamic_cast<Leitao*>(ini)->getRaio() + 1.f);
        }

        // Colisão pela direita
        ini->setPos(posTronco.x + tamTronco.x, posInimigo.y);
    }
}

void Tronco::salvar(std::ofstream& arq) {
    arq << "TRONCO ";
    salvarDataBuffer(arq);  // salva x, y e danoso
    arq << altura << std::endl;
}
void Tronco::salvarDataBuffer(std::ofstream& arq) {
    Obstaculo::salvarDataBuffer(arq);
}
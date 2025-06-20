#include "Floresta.h"


using namespace PigsCpp::Fases;



Floresta::Floresta():
	Fase("fasesjson/Floresta.json"),
	maxInimMedios(2)
{

}

Floresta::~Floresta() {

}


void Floresta::criarTouc() {
	ent = static_cast<Entidade*>(new Toucinho());
}

void Floresta::criarLago() {
	ent = static_cast<Entidade*>(new Lago());
}

// Precisamos fazer uma criação diferente, pois a posição do tronco é só uma no tilemap, na qual vai criar outros 3
// Pois seu sprite é 64x64
void Floresta::criarTronco(sf::Vector2f pos) {
    sf::Vector2f offsets[4] = {
        {0, 0},                       // Base
        {spriteSize, 0},              // Direita
        {0, -spriteSize},             // Cima
        {spriteSize, -spriteSize}     // Canto superior direito
    };

    for (int i = 0; i < 4; i++) {
        Entidade* tronco = static_cast<Entidade*>(new Tronco());

        if (i != 0) {
            dynamic_cast<Tronco*>(tronco)->setSpriteVisivel(false);
        }

        inicializarEntidades(tronco, pos.x + offsets[i].x, pos.y + offsets[i].y, spriteSize);
    }
}


void Floresta::criarInimigos() {
	criarLeitao();
	criarTouc();
}


void Floresta::criarObstaculo() {
	criarLago();
    // criarTronco();
}


// Método que vai criar as entidades na posição obtida dos tiles da camada "Entidades" na fase
void Floresta::criarEntidades(Gerenciador_Grafico* GG) {

    for (unsigned int i = 0; i < posicoesEntidades.size(); i++) {
        int tileId = posicoesEntidades[i].first;
        sf::Vector2f pos = posicoesEntidades[i].second;

        ent = nullptr;

        switch (tileId) {
        case 73: // Plataforma lógica (apenas colisão, não desenha)
            criarBloco();

            break;
		case 74: // Lago (obstáculo)
            criarLago();
            break;

        case 76: // Leitao (inimigo fácil)
            criarLeitao();
            break;

        case 77: // Touc (inimigo médio)
            criarTouc();
            break;

        case 79: // Jogador(es)
            criarJogador(pos.x, pos.y, spriteSize);
            break;

		case 80: // Tronco (obstáculo sem dano)
            criarTronco(pos);
            break;
            

        default:
            break;
        }

        inicializarEntidades(ent, pos.x, pos.y, spriteSize);
    }
}

#include "Floresta.h"


using namespace PigsCpp::Fases;



Floresta::Floresta() :              // 10 - 15         // 3 - 6
    Fase("fasesjson/Floresta.json", (rand() % 5) + 10, (rand() % 4) + 3),
    maxToucinhos((rand() % 3) + 3), // 0, 1, 2 no rand, e com + 3 fica 3, 4, 5
    maxTroncos((rand() % 3) + 3) // 0, 1, 2 no rand, e com + 3 fica 3, 4, 5
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
        {32.0f, 0},              // Direita
        {0, -32.0f},             // Cima
        {32.0f, -32.0f}     // Canto superior direito
    };

    for (int i = 0; i < 4; i++) {
        Entidade* tronco = static_cast<Entidade*>(new Tronco());

        if (i == 0) {
            dynamic_cast<Tronco*>(tronco)->setSpriteVisivel(true);
        }
        else {
            dynamic_cast<Tronco*>(tronco)->setSpriteVisivel(true);
        }

        inicializarEntidades(tronco, pos.x + offsets[i].x, pos.y + offsets[i].y);
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

    int maxToucCounter = 0;
    int maxTroncoCounter = 0;
    int maxLagoCounter = 0;
    int maxLeitaoCounter = 0;

    for (unsigned int i = 0; i < posicoesEntidades.size(); i++) {
        int tileId = posicoesEntidades[i].first; // Pegando a lista dos tile IDS
        sf::Vector2f pos = posicoesEntidades[i].second; // Pegando a posição das entidades

        ent = nullptr;

        switch (tileId) {
        case 73: // Plataforma lógica (apenas colisão, não desenha)
            criarBloco();

            break;
		case 74: // Lago (obstáculo)

            if (maxLagoCounter >= maxLagos) {
                break;
            }
            criarLago();
            maxLagoCounter++;
            break;

        case 76: // Leitao (inimigo fácil)

            if (maxLeitaoCounter >= maxLeitaos) {
                break;
            }
            criarLeitao();
            maxLeitaoCounter++;
            break;

        case 77: // Touc (inimigo médio)

            if (maxToucCounter >= maxToucinhos) {
                break;
            }
            criarTouc();
            maxToucCounter++;
            break;

        case 79: // Jogador(es)
            criarJogador(pos.x, pos.y);
            break;

		case 80: // Tronco (obstáculo sem dano)
            if (maxTroncoCounter >= maxTroncos) {
                break;
            }
            criarTronco(pos);
            maxTroncoCounter++;
            break;
            

        default:
            break;
        }

        inicializarEntidades(ent, pos.x, pos.y);
    }
}

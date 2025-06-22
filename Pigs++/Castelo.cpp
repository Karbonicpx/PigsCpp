#include "Castelo.h"

using namespace PigsCpp::Fases;

Castelo::Castelo():                 // 8 - 18          // 4 - 7
	Fase("fasesjson/Castelo.json", (rand() % 9) + 10, (rand() % 5) + 3),
    maxEspinhos((rand() % 20) + 10), // 0, 1, 2 ... 20 no rand, + 10 - 10, 11 ... 30  
    maxBaconzillas((rand() % 4) + 1)  // 0, 1, 2, 3 no rand, + 1 - 1, 2, 3, 4
{
  
}

Castelo::~Castelo() {

}



void Castelo::criarLago() {
	ent = static_cast<Entidade*>(new Lago());
}

void Castelo::criarEspinho() {
	ent = static_cast<Entidade*>(new Espinho());
}

void Castelo::criarZilla() {
    ent = static_cast<Entidade*>(new Baconzilla());
}

// Provável que não utilize isso, já que as bombas são criadas a partir de Bancozilla/Toucinho
void Castelo::criarProjeteis() {
    ent = static_cast<Entidade*>(new Bomba());
}

void Castelo::criarInimigos() {
	criarZilla();
	criarLeitao();
}


void Castelo::criarObstaculo() {
	criarLago();
	criarEspinho();
}

void Castelo::criarEntidades(Gerenciador_Grafico* GG) {
    
    int maxZillaCounter = 0;
    int maxEspinhoCounter = 0;
    int maxLeitaoCounter = 0;
    int maxLagoCounter = 0;

    for (unsigned int i = 0; i < posicoesEntidades.size(); i++) {
        int tileId = posicoesEntidades[i].first;
        sf::Vector2f pos = posicoesEntidades[i].second;

        switch (tileId) {
        case 274: // Plataforma lógica (só cria a entidade, não o visual)
            criarBloco();
            break;

        case 275: // Lago
            if (maxLagoCounter >= maxLagos) {
                break;
            }
            criarLago();
            maxLagoCounter++;
            break;

        case 276: // Espinho
            if (maxEspinhoCounter >= maxEspinhos) {
                break;
            }
            criarEspinho();
            maxEspinhoCounter++;
            break;

        case 277: // Leitao (inimigo fácil)
            if (maxLeitaoCounter >= maxLeitaos) {
                break;
            }
            criarLeitao();
            maxLeitaoCounter++;
            break;

        case 279: // Baconzilla (chefe)

            if (maxZillaCounter >= maxBaconzillas) {
                break;
            }
            criarZilla();
            maxZillaCounter++;
            break;

        case 280: // Jogador
            criarJogador(pos.x, pos.y);
            break;

        default:
            break;
        }

        inicializarEntidades(ent, pos.x, pos.y);
    }
}
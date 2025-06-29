#include "Subterraneo.h"

using namespace PigsCpp::Fases;

Subterraneo::Subterraneo():                 // 14 - 21          // 3 - 5
	Fase("fasesjson/Subterraneo.json", (rand() % 8) + 14, (rand() % 3) + 3),
    maxEspinhos((rand() % 11) + 11), // 0, 1, 2 ... 20 no rand, + 10 - 10, 11 ... 30  
    maxBaconzillas((rand() % 2) + 3)  // 0 e 1 no rand, vira 3 e 4
{
  
}

Subterraneo::~Subterraneo() {

}



void Subterraneo::criarLago() {
	ent = dynamic_cast<Entidade*>(new Lago());
}

void Subterraneo::criarEspinho() {
	ent = dynamic_cast<Entidade*>(new Espinho());
}

void Subterraneo::criarZilla() {

    ent = dynamic_cast<Entidade*>(new Baconzilla(getListaEntidades()));
}

// Provável que não utilize isso, já que as bombas são criadas a partir de Baconzilla/Toucinho
void Subterraneo::criarProjeteis() {
    // ent = dynamic_cast<Entidade*>(new Projetil());
}

void Subterraneo::criarInimigos() {
	criarZilla();
	criarLeitao();
}


void Subterraneo::criarObstaculo() {
	criarLago();
	criarEspinho();
}

void Subterraneo::criarEntidades(Gerenciador_Grafico* GG) {
    
    int maxZillaCounter = 0;
    int maxEspinhoCounter = 0;
    int maxLeitaoCounter = 0;
    int maxLagoCounter = 0;

    for (unsigned int i = 0; i < posicoesEntidades.size(); i++) {
        int tileId = posicoesEntidades[i].first;
        sf::Vector2f pos = posicoesEntidades[i].second;

        switch (tileId) {
        case 73: // Plataforma lógica (só cria a entidade, não o visual)
            criarBloco();
            break;

        case 74: // Lago
            if (maxLagoCounter >= maxLagos) {
                break;
            }
            criarLago();
            maxLagoCounter++;
            break;

        case 75: // Espinho
            if (maxEspinhoCounter >= maxEspinhos) {
                break;
            }
            criarEspinho();
            maxEspinhoCounter++;
            break;

        case 76: // Leitao (inimigo fácil)
            if (maxLeitaoCounter >= maxLeitaos) {
                break;
            }
            criarLeitao();
            maxLeitaoCounter++;
            break;

        case 78: // Baconzilla (chefe)

            if (maxZillaCounter >= maxBaconzillas) {
                break;
            }

            criarZilla();
            maxZillaCounter++;
            break;

        case 79: // Jogador
            criarJogador(pos.x, pos.y);
            break;

        case 81:
            criarPorta(-1);
            break;
        default:
            break;
        }

        inicializarEntidades(ent, pos.x, pos.y);
    }
}
#include "Castelo.h"

using namespace PigsCpp::Fases;

Castelo::Castelo():
	Fase("fasesjson/Castelo.json"),
	maxChefoes(1)
{

}

Castelo::~Castelo() {

}



void Castelo::criarLago() {
	// ent = static_cast<Entidade*>(new Lago());
}

void Castelo::criarEspinho() {
	// ent = static_cast<Entidade*>(new Espinho());
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
    

    for (unsigned int i = 0; i < posicoesEntidades.size(); i++) {
        int tileId = posicoesEntidades[i].first;
        sf::Vector2f pos = posicoesEntidades[i].second;

        switch (tileId) {
        case 274: // Plataforma lógica (só cria a entidade, não o visual)
      
            break;

        case 276: // Lago
            criarLago();
            break;

        case 277: // Leitao (inimigo fácil)
            criarLeitao();
            break;

        case 279: // Baconzilla (chefe)
            criarZilla();
            break;

        case 280: // Jogador
            criarJogador();
            break;

        case 282: // Espinho
            criarEspinho();
            break;

        default:
            break;
        }

        inicializarEntidades(ent, pos.x, pos.y, spriteSize);
    }
}
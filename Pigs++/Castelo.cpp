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
	// ent = new Lago();
}

void Castelo::criarEspinho() {
	// ent = new Espinho();
}

void Castelo::criarChefoes() {

}

void Castelo::criarProjeteis() {

}

void Castelo::criarInimigos() {
	criarTouc();
	criarChefoes();
}


void Castelo::criarObstaculo() {
	criarLago();
	criarEspinho();
}

void Castelo::criarEntidades(Gerenciador_Grafico* GG) {
    const float tamanho = 32.0f;

    for (unsigned int i = 0; i < posicoesEntidades.size(); i++) {
        int tileId = posicoesEntidades[i].first;
        sf::Vector2f pos = posicoesEntidades[i].second;

        switch (tileId) {
        case 274: // Plataforma lógica (não cria entidade visual)
      
            break;

        case 276: // Lago
            criarLago();
            break;

        case 277: // Toucinho (inimigo fácil)
            criarTouc();
            break;

        case 279: // Leitao (inimigo médio)
            criarChefoes();
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

        if (ent != nullptr) {
            ent->setPos(pos.x, pos.y);
            ent->setTamanho(tamanho, tamanho);
            getListaEntidades()->listaEntidades.incluir(ent);
            ent = nullptr;
        }
    }
}
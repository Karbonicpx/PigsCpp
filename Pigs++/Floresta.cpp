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
	// ent = static_cast<Entidade*>(new Lago());
}

void Floresta::criarTronco() {
	// ent = static_cast<Entidade*>(new Tronco());
}


void Floresta::criarInimigos() {
	criarLeitao();
	criarTouc();
}


void Floresta::criarObstaculo() {
	criarLago();
    criarTronco();
}


// Método que vai criar as entidades na posição obtida dos tiles da camada "Entidades" na fase
void Floresta::criarEntidades(Gerenciador_Grafico* GG) {

    for (unsigned int i = 0; i < posicoesEntidades.size(); i++) {
        int tileId = posicoesEntidades[i].first;
        sf::Vector2f pos = posicoesEntidades[i].second;

        ent = nullptr;

        switch (tileId) {
        case 73: // Plataforma lógica (apenas colisão, não desenha)
            

            break;
		case 74: // Lago (obstáculo)
            criarLago();
            break;

        case 76: // Toucinho (inimigo fácil)
            criarTouc();
            break;

        case 77: // Leitao (inimigo médio)
            criarLeitao();
            break;

        case 79: // Jogador(es)
            criarJogador();
            break;

		case 80: // Tronco (obstáculo)
            criarTronco();
            break;
            

        default:
            break;
        }

        inicializarEntidades(ent, pos.x, pos.y, spriteSize);
    }
}

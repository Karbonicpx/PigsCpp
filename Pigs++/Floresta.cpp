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


// M�todo que vai criar as entidades na posi��o obtida dos tiles da camada "Entidades" na fase
void Floresta::criarEntidades(Gerenciador_Grafico* GG) {

    for (unsigned int i = 0; i < posicoesEntidades.size(); i++) {
        int tileId = posicoesEntidades[i].first;
        sf::Vector2f pos = posicoesEntidades[i].second;

        ent = nullptr;

        switch (tileId) {
        case 73: // Plataforma l�gica (apenas colis�o, n�o desenha)
            

            break;
		case 74: // Lago (obst�culo)
            criarLago();
            break;

        case 76: // Toucinho (inimigo f�cil)
            criarTouc();
            break;

        case 77: // Leitao (inimigo m�dio)
            criarLeitao();
            break;

        case 79: // Jogador(es)
            criarJogador();
            break;

		case 80: // Tronco (obst�culo)
            criarTronco();
            break;
            

        default:
            break;
        }

        inicializarEntidades(ent, pos.x, pos.y, spriteSize);
    }
}

#include "Floresta.h"


using namespace PigsCpp::Fases;



Floresta::Floresta():
	Fase("fasesjson/Floresta.json"),
	maxInimMedios(2)
{

}

Floresta::~Floresta() {

}


void Floresta::criarLeitao() {
	ent = static_cast<Entidade*>(new Leitao());
}

void Floresta::criarLago() {
	// ent = new Lago();
}

void Floresta::criarTronco() {
	// ent = new Tronco();
}


void Floresta::criarInimigos() {
	criarLeitao();
	criarTouc();
}


void Floresta::criarObstaculo() {
	criarLago();
}


void Floresta::criarEntidades(Gerenciador_Grafico* GG) {
    const float tamanho = 32.0f;

    for (unsigned int i = 0; i < posicoesEntidades.size(); i++) {
        int tileId = posicoesEntidades[i].first;
        sf::Vector2f pos = posicoesEntidades[i].second;

        ent = nullptr;

        switch (tileId) {
        case 73: // Plataforma lógica (colisão, não desenha)
            // Pode usar para colisão, ou ignorar se já trata no tilemap
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

        case 79: // Jogador
            criarJogador();
            break;

		case 80: // Tronco (obstáculo)
            criarTronco();
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

#include "Floresta.h"


using namespace PigsCpp::Fases;

Floresta::Floresta(Jogador* pJ) :
	Fase(pJ, "fasesjson/Floresta.json"),
	maxInimMedios(2)
{

}
Floresta::Floresta(Jogador* pJ1, Jogador* pJ2):
	Fase(pJ1, pJ2, "fasesjson/Floresta.json"),
	maxInimMedios(2)

{

}

Floresta::Floresta():
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

void Floresta::criarInimigos() {
	criarLeitao();
	criarTouc();
}


void Floresta::criarObstaculo() {
	criarLago();
}


void Floresta::criarEntidades(Gerenciador_Grafico* GG) {


	for (unsigned int i = 0; i < posicoesEntidades.size(); i++) {
		int tileId = posicoesEntidades[i].first;
		sf::Vector2f pos = posicoesEntidades[i].second;
		float tamanho = 32.0f; // Tamanho padrão das entidades	

		

		switch (tileId) {
		case 67: // Plataforma
			
			break;



		case 70: // Toucinho (inimigo fácil)
			ent = static_cast<Entidade*>(new Toucinho());

			break;

		case 71: // Leitao (inimigo médio)
			ent = static_cast<Entidade*>(new Leitao());

			break;

		case 72: // Obstáculo
			// ent = new Obstaculo();
			break;

		case 73: // Jogador
			if (j1 != nullptr && j2 == nullptr) {

				ent = static_cast<Entidade*>(j1);

			}
			else {

				ent = static_cast<Entidade*>(j1);
				ent = static_cast<Entidade*>(j2);

			}
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
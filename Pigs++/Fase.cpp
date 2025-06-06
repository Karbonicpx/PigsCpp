#include "Fase.h"

using namespace PigsCpp::Fases;

// 2 tipos de construtores: Um quando for apenas um jogador, e um quando for 2
Fase::Fase(Jogador* pJ):
	j2(nullptr)
{

	this->j1 = pJ;
	GC = new Gerenciador_Colisao();
	LEs = new ListaEntidades();
	LEs->listaEntidades.incluir(j1);
};

Fase::Fase(Jogador* pJ1, Jogador* pJ2) {

	this->j1 = pJ1;
	this->j2 = pJ1;
	GC = new Gerenciador_Colisao();
	LEs = new ListaEntidades();
	LEs->listaEntidades.incluir(j1);
	LEs->listaEntidades.incluir(j2);
};

Fase::~Fase() {

	LEs->listaEntidades.limpar();
	j1 = nullptr;
	j2 = nullptr;
	delete(LEs);
	delete(GC);
};

ListaEntidades* Fase::getListaEntidades() const {
	return LEs;
}


// Fazer depois
const void Fase::gerenciarColisoes() {

}

// Fazer depois
const void Fase::criarTouc() {

}

// Fazer depois
const void Fase::criarPlataformas() {

}

// Fazer depois
const void Fase::criarCenario() {

}


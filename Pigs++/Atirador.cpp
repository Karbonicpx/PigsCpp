#include "Atirador.h"


using namespace PigsCpp::Entidades::Personagens;


Atirador::Atirador(const float tempoPrj, ListaEntidades* lista) :
	tempoProjetil(tempoPrj),
	listaEntidades(lista),
	tempoCounter(0)
{

}

Atirador::~Atirador() {
	listaEntidades = nullptr;
}

void Atirador::projetilRecarga() {
	tempoCounter++;
	if (tempoCounter >= tempoProjetil) {
		atirarProjetil();
		tempoCounter = 0;
	}
}

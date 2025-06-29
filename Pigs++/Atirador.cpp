#include "Atirador.h"


using namespace PigsCpp::Entidades::Personagens;


<<<<<<< Updated upstream
Atirador::Atirador(const float tempoPrj, ListaEntidades* lista): 
=======
Atirador::Atirador(const float tempoPrj, ListaEntidades* lista) :
>>>>>>> Stashed changes
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

#pragma once
#include "ListaEntidades.h"

// Classe para cumprir o conceito de multiherança
namespace PigsCpp::Entidades::Personagens {
	class Atirador
	{
	protected:
		ListaEntidades* listaEntidades;
		float tempoProjetil;
		float tempoCounter;
		virtual void atirarProjetil() = 0;
		void projetilRecarga();

	public:
		Atirador(const float tempoPrj, ListaEntidades* lista);
		~Atirador();
	};
}



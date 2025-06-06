#pragma once
#include "Entidade.h"
#include "Lista.h"

using namespace PigsCpp::Listas;
using namespace PigsCpp::Entidades;

// LEIA!
// OBS: Todos os créditos ao desenvolvedor do código desse arquivo, Felipe Alvez Barboza,
// retirado através de um tutorial de uma playlist feita pelo mesmo, no canal "Dev Felipe", 
// ensinando a como desenvolver uma lista template.

namespace PigsCpp {

	namespace Listas {

		// Essa classe vai servir apenas para criar listas de entidades independentes umas das outras
		class ListaEntidades
		{

		public:
			Lista<Entidade> listaEntidades;

		};
	};
};



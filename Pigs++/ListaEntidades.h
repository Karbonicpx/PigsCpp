#pragma once
#include "Entidade.h"
#include "Lista.h"

using namespace PigsCpp::Listas;
using namespace PigsCpp::Entidades;

namespace PigsCpp {

	namespace Listas {

		// Essa classe vai servir apenas para criar instâncias de listas de entidades independentes umas das outras
		class ListaEntidades
		{

		public:
			Lista<Entidade> listaEntidades;

		};
	};
};


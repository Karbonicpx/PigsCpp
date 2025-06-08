#pragma once
#include "Entidade.h"
#include "Jogador.h"
#include <SFML/Graphics.hpp>

using namespace Personagens;
using namespace PigsCpp;
using namespace Entidades;

namespace PigsCpp {

	namespace Entidades {

		class Obstaculo : public Entidade {

		private:
			bool danoso;

		public:
			Obstaculo();
			virtual ~Obstaculo();
			void salvarDataBuffer();
			virtual void executar() = 0;
			virtual void salvar() = 0;
			virtual void obstaculizar(Jogador* p) = 0;
			void setDanoso(bool dano);
			bool getDanoso() const;
		};
	};
};
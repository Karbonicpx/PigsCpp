#pragma once
#include "Obstaculo.h"

namespace PigsCpp {

	namespace Entidades {

		class Espinho : public Obstaculo {

		private:
			short int danosidade;

		public:
			Espinho();
			~Espinho();
			void executar();
			void obstaculizar(Jogador* p);
			void salvar();
			void salvarDataBuffer();
		};
	};
};
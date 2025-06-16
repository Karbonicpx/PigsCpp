#pragma once
#include "Obstaculo.h"

namespace PigsCpp {

	namespace Entidades {

		class Lago : public Obstaculo {

		private:
			int largura;

		public:
			Lago();
			~Lago();
			void executar();
			void obstaculizar(Jogador* p);
			void salvar();
			void salvarDataBuffer();
		};
	};
};
#pragma once
#include "Obstaculo.h"

namespace PigsCpp {
	namespace Entidades {
		class Tronco : public Obstaculo {
		private:
			int altura;
		public:
			Tronco();
			~Tronco();
			void executar();
			void obstaculizar(Jogador* p);
			void salvar();
			void salvarDataBuffer();
		};
	};
};
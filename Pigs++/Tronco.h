#pragma once
#include "Obstaculo.h"
#include "Inimigo.h"
#include "Leitao.h"

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
			void obstaculizarIni(Inimigo* ini);
			void salvar(std::ofstream& arq);
			void salvarDataBuffer();
		};
	};
};
#pragma once
#include "Fase.h"

namespace PigsCpp {
	namespace Fases {

		// Fase 1
		class Floresta : public Fase {

		private:

			const int maxInimMedios;
			

		public:
			Floresta();
			~Floresta();

			void criarLeitao();
			void criarLago();
			void criarTronco();

			void criarInimigos();
			void criarPlataformas();
			void criarObstaculo();
			void criarEntidades(Gerenciador_Grafico* GG);
			
		};

	}
}


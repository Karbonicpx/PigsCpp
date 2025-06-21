#pragma once
#include "Fase.h"

namespace PigsCpp {
	namespace Fases {

		// Fase 1
		class Floresta : public Fase {

		private:

			const int maxToucinhos;
			const int maxTroncos;	

		public:
			Floresta();
			~Floresta();

			void criarTouc();
			void criarLago();
			void criarTronco(sf::Vector2f pos);

			void criarInimigos();
			void criarPlataformas();
			void criarObstaculo();
			void criarEntidades(Gerenciador_Grafico* GG);

			
			
		};

	}
}


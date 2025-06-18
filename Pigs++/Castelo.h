#pragma once
#include "Fase.h"
#include "Baconzilla.h"


namespace PigsCpp {

	namespace Fases {
		class Castelo : public Fase {


		private:
			const int maxChefoes;
		public:
			Castelo();
			~Castelo();

			void criarZilla();
			void criarProjeteis();
			void criarLago();

			void criarEspinho();
			void criarInimigos();
			void criarPlataformas();
			void criarObstaculo();
			void criarEntidades(Gerenciador_Grafico* GG);
			
		};

	}
}


#pragma once
#include "Fase.h"

namespace PigsCpp {

	namespace Fases {
		class Castelo : public Fase {


		private:
			const int maxChefoes;
		public:
			void criarChefoes();
			void criarObstMedios();
			void criarProjeteis();
		};

	}
}


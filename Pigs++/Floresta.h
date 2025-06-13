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
			void criarInimMedios();
			void criarObstMedios();
			
		};

	}
}


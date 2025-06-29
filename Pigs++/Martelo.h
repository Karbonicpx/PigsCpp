#pragma once
#include "Projetil.h"

namespace PigsCpp {
	namespace Entidades {
		class Martelo : public Projetil {
		private:

			float velocidadeGiro;

		public:
			Martelo(float x, float y, sf::Vector2f vel);
			~Martelo();
			void mover();
			void executar();
			void salvar(std::ofstream& arq);

		};
	};
};

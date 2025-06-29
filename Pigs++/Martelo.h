<<<<<<< Updated upstream
#pragma
#include "Projetil.h"
#include <SFML/Graphics.hpp>
=======
#pragma once
#include "Projetil.h"
>>>>>>> Stashed changes

namespace PigsCpp {
	namespace Entidades {
		class Martelo : public Projetil {
		private:
<<<<<<< Updated upstream
			
=======

>>>>>>> Stashed changes
			float velocidadeGiro;

		public:
			Martelo(float x, float y, sf::Vector2f vel);
			~Martelo();
			void mover();
			void executar();
			void salvar(std::ofstream& arq);
<<<<<<< Updated upstream
			
=======

>>>>>>> Stashed changes
		};
	};
};

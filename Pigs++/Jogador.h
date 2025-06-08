#pragma once
#include "Personagem.h"

namespace PigsCpp {
	namespace Entidades {
		namespace Personagens {
			class Jogador : public Personagem
			{
			protected:

				int pontos;
				void apertarTecla(sf::Keyboard::Key tecla, float spdX, float spdY);
			public:

				Jogador();
				~Jogador();
				void mover();
				void executar();
				void salvar();

			};
		}
	}
}


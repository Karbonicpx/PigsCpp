#pragma once
#include "Personagem.h"

namespace PigsCpp {
	namespace Entidades {
		namespace Personagens {
			class Jogador : public Personagem
			{
			private:

				int pontos;
				const void apertarTecla(sf::Keyboard::Key tecla, float spdX, float spdY);
			public:

				Jogador();
				~Jogador();
				const void mover();
				const void executar();
				const void salvar();

			};
		}
	}
}


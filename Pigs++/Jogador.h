#pragma once
#include "Personagem.h"
#include <SFML/Graphics.hpp>
namespace PigsCpp {
	namespace Entidades {

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


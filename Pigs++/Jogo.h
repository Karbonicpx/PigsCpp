#pragma once

#include <SFML/Graphics.hpp>
#include "Jogador.h"

// Namespace principal do projeto
namespace PigsCpp {

	class Jogo
	{
		private:
		sf::RenderWindow window;
		Jogador jogador1;

		public:
		Jogo();
		~Jogo();
		const void executar();
	};
};



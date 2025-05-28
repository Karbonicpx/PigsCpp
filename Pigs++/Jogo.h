#pragma once

#include <SFML/Graphics.hpp>

// Namespace principal do projeto
namespace PigsCpp {

	class Jogo
	{
		private:
		sf::RenderWindow window;
		sf::RectangleShape shape;

		public:
		Jogo();
		~Jogo();
		const void executar();
	};
};



#pragma once
#include <SFML/Graphics.hpp>

namespace PigsCpp {

	class Ente
	{
		
		protected:
		static int id;
		sf::RectangleShape corpo;
		sf::RenderWindow* janela;

		private:
		const void operator++();

		public:
		Ente();
		~Ente();
		virtual void executar() = 0;
		const void desenhar();
			
	};
	int Ente::id(0);
};


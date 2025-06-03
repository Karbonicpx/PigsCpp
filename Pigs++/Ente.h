#pragma once
#include <SFML/Graphics.hpp>

// Classe mais abstrata das entidades no projeto, onde vai ter as fun��es de:
// Registrar id, acessar o endere�o da janela, definir o body das entidades assim como desenhalas
// OBS: Esse namespace vai estar em todo o projeto
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
		const int getId() const;
		const sf::RectangleShape getCorpo() const;
		const virtual void executar() = 0;
		const void desenhar();
		const void setJanela(sf::RenderWindow* j);
		
			
	};
};


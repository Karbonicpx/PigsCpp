#pragma once
#include <SFML/Graphics.hpp>

// Classe mais abstrata das entidades no projeto, onde vai ter as funções de:
// Registrar id, acessar o endereço da janela, definir o body das entidades assim como desenhalas
// OBS: Esse namespace vai estar em todo o projeto
namespace PigsCpp {

	using namespace sf;
	class Ente
	{
		
	protected:
		static int id;
		RectangleShape corpo;
		RenderWindow* janela;
		

	private:
		const void operator++();

	public:
		Ente();
		~Ente();
		const int getId() const;
		const sf::RectangleShape getCorpo() const;
		const virtual void executar() = 0;
		const int getId() const;
		RectangleShape getCorpo() const;
		const void desenhar();
		const void setJanela(sf::RenderWindow* j);
		
			
	};
};


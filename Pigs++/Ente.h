#pragma once
#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.h"

// Classe mais abstrata das entidades no projeto, onde vai ter as funções de:
// Registrar id, acessar o endereço da janela, definir o body das entidades assim como desenhalas
// OBS: Esse namespace vai estar em todo o projeto

using namespace PigsCpp::Gerenciadores;

namespace PigsCpp {

	using namespace sf;
	class Ente
	{
		
	protected:
		static int id;
		RectangleShape corpo;
		static Gerenciador_Grafico* pGG;
		

	private:
		const void operator++();

	public:
		Ente();
		~Ente();
		const int getId() const;
		const sf::RectangleShape getCorpo() const;
		const virtual void executar() = 0;
		const void desenhar();
		const static void setGG(Gerenciador_Grafico* gg);
		
			
	};
};


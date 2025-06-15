#pragma once
#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.h"

// Classe mais abstrata das entidades no projeto, onde vai ter as fun��es de:
// Registrar id, acessar o endere�o da janela, definir o body das entidades assim como desenhalas
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
		

	public:
		Ente();
		virtual ~Ente();
		const sf::RectangleShape getCorpo() const;
		virtual void executar() = 0;
		static void setGG(Gerenciador_Grafico* gg);
		const int getId() const;
		void desenhar();
		void operator++();
	};
};


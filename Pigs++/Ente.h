#pragma once
#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.h"
#include <cstdlib>
#include <fstream>

// Classe mais abstrata das entidades no projeto, onde vai ter as funções de:
// Registrar id, acessar o endereço da janela, definir o body das entidades assim como desenhalas
// OBS: Esse namespace vai estar em todo o projeto

using namespace PigsCpp::Gerenciadores;

namespace PigsCpp {

	using namespace sf;
	class Ente
	{

	protected:
		int idIndividual; // Id individual de cada entidade
		static int id; // Contador globao
		bool spriteVisivel;
		RectangleShape corpo;
		Texture* textura;

		static Gerenciador_Grafico* pGG;


	public:
		Ente(const std::string texturePath, const float bodyX, const float bodyY, const bool sV);
		Ente();
		virtual ~Ente();
		RectangleShape& getCorpo();
		bool getSpriteVisivel() const;
		const int getId() const;
		virtual void executar() = 0;

		void setSpriteVisivel(const bool sV);
		static void setGG(Gerenciador_Grafico* gg);

		void desenhar();
		void operator++();
		float gerarAleatorioFloat(const float min, const float max);
	};
};
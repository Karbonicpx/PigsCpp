#pragma once

#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "ListaEntidades.h"
#include "Floresta.h"
#include "Castelo.h"
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Colisao.h"

// Namespace e classe principal do projeto
namespace PigsCpp {

	class Jogo
	{
	private:
		Personagens::Jogador* jogador1;
		Personagens::Jogador* jogador2;
		Gerenciadores::Gerenciador_Grafico& GG;
		Fases::Castelo* fase;
		

	public:
		Jogo();
		~Jogo();
		void executar();
		void inicializar(Fases::Castelo* f, std::string texturePath);
		void executarEntidades(Fases::Castelo* f);
		void desenharEntidades(Fases::Castelo* f);
	};
};
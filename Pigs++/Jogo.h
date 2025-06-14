#pragma once

#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "ListaEntidades.h"
#include "Floresta.h"
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Colisao.h"

// Namespace e classe principal do projeto
namespace PigsCpp {

	class Jogo
	{
	private:
		Personagens::Jogador* jogador1;
		Gerenciadores::Gerenciador_Grafico& GG;
		Fases::Floresta* f1;
		

	public:
		Jogo();
		~Jogo();
		void executar();
		void criarEntidades(Gerenciador_Grafico* GG);
	};
};
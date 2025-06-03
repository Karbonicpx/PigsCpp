#pragma once

#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Colisao.h"

// Namespace e classe principal do projeto
namespace PigsCpp {

	class Jogo
	{
	private:
		Personagens::Jogador jogador1;
		Personagens::Jogador jogador2;
		Gerenciadores::Gerenciador_Grafico GG;
		Gerenciadores::Gerenciador_Colisao GC;

	public:
		Jogo();
		~Jogo();
		const void executar();
	};
};
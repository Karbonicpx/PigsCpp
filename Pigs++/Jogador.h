#pragma once
#include "Personagem.h"

namespace PigsCpp {
	namespace Entidades {
		namespace Personagens {
			class Jogador : public Personagem
			{
			private:

				int pontos;
				
				sf::Clock relogioPulo;
				float alturaMaximaPulo;
				float deslocamentoPulo;
				bool estaPulando;
				bool podePular;
				bool pisandoPoca;
				bool ehJogador1;

				void apertarTecla(sf::Keyboard::Key tecla, float spdX, float spdY);
				void iniciarPulo();
				void atualizarPulo();

			public:

				Jogador(const bool ehJogador1);
				Jogador();
				~Jogador();
				void mover();
				void executar();
				void salvar();
				void setVelocidade(float v);
				void setPisandoPoca(const bool pP);


			};
		}
	}
}


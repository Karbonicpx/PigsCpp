#pragma once
#include "Personagem.h"
#include "Martelo.h"
#include "ListaEntidades.h"
#include "Atirador.h"

namespace PigsCpp {
	namespace Entidades {
		namespace Personagens {
			class Jogador : public Personagem, Atirador
			{
			private:
				
				int pontos;
				
				sf::Clock relogioPulo;
				sf::Clock relogioRespawn;
				sf::Vector2f posRespawn;
				float alturaMaximaPulo;
				float deslocamentoPulo;
				float tempoCounterJ1;
				float tempoCounterJ2;
				bool podePular;
				bool pisandoPoca;
				bool ehJogador1;
				bool estaMorto;
				bool entrandoPorta;
				

				void apertarTecla(sf::Keyboard::Key tecla, float spdX, float spdY);
				
				void iniciarPulo();
				void atualizarPulo();
				void controlarRespawn();
				void atualizarDirecaoSprite(int direcao);
				void atirarProjetil();

			public:

				Jogador(const std::string jTexturePath, const bool ehJogador1, ListaEntidades* lE);
				Jogador();
				~Jogador();
				void mover();
				void executar();
				void salvar(std::ofstream& arq);
				bool entrouNaPorta() const;
				void setVelocidade(float v);
				void setPisandoPoca(const bool pP);
				void setPodePular(const bool pP);
				void setPosRespawn(const float x, const float y);
				void setEntrandoPorta(const bool eP);


			};
		}
	}
}


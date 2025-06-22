#pragma once
#include "Personagem.h"
#include "Martelo.h"

namespace PigsCpp {
    namespace Entidades {
        namespace Personagens {
            class Jogador : public Personagem
            {
            private:

                int pontos;
                float direcaoMartelo;

                bool estaPulando;	
				
				sf::Clock relogioPulo;
				sf::Clock relogioRespawn;
				sf::Vector2f posRespawn;
				float alturaMaximaPulo;
				float deslocamentoPulo;
				bool podePular;
				bool pisandoPoca;
				bool ehJogador1;
				bool estaMorto;

				void apertarTecla(sf::Keyboard::Key tecla, float spdX, float spdY);
				void iniciarPulo();
				void atualizarPulo();
				void controlarRespawn();
				void atualizarDirecaoSprite(int direcao);


            public:

                Jogador();
                ~Jogador();
                void mover();
                void executar();
                void salvar();
                Martelo* usarMartelo(float velocidade);
				Jogador(const std::string jTexturePath, const bool ehJogador1);
				void setVelocidade(float v);
				void setPisandoPoca(const bool pP);
				void setPodePular(const bool pP);
				void setPosRespawn(const float x, const float y);


            };
        }
    }
}
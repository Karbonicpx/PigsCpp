#pragma once
#include "Entidade.h"
#include <SFML/Graphics.hpp>

using namespace PigsCpp;
using namespace Entidades;
using namespace sf;
using namespace Keyboard;

namespace PigsCpp {

	namespace Entidades {

		namespace Personagens {	

			class Personagem : public Entidade {

			protected:
				int numVidas;
				float velocidade;

			public:
				Personagem(const std::string texturePath, const float bodyX, const float bodyY, const float vel, const int vida);
				Personagem();
				~Personagem();
				const int getVidas() const;
				void setVidas(const int v);
				virtual void mover() = 0;
				virtual void executar() = 0;
				virtual void salvar(std::ofstream& arq) = 0;
				void salvarDataBuffer(std::ofstream& arq);
				float getVelX();
			};
		};
	};
};




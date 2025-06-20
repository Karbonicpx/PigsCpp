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
				Personagem(const float vel);
				Personagem();
				~Personagem();
				const int getVidas() const;
				void setVidas(const int v);
				virtual void mover() = 0;
				virtual void executar() = 0;
				virtual void salvar() = 0;
				void salvarDataBuffer();
				float getVelX();
			};
		};
	};
};




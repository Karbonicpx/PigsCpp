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

			public:
				Personagem();
				~Personagem();
				const int getVidas() const;
				const void setVidas(const int v);
				const virtual void mover();
				const virtual void executar() = 0;
			};
		};
	};
};




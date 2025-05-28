#pragma once
#include "Entidade.h"

namespace PigsCpp {

	namespace Entidades {

		class Personagem : public Entidade {

			protected:
			int numVidas;

			public:
			Personagem();
			~Personagem();
			const virtual void mover();
			virtual void executar() = 0;
		};
	};
};




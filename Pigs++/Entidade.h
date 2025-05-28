#pragma once
#include "Ente.h"
#include <ostream>

namespace PigsCpp {

	namespace Entidades {

		class Entidade : public Ente
		{
		protected:
			float x;
			float y;

			// ostream buffer;
		public:
			Entidade();
			virtual ~Entidade();
			virtual void executar() = 0;
			virtual void salvar() = 0;
			const void salvarDataBuffer();
		};
	};

};

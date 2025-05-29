#pragma once
#include "Ente.h"
#include <ostream>

namespace PigsCpp {

	// A partir daqui, todas as classes relacionadas a ente ter�o o namespace Entidade
	namespace Entidades {

		class Entidade : public Ente
		{
		protected:
			float x; // Posi��o x
			float y; // Posi��o y

			// std::ostream buffer; // implementar depois
		public:
			Entidade();
			virtual ~Entidade();
			const virtual void executar() = 0;
			const virtual void salvar() = 0;
			const void setPos(const float xP, const float yP); // Fun��o para redefinir as coordenadas X e Y
			const void salvarDataBuffer(); // implementar depois
		};
	};

};

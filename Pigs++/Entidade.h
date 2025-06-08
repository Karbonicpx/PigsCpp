#pragma once
#include "Ente.h"
#include <ostream>

namespace PigsCpp {

	// A partir daqui, todas as classes relacionadas a ente terão o namespace Entidade
	namespace Entidades {

		class Entidade : public Ente
		{
		protected:
			float x; // Posição x
			float y; // Posição y

			// std::ostream buffer; // implementar depois
		protected:
			void salvarDataBuffer(); // implementar depois

		public:
			Entidade();
			virtual ~Entidade();
			virtual void executar() = 0;
			virtual void salvar() = 0;
			void setPos(const float xP, const float yP); // Função para redefinir as coordenadas X e Y
		};
	};

};

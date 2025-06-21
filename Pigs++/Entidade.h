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
			float posInicial;
			bool sofreGravidade;
			bool spriteVisivel;
			

			// std::ostream buffer; // implementar depois
		protected:
			void salvarDataBuffer(); // implementar depois

		public:
			Entidade(const bool sG, const bool sV);
			Entidade();
			virtual ~Entidade();
			virtual void executar() = 0;
			virtual void salvar() = 0;

			void setPos(const float x, const float y);
			bool getSofreGravidade() const;		
			void setSofreGravidade(const bool sV);
			void setSpriteVisivel(const bool sV);
			
		};
	};

};

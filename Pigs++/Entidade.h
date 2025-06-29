#pragma once
#include "Ente.h"
#include <ostream>
#include <fstream>

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
			// std::ostream buffer;
			void salvarDataBuffer(std::ofstream& arq);

		public:
			Entidade(const std::string texturePath, const float bodyX, const float bodyY, const bool sV, const bool sG);
			Entidade();
			virtual ~Entidade();
			virtual void executar() = 0;
			virtual void salvar(std::ofstream& arq) = 0;

			void setPos(const float x, const float y);
			bool getSofreGravidade() const;
			void setSofreGravidade(const bool sV);

		};
	};

};
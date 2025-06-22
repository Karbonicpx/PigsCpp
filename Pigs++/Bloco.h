#pragma once
#include "Obstaculo.h"
#include "Inimigo.h"
#include "Leitao.h"
#include "Baconzilla.h"

namespace PigsCpp {
	namespace Entidades {

		// Classe que vai servir apenas para delimitar colisão dos personagens entre o chão e paredes
		class Bloco : public Entidade
		{
		private:
			float blockSize;
		public:
			Bloco();
			~Bloco();
			void setSize(const float size);
			float getSize() const;
			void executar();
			void salvar();
			void blocar(Entidade* e);
		};

	};
}


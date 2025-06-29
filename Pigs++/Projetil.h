#pragma once
#include "Entidade.h"

namespace PigsCpp::Entidades {
	class Projetil : public Entidade
	{
		protected:
			sf::Vector2f velocidade;
			bool ativo;
			int dano;

		public:
			Projetil(const std::string texturePath, const float bodyX, const float bodyY, const float posX, const float posY, sf::Vector2f vel, const int d);
			~Projetil();
			virtual void mover() = 0;
			virtual void executar() = 0;
			void salvar();
			int colidir();
			const bool isAtivo() const;
			void desativar();

	};
}



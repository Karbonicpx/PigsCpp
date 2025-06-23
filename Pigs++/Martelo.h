#pragma once
#include "Entidade.h"
#include <SFML/Graphics.hpp>

namespace PigsCpp {
	namespace Entidades {
		class Martelo : public Entidade {
		private:
			int dano;
			float velocidade;
			sf::Vector2f direcao;
			bool ativo;
		public:
			Martelo(float x, float y, float vel, sf::Vector2f dir);
			~Martelo();
			void mover();
			const bool isAtivo() const;
			void executar();
			void salvar();
			const float getDano() const;
			void desativar();
		};
	};
};

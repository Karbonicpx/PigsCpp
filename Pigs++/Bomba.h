#pragma once 
#include "Entidade.h"
#include <SFML/Graphics.hpp>

namespace PigsCpp {
    namespace Entidades {

        class Bomba : public Entidade {
        private:
            sf::Vector2f velocidade;
            sf::Vector2f aceleracao;
            bool ativo;
            int dano;

        public:
            Bomba();
            Bomba(float x, float y, sf::Vector2f vel);
            ~Bomba();

            void mover();
            void executar();
            void salvar();
            
            int explodir(); // Causa dano

            const bool isAtivo() const;
            void desativar();
        };
    }
}
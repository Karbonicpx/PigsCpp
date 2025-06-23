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
            ~Bomba();
            void mover();
            const bool isAtivo() const;
            void executar();
            void salvar(std::ofstream& arq);
            Bomba(float x, float y, sf::Vector2f vel);     
            int explodir(); // Causa dano

            const bool isAtivo() const;
            void desativar();
        };
    }
}
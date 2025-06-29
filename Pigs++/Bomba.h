#pragma once 
#include "Projetil.h"

namespace PigsCpp {
    namespace Entidades {

        class Bomba : public Projetil {
        private:
            sf::Vector2f aceleracao;

        public:
            Bomba();
            Bomba(float x, float y, sf::Vector2f vel);
            ~Bomba();
            void mover();
            void executar();
            void salvar(std::ofstream& arq);
        };
    }
}


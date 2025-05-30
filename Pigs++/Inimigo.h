#pragma once
#include "Personagem.h"
#include <SFML/Graphics.hpp>

namespace Pigscpp{
    namespace Entidades{

        class Inimigo : public Personagem{

        protected:

            int nivel_maldade;

        public:

            Inimigo();
            ~Inimigo();
            int getMaldade();
            void setMaldade(int m);
            void salvarDataBuffer();
            virtual void exercutar() = 0;
            virtual void danificar(Jogador* p) = 0;

        }
    }
}
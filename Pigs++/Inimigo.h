#pragma once
#include "Personagem.h"
#include <SFML/Graphics.hpp>

namespace PigsCpp{
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
            void mover();
            virtual void executar() = 0;
            virtual void danificar(Jogador* p) = 0;
            virtual void salva() = 0;

        };
    }
}
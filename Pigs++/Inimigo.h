#pragma once
#include "Personagem.h"
#include "Jogador.h"
#include <SFML/Graphics.hpp>

namespace PigsCpp{
    namespace Entidades{
        namespace Personagens {
            class Inimigo : public Personagem {

            protected:

                int nivel_maldade;

            public:

                Inimigo();
                ~Inimigo();
                const int getMaldade() const;
                const void setMaldade(int m);
                const void salvarDataBuffer();
                const virtual void executar() = 0;
                const virtual void danificar(Jogador* p) = 0;

            };
        }  
    }
}
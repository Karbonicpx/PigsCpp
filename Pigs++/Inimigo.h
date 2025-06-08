#pragma once
#include "Jogador.h"

namespace PigsCpp {
    namespace Entidades {
        namespace Personagens {
            class Inimigo : public Personagem {

            protected:

                int nivel_maldade;

            public:

                Inimigo();
                ~Inimigo();
                const int getMaldade() const;
                void setMaldade(int m);
                void salvarDataBuffer();
                virtual void executar() = 0;
                virtual void danificar(Jogador* p) = 0;
                virtual void salvar() = 0;
                virtual void mover() = 0;
            };
        };
    };
};
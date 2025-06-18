// Inimigo Facil
#pragma once
#include "Inimigo.h"

namespace PigsCpp {
    namespace Entidades {
        namespace Personagens {
            class Leitao : public Inimigo {
            private:

                float raio;
                int direcao;
                

            public:
                Leitao();
                ~Leitao();
                void executar();
                void danificar(Jogador* p);
                void salvar();
                void mover();

                
            };
        };
    };
};
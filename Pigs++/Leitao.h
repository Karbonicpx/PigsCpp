// Inimigo Facil
#pragma once
#include "Inimigo.h"

namespace PigsCpp {
    namespace Entidades {
        namespace Personagens {
            class Leitao : public Inimigo {
            private:

                float raio;

            public:
                Leitao();
                ~Leitao();
                void executar();
                void danificar(Jogador* p);
                void salvar(std::ofstream& arq);
                void mover();
                float getRaio() const;
                void setRaio(const float r);

                
            };
        };
    };
};
// Inimigo Facil
#pragma once
#include "Inimigo.h"

namespace PigsCpp {
    namespace Entidades {
        namespace Personagens {
            class Leitao : public Inimigo {
            private:
                short int tamanho;
                short int forca;

            public:
                Leitao();
                ~Leitao();
                const void executar();
                const void danificar(Jogador* p);
                const void salvar();
                const void mover();
                const int getForca() const;
                short const int getTamanho() const;
                const void setForca(int f);
                const void setTamanho(short int t);
                

            };
        };
    };
};
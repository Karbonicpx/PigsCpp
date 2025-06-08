// Inimigo Facil
#pragma once
#include "Inimigo.h"

namespace PigsCpp {
    namespace Entidades {
        namespace Personagens {
            class Leitao : public Inimigo {
            private:
                int tamanho;
                short int forca;

            public:
                Leitao();
                ~Leitao();
                void executar();
                void danificar(Jogador* p);
                void salvar();
                void mover();
                const short int getForca() const;
                const int getTamanho() const;
                void setForca(short int f);
                void setTamanho(short int t);
            };
        };
    };
};
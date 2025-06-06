// Inimigo Medio
#pragma once
#include "Inimigo.h"

namespace PigsCpp {
    namespace Entidades {
        namespace Personagens {
            class Toucinho : public Inimigo {
            private:
                float raio;
                short int tamanho;
                short int forca;

            public:
                Toucinho();
                ~Toucinho();
                const void executar();
                const void danificar(Jogador* p);
                const void salvar();
                const void mover();
                const int getForca() const;
                const short int getTamanho() const;
                const int getRaio() const;
                const void setForca(int f);
                const void setTamanho(short int t);
                const void setRaio(float r);
            };
        };
    };
};
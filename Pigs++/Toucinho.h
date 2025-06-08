// Inimigo Medio
#pragma once
#include "Inimigo.h"

namespace PigsCpp {
    namespace Entidades {
        namespace Personagens {
            class Toucinho : public Inimigo {
            private:
                float raio;
                int tamanho;
                short int forca;

            public:
                Toucinho();
                ~Toucinho();
                void executar();
                void danificar(Jogador* p);
                void salvar();
                void mover();
                const short int getForca() const;
                const int getTamanho() const;
                const int getRaio() const;
                void setForca(short int f);
                void setTamanho(int t);
                void setRaio(float r);
            };
        };
    };
};
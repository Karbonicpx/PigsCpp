// Chefão
#pragma once
#include "Inimigo.h"

namespace PigsCpp {
    namespace Entidades {
        namespace Personagens {
            class Baconzilla : public Inimigo {
            private:
                float raio;
                int tamanho;
                short int forca;

            public:
                Baconzilla();
                ~Baconzilla();
                void executar();
                void danificar(Jogador* p);
                void salva();
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
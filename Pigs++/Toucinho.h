// Inimigo Medio
#pragma once
#include "Inimigo.h"
#include <SFML/Graphics.hpp>

namespace PigsCpp {
    namespace Entidades {

        class Toucinho : public Inimigo {
        private:
            float raio;
            int tamanho;
            short int forca;

        public:
            Toucinho();
            ~Toucinho();
            const void executar() override;
            const void danificar(Jogador* p) override;
            const void salva();
            const void mover();
            const int getForca() const;
            const int getTamanho() const;
            const int getRaio() const;
            const void setForca(int f);
            const void setTamanho(int t);
            const void setRaio(float r);
        };

    }
}
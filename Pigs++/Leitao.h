// Inimigo Facil
#pragma once
#include "Inimigo.h"
#include <SFML/Graphics.hpp>

namespace PigsCpp {
    namespace Entidades {

        class Leitao : public Inimigo {
        private:
            float raio;
            int tamanho;
            short int forca;

        public:
            Leitao();
            ~Leitao();
            void executar() override;
            void danificar(Jogador* p) override;
            void salva();  
            int getForca();
            int getTamanho();
            int getRaio();
            void setForca(int f);
            void setTamanho(int t);
            void setRaio(float r);

        };

    }
}
// Chefão
#pragma once
#include "Inimigo.h"
#include "Jogador.h"
#include "Bomba.h"
#include <cmath>

namespace PigsCpp {
    namespace Entidades {
        namespace Personagens {
            class Baconzilla : public Inimigo {
            private:
                int tamanho;
                short int forca;
                sf::Clock relogio;
                float tempoTrocaDirecao; // Intervalo em segundos

            public:
                Baconzilla();
                ~Baconzilla();
                void executar();
                void danificar(Jogador* p);
                void salvar();
                void mover(); 
                void atirarProjetil();

            };
        };


    };
};
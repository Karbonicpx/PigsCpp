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
                int direcao;
                short int forca;
                sf::Clock relogio;
                float tempoTrocaDirecao; // em segundos

            public:
                Baconzilla();
                ~Baconzilla();
                void executar();
                void danificar(Jogador* p);
                void salvar();
                void mover(); // Pra cumprir com método virtual puro, não utilizar!
                void atirarProjetil(Jogador* alvo, std::vector<Bomba*>& bombas);

            };
        };


    };
};
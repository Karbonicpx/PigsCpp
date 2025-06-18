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

            public:
                Baconzilla();
                ~Baconzilla();
                void executar(); // Pra cumprir com método virtual puro, não utilizar!
                void executar(Jogador* j, std::vector<Bomba*>& bombas);
                void danificar(Jogador* p);
                void salvar();
                void mover(); // Pra cumprir com método virtual puro, não utilizar!
                void mover(Jogador* j);
                void atirarProjetil(Jogador* alvo, std::vector<Bomba*>& bombas);

            };
        };


    };
};
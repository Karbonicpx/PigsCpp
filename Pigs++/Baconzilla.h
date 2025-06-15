// Chefão
#pragma once
#include "Inimigo.h"
#include "Jogador.h"
#include "Projetil.h"
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
                void executar(Jogador* j, std::vector<Projetil*>& projeteis);
                void danificar(Jogador* p);
                void salva();
                void mover(Jogador* j);
                void atirarProjetil(Jogador* alvo, std::vector<Projetil*>& projeteis);

            };
        };


    };
};
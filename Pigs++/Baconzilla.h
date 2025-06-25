// Chefão
#pragma once
#include "Inimigo.h"
#include "Bomba.h"
#include "ListaEntidades.h"
#include "Atirador.h"
#include <cmath>

namespace PigsCpp {
    namespace Entidades {
        namespace Personagens {
            class Baconzilla : public Inimigo, Atirador {
            private:

                int tamanho;
                short int forca;
                sf::Clock relogio;
                float tempoTrocaDirecao; // em segundos

            public:
                Baconzilla(ListaEntidades* lE);
                ~Baconzilla();
                void executar();
                void danificar(Jogador* p);
                void salvar(std::ofstream& arq);
                void mover();
                void atirarProjetil();

            };
        };


    };
};
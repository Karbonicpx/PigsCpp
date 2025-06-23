// Inimigo Medio
#pragma once
#include "Inimigo.h"
#include "Bomba.h"
#include <queue>

namespace PigsCpp {
    namespace Entidades {
        namespace Personagens {
            class Toucinho : public Inimigo {
            private:

                // Usando isso aqui para ter um fluxo de bombas sendo alocadas e desalocadas da memoria
                std::queue<Bomba*> filaBombas;
                int tempoAtaque;
                short int forca;

            public:
                Toucinho();
                ~Toucinho();
                void executar();
                void danificar(Jogador* p);
                void salvar(std::ofstream& arq);
                void mover();
                void tacarBomba();

            };
        };
    };
};
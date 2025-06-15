// Inimigo Medio
#pragma once
#include "Inimigo.h"
#include "Bomba.h"
#include <vector>

namespace PigsCpp {
    namespace Entidades {
        namespace Personagens {
            class Toucinho : public Inimigo {
            private:
                short int forca;
                std::vector <Bomba> bombas;
                int tempoAtaque;

            public:
                Toucinho();
                ~Toucinho();
                void executar();
                void danificar(Jogador* p);
                void salvar();
                void mover();
                void tacarBomba();

            };
        };
    };
};
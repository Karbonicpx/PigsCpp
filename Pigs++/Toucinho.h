// Inimigo Medio
#pragma once
#include "Inimigo.h"
#include "Bomba.h"
#include "ListaEntidades.h"
#include "Atirador.h"


using namespace Listas;

namespace PigsCpp {
    namespace Entidades {
        namespace Personagens {
            class Toucinho : public Inimigo, Atirador {
            private:

                short int forca;

            public:
                Toucinho(ListaEntidades* lista);
                ~Toucinho();
                void executar();
                void danificar(Jogador* p);
                void salvar(std::ofstream& arq);
                void mover();
                void atirarProjetil();

            };
        };
    };
};


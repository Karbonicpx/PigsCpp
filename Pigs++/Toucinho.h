// Inimigo Medio
#pragma once
#include "Inimigo.h"
#include "Bomba.h"
#include "ListaEntidades.h"
#include <queue>


using namespace Listas;

namespace PigsCpp {
    namespace Entidades {
        namespace Personagens {
            class Toucinho : public Inimigo {
            private:

                
               
                ListaEntidades* listaEntidades;
                // Usando isso aqui para ter um fluxo de bombas sendo alocadas e desalocadas da memoria
                std::queue<Bomba*> filaBombas;
                int tempoAtaque;
                short int forca;

            public:
                Toucinho(ListaEntidades* lista);
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
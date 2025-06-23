#pragma once

#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "ListaEntidades.h"
#include "Floresta.h"
#include "Subterraneo.h"
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Colisao.h"
#include <ctime>

namespace PigsCpp {
    class Jogo {
    private:
        Personagens::Jogador* jogador1;
        Personagens::Jogador* jogador2;
        Gerenciadores::Gerenciador_Grafico& GG;
        Fases::Fase* fase;

        int idFase;

    public:
        Jogo(int idFase);
        ~Jogo();

        void executar();
        void executarEntidades(Fases::Fase* f);
        void desenharEntidades(Fases::Fase* f);
    };
}
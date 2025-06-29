#pragma once
#include "Entidade.h"
#include "Jogador.h"

namespace PigsCpp {
    namespace Entidades {

        class Porta : public Entidade {
        private:
            sf::Clock relogioEntrada;
            bool podeEntrar;
            int idProximaFase; // Ex: 2 Fase 2,  -1,  sair do jogo
            bool trocarFase;
           

        public:
            Porta(int idProxima);
            ~Porta();

            void executar();
            void verificarEntrada(Personagens::Jogador* j);
            void salvar(std::ofstream& arq);
            bool getTrocarFase();
            int getIdProxFase();
           
        };
    }
}

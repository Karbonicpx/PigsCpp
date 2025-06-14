#pragma once
#pragma once

#include "Jogador.h"
#include "Entidade.h"

/* LEIA!!
 OBS: Todos os cr�ditos ao c�digo dos arquivos .h e .cpp dessa classe,
 se deve aos integrantes do grupo de extens�o PETECO, na universidade UTFPR,
 na qual foi feita uma oficina direcionada ao desenvolvimento dos gerenciadores
 dirigida por eles, realizada em 30/05/2025, das 17:00 as 19:00, na sala do PETECO.
*/


namespace PigsCpp {
    namespace Gerenciadores {
        class Gerenciador_Colisao {
        private:
            // list<Obstaculos::Obstaculo*> LObst; // Implementar depois
            // list<Personagens::Inimigo*> LIni; // Implementar depois
            // list<Projetil*> LProjetil; // Implementar depois
            Personagens::Jogador* jog1;
            Personagens::Jogador* jog2;

        public:
            Gerenciador_Colisao();
            ~Gerenciador_Colisao();
            void setJogadores(Personagens::Jogador* j1, Personagens::Jogador* j2);
            void includeEntidade(Entidade* ent);
            void removeEntidade(Entidade* ent);
            const bool veriColisao(Entidade* ent1, Entidade* ent2);
            void verificaObs();
            void verificaInim();
            void verificaProjetil();
            void executar();
        };
    }
}
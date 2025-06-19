#pragma once

#include "Jogador.h"
#include "Entidade.h"
#include "Obstaculo.h"
#include "Inimigo.h"
#include "Bomba.h"
#include "Bloco.h"
#include "ListaEntidades.h"
#include <list>
#include <vector>
#include <set>

/* LEIA!!
 OBS: Todos os créditos ao código dos arquivos .h e .cpp dessa classe,
 se deve aos integrantes do grupo de extensão PETECO, na universidade UTFPR,
 na qual foi feita uma oficina direcionada ao desenvolvimento dos gerenciadores
 dirigida por eles, realizada em 30/05/2025, das 17:00 as 19:00, na sala do PETECO.
*/


namespace PigsCpp {
    namespace Gerenciadores {

        using namespace Entidades;
        using namespace std;
        class Gerenciador_Colisao {
        private:
            list<Obstaculo*> LOs; 
            vector<Inimigo*> LIs; 
            set<Bomba*> LBs;
            ListaEntidades* LEsGC;
            
            Personagens::Jogador* jog1;
            Personagens::Jogador* jog2;
            const bool verificarColisao(Entidade* ent1, Entidade* ent2);
            void tratarColisoesJogsObstacs();
            void tratarColisoesJogsInimgs();
            void tratarColisoesJogsBombas();
            void tratarColisoesEntsBlocos();
           

        public:
            Gerenciador_Colisao();
            ~Gerenciador_Colisao();
            void setJogadores(Personagens::Jogador* j1, Personagens::Jogador* j2);
            void incluirInimigo(Inimigo* ini);
            void incluirObstaculo(Obstaculo* obs);
            void incluirBomba(Bomba* b);
            void removerInimigo(Inimigo* ini);
            void removerObstaculo(Obstaculo* obs);
            void removerBomba(Bomba* b);

            void setLE(ListaEntidades* LE);


            void executar();
        };
    }
}

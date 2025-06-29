#pragma once

#include "Jogador.h"
#include "Entidade.h"
#include "Obstaculo.h"
#include "Tronco.h"
#include "Inimigo.h"
#include "Projetil.h"
#include "Bloco.h"
#include "Porta.h"
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
<<<<<<< Updated upstream
            list<Obstaculo*> LOs; 
            vector<Inimigo*> LIs; 
=======
            list<Obstaculo*> LOs;
            vector<Inimigo*> LIs;
>>>>>>> Stashed changes
            set<Projetil*> LPs;
            ListaEntidades* LEsGC;

            bool trocarFase;
            int idNovaFase;

            Personagens::Jogador* jog1;
            Personagens::Jogador* jog2;
            const bool verificarColisao(Entidade* ent1, Entidade* ent2);
            void tratarColisoesJogsObstacs();
            void tratarColisoesJogsInimgs();
            void tratarColisoesJogsBombas();
            void tratarColisoesJogsPortas();
            void tratarColisoesEntsBlocos();
            void tratarColisoesInimTroncos();
            void tratarColisoesInimMartelos();
<<<<<<< Updated upstream
            
           
=======


>>>>>>> Stashed changes

        public:
            Gerenciador_Colisao();
            ~Gerenciador_Colisao();
            void setJogadores(Personagens::Jogador* j1, Personagens::Jogador* j2);
            void incluirInimigo(Inimigo* ini);
            void incluirObstaculo(Obstaculo* obs);
            void incluirProjetil(Projetil* b);
            void removerInimigo(Inimigo* ini);
            void removerProjetil(Projetil* b);
            const bool getTrocarFase() const;
            const int getIdNovaFase() const;
            void resetarTrocaFase();

            void setLE(ListaEntidades* LE);


            void executar();
        };
    }
}
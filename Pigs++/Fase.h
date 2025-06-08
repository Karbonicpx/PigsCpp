#pragma once
#include "Jogador.h"
#include "Inimigo.h"
#include "Leitao.h"
#include "Toucinho.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisao.h"

using namespace PigsCpp::Entidades::Personagens;
using namespace PigsCpp::Gerenciadores;


// LEIA!
// OBS: Todos os créditos ao uso de partes do código desenvolvido nesse arquivo, por Felipe Alvez Barboza,
// retirado através de um tutorial de uma playlist feita pelo mesmo, no canal "Dev Felipe", 
// ensinando a como desenvolver uma lista template.

namespace PigsCpp {

	namespace Fases {
		class Fase {

		private:
			Gerenciador_Colisao* GC;
			ListaEntidades* LEs;
			Jogador* j1;
			Jogador* j2;

		public:
			Fase(Jogador* pJ);
			Fase(Jogador* pJ1, Jogador* pJ2);
			~Fase();
			// const virtual void executar();
			void gerenciarColisoes();
			void criarTouc();
			void criarPlataformas();
			// virtual void criarInimigos() = 0;
			// virtual void criarObstaculo() = 0;
			void criarCenario();

			ListaEntidades* getListaEntidades() const;
		};
	};
};



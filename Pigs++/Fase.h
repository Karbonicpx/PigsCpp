#pragma once
#include "Jogador.h"
#include "Inimigo.h"
#include "Leitao.h"
#include "Toucinho.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisao.h"
#include "nlohmann/json.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace PigsCpp::Entidades::Personagens;
using namespace PigsCpp::Gerenciadores;


// OBS:
// Código de geração de tilemap retirado do manual da oficina PETECO,
// no link: https://github.com/Nixxye/Project-Simas-PETECO/tree/main/Tilemap
namespace PigsCpp {

	namespace Fases {
		class Fase : public Ente {

		private:
			Gerenciador_Colisao* GC;
			ListaEntidades* LEs;
			nlohmann::json mapa; // mapa.json  
		protected:
			Entidade* ent; // Entidade genérica que vai ser usada na função virtual de criar entidades
			Jogador* j1;
			Jogador* j2;
			std::vector< std::pair<int, sf::Vector2f> > posicoesEntidades;

		public:
			Fase();
			Fase(Jogador* pJ, std::string jsonPath);
			Fase(Jogador* pJ1, Jogador* pJ2, std::string jsonPath);
			~Fase();
			virtual void executar();
			virtual void criarInimigos() = 0;
			virtual void criarObstaculo() = 0;

			void gerenciarColisoes();
			void criarTouc();
			void criarPlataformas();
			void criarCenario();
			ListaEntidades* getListaEntidades() const;
			Gerenciador_Colisao* getGC() const;
			

			void setMapa(std::string jsonPath);
			void criarMapa();		
			void desenharTileset(Gerenciador_Grafico* GG, std::string tilesetPath);
			virtual void criarEntidades(Gerenciador_Grafico* GG) = 0;
		};
	};
};



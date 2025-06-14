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
// C�digo de gera��o de tilemap adaptado do manual da oficina PETECO,
// no link: https://github.com/Nixxye/Project-Simas-PETECO/tree/main/Tilemap
namespace PigsCpp {

	namespace Fases {
		class Fase : public Ente {

		private:
			Gerenciador_Colisao* GC;
			ListaEntidades* LEs;
			nlohmann::json mapa; // mapa.json  
		protected:
			Entidade* ent; // Entidade gen�rica que vai ser usada na fun��o virtual de criar entidades
			Jogador* j1;
			Jogador* j2;
			std::vector< std::pair<int, sf::Vector2f> > posicoesEntidades;
			const float spriteSize;

		public:
			Fase(std::string jsonPath);
			~Fase();
			virtual void executar();
			virtual void criarInimigos() = 0;
			virtual void criarObstaculo() = 0;
			void criarJogador();

			void gerenciarColisoes();
			void criarLeitao();
			void criarPlataformas();
			void criarCenario();
			ListaEntidades* getListaEntidades() const;
			Gerenciador_Colisao* getGC() const;
			void setJogadores(Jogador* pJ1, Jogador* pJ2 = nullptr);
			

			void setMapa(std::string jsonPath);
			void criarMapa();
			void inicializarEntidades(Entidade* e, const float x, const float y, const float size);
			virtual void desenharTileset(Gerenciador_Grafico* GG, std::string tilesetPath);
			virtual void criarEntidades(Gerenciador_Grafico* GG) = 0;
		};
	};
};



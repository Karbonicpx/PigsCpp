#pragma once
#include "Jogador.h"
#include "Inimigo.h"
#include "Leitao.h"
#include "Toucinho.h"
#include "Baconzilla.h"
#include "Obstaculo.h"
#include "Lago.h"
#include "Tronco.h"	
#include "Espinho.h"
#include "Bloco.h"
#include "Porta.h"
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
// Código de geração de tilemap adaptado do manual da oficina PETECO,
// no link: https://github.com/Nixxye/Project-Simas-PETECO/tree/main/Tilemap
namespace PigsCpp {

	namespace Fases {
		class Fase : public Ente {

		private:
			Gerenciador_Colisao* GC;
			ListaEntidades* lista_entes;
			nlohmann::json mapa; // mapa.json  
			static const float gravidade;
			void aplicarGravidade();
			sf::Texture texturaFundo;
			sf::Sprite fundo;

		protected:
			Entidade* ent; // Entidade genérica que vai ser usada na função virtual de criar entidades
			Jogador* j1;
			Jogador* j2;
			std::vector<std::pair<int, sf::Vector2f>> posicoesEntidades;
			const int maxLagos; // Numero máximo de lagos em ambas fases
			const int maxLeitaos; // Numero máximo de leitaos em ambas fases

			void gerenciarColisoes();
			void criarJogador(const float posX, const float posY);
			void criarBloco(); // Chão e paredes do jogo
			void criarLeitao();
			void criarPlataformas();
			void criarCenario();
			void criarPorta(int idFase);
			virtual void criarInimigos() = 0;
			virtual void criarObstaculo() = 0;
			void gerenciarMorteInimigo();
			void gerenciarCriacaoProjeteis();

		public:
			Fase(std::string jsonPath, const int mLG, const int mLT);
			Fase();
			~Fase();
			virtual void executar();	
			void criarMapa();
			void inicializarEntidades(Entidade* e, const float x, const float y);
			virtual void desenharTileset(Gerenciador_Grafico* GG, std::string tilesetPath);
			virtual void criarEntidades(Gerenciador_Grafico* GG) = 0;

			Gerenciador_Colisao* getGC() const;
			ListaEntidades* getListaEntidades() const;
			void setJogadores(Jogador* pJ1, Jogador* pJ2 = nullptr);
			void setMapa(std::string jsonPath);
		};
	};
};



#include "Fase.h"

using namespace PigsCpp::Fases;
using namespace std;

// 2 tipos de construtores: Um quando for apenas um jogador, e um quando for 2
Fase::Fase(Jogador* pJ, string jsonPath):
	j1(pJ),
	j2(nullptr)
	
{

	GC = new Gerenciador_Colisao();
	LEs = new ListaEntidades();
	setMapa(jsonPath);
	criarMapa();

	
};

Fase::Fase(Jogador* pJ1, Jogador* pJ2, string jsonPath):
	j1(pJ1),
	j2(pJ2)
	
{
	GC = new Gerenciador_Colisao();
	LEs = new ListaEntidades();
	setMapa(jsonPath);
	criarMapa();
	
};

Fase::Fase() :
	j1(nullptr),
	j2(nullptr)
{
	GC = new Gerenciador_Colisao();
	LEs = new ListaEntidades();


};

Fase::~Fase() {

	LEs->listaEntidades.limpar();
	j1 = nullptr;
	j2 = nullptr;
	delete(LEs);
	delete(GC);
};

ListaEntidades* Fase::getListaEntidades() const {
	return LEs;
}

void Fase::setMapa(string jsonPath) {

	ifstream arquivo(jsonPath);

	// Se não conseguir abrir o arquivo, exibe uma mensagem de erro
	try {
		arquivo >> mapa;
		arquivo.close();
	}

	catch (const exception& e) {
		cerr << "Erro ao abrir o mapa: " << e.what() << endl;
		return;
	}
}

// Criando o mapa a partir dos dados do JSON
void Fase::criarMapa() {
	int tileSize = mapa["tilewidth"];
	int width = mapa["width"];
	int height = mapa["height"];

	for (unsigned int i = 0; i < mapa["layers"].size(); i++) {
		std::string nome = mapa["layers"][i]["name"];
		if (nome != "Entidades")
			continue;

		std::vector<int> dados = mapa["layers"][i]["data"];
		int indice = 0;

		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				int tileId = dados[indice++];
				if (tileId == 0)
					continue;

				sf::Vector2f pos(static_cast<float>(x * tileSize), static_cast<float>(y * tileSize));
				posicoesEntidades.push_back(make_pair(tileId, pos));
			}
		}
	}
}

void Fase::desenharPlataformas(Gerenciador_Grafico* GG, string tilesetPath) {
	int tileSize = mapa["tilewidth"];
	int largura = mapa["width"];
	int altura = mapa["height"];
	sf::Texture* tileset = new Texture(tilesetPath);


	int colunasTileset = tileset->getSize().x / tileSize;

	for (unsigned int i = 0; i < mapa["layers"].size(); i++) {
		std::string nomeCamada = mapa["layers"][i]["name"];
		if (nomeCamada != "Plataformas")
			continue;

		std::vector<int> dados = mapa["layers"][i]["data"];
		int indice = 0;

		for (int y = 0; y < altura; y++) {
			for (int x = 0; x < largura; x++) {
				int tileId = dados[indice++] - 1; // Tiled começa IDs em 1

				if (tileId < 0)
					continue;

				int tu = tileId % colunasTileset;
				int tv = tileId / colunasTileset;
				// Criar o sprite (sem parâmetros no construtor)
				sf::Sprite bloco(*tileset);

				// Configurar a porção da textura
				bloco.setTextureRect(sf::IntRect({ tu * tileSize, tv * tileSize }, { tileSize,tileSize } ));

				// Configurar posição
				bloco.setPosition(sf::Vector2f(static_cast<float>(x * tileSize), static_cast<float>(y * tileSize)));
				GG->getWindow()->draw(bloco);
			}
		}

		break; // só a camada "Plataformas"
	}
}


void Fase::criarEntidades(Gerenciador_Grafico* GG) {


	for (unsigned int i = 0; i < posicoesEntidades.size(); i++) {
		int tileId = posicoesEntidades[i].first;
		sf::Vector2f pos = posicoesEntidades[i].second;
		float tamanho = 32.0f; // Tamanho padrão das entidades	

		Entidade* ent = nullptr;

		switch (tileId) {
		case 67: // Plataforma
			// ent = new Plataforma(); // agora sem parâmetros
			break;

	

		case 70: // Toucinho (inimigo fácil)
			ent = static_cast<Entidade*>(new Toucinho());
			
			break;

		case 71: // Leitao (inimigo médio)
			ent = static_cast<Entidade*>(new Leitao());
			
			break;

		case 72: // Obstáculo
			// ent = new Obstaculo();
			break;

		case 73: // Jogador
			if (j1 != nullptr && j2 == nullptr) {

				ent = static_cast<Entidade*>(j1);

			}
			else {

				ent = static_cast<Entidade*>(j1);
				ent = static_cast<Entidade*>(j2);

			}
			break;

		default:
			break;

			
				
		}
		if (ent != nullptr) {
			ent->setPos(pos.x, pos.y);
			ent->setTamanho(tamanho, tamanho);
			LEs->listaEntidades.incluir(ent);
		}
	}

	
}


// Fazer depois
void Fase::gerenciarColisoes() {

}

// Fazer depois
void Fase::criarTouc() {

}

// Fazer depois
void Fase::criarPlataformas() {

}

// Fazer depois
void Fase::criarCenario() {

}

void Fase::executar() {
	gerenciarColisoes();
}




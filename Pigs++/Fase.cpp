#include "Fase.h"

using namespace PigsCpp::Fases;
using namespace std;

// 2 tipos de construtores: Um quando for apenas um jogador, e um quando for 2
Fase::Fase(Jogador* pJ, string jsonPath):
	j1(pJ),
	j2(nullptr),
	ent(nullptr)
	
{

	GC = new Gerenciador_Colisao();
	LEs = new ListaEntidades();
	setMapa(jsonPath);
	criarMapa();

	
};

Fase::Fase(Jogador* pJ1, Jogador* pJ2, string jsonPath):
	j1(pJ1),
	j2(pJ2),
	ent(nullptr)
	
{
	GC = new Gerenciador_Colisao();
	LEs = new ListaEntidades();
	setMapa(jsonPath);
	criarMapa();
	
};

Fase::Fase() :
	j1(nullptr),
	j2(nullptr),
	ent(nullptr)
{
	GC = new Gerenciador_Colisao();
	LEs = new ListaEntidades();


};

Fase::~Fase() {

	LEs->listaEntidades.limpar();
	j1 = nullptr;
	j2 = nullptr;
	ent = nullptr;
	delete(LEs);
	delete(GC);
};

ListaEntidades* Fase::getListaEntidades() const {
	return LEs;
}

Gerenciador_Colisao* Fase::getGC() const {
	return GC;
};

void Fase::setMapa(string jsonPath) {

	ifstream arquivo(jsonPath);

	// Se n�o conseguir abrir o arquivo, exibe uma mensagem de erro
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

void Fase::desenharTileset(Gerenciador_Grafico* GG, string tilesetPath) {
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
				int tileId = dados[indice++] - 1; // Tiled come�a IDs em 1

				if (tileId < 0)
					continue;

				int tu = tileId % colunasTileset;
				int tv = tileId / colunasTileset;
				// Criar o sprite (sem par�metros no construtor)
				sf::Sprite bloco(*tileset);

				// Configurar a por��o da textura
				bloco.setTextureRect(sf::IntRect({ tu * tileSize, tv * tileSize }, { tileSize,tileSize } ));

				// Configurar posi��o
				bloco.setPosition(sf::Vector2f(static_cast<float>(x * tileSize), static_cast<float>(y * tileSize)));
				GG->getWindow()->draw(bloco);
			}
		}

		break; // s� a camada "Plataformas"
	}
}


// Fazer depois
void Fase::gerenciarColisoes() {

}

// Fazer depois
void Fase::criarTouc() {
	ent = static_cast<Entidade*>(new Toucinho());
}

// Fazer depois
void Fase::criarPlataformas() {
	// ent = new Plataforma(); // agora sem par�metros
}

// Fazer depois
void Fase::criarCenario() {

}

void Fase::executar() {
	gerenciarColisoes();
}




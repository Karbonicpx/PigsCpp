#include "Fase.h"

using namespace PigsCpp::Fases;
using namespace std;


Fase::Fase(string jsonPath) :
	j1(nullptr),
	j2(nullptr),
	ent(nullptr)
{
	GC = new Gerenciador_Colisao();
	LEs = new ListaEntidades();
	setMapa(jsonPath);
	criarMapa();


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

void Fase::setJogadores(Jogador* pJ1, Jogador* pJ2) {
	j1 = pJ1;
	j2 = pJ2;

	LEs->listaEntidades.incluir(j1);
	if (j2 != nullptr)
		LEs->listaEntidades.incluir(j2);
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

void Fase::desenharTileset(Gerenciador_Grafico* GG, std::string tilesetPath) {
	int tileSize = mapa["tilewidth"];
	int largura = mapa["width"];
	int altura = mapa["height"];
	sf::Texture* tileset = new Texture(tilesetPath);


	int colunasTileset = tileset->getSize().x / tileSize;

	for (unsigned int i = 0; i < mapa["layers"].size(); i++) {
		std::string nomeCamada = mapa["layers"][i]["name"];
		if (nomeCamada != "Visual")
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
				bloco.setTextureRect(sf::IntRect({ tu * tileSize, tv * tileSize }, { tileSize,tileSize }));

				// Configurar posição
				bloco.setPosition(sf::Vector2f(static_cast<float>(x * tileSize), static_cast<float>(y * tileSize)));
				GG->getWindow()->draw(bloco);
			}
		}

		break; // só a camada "Plataformas"
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
	// ent = new Plataforma(); // agora sem parâmetros
}

// Fazer depois
void Fase::criarCenario() {

}

void Fase::criarJogador() {

	if (j1 != nullptr && j2 == nullptr) {

		ent = static_cast<Entidade*>(j1);

	}
	else {

		ent = static_cast<Entidade*>(j1);
		ent = static_cast<Entidade*>(j2);

	}
}

void Fase::executar() {
	gerenciarColisoes();
}




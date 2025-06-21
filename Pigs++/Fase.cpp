#include "Fase.h"

using namespace PigsCpp::Fases;
using namespace std;


Fase::Fase(string jsonPath, const int mLG, const int mLT) :
	j1(nullptr),
	j2(nullptr),
	ent(nullptr),
	spriteSize(32.0f),
	maxLagos(mLG),
	maxLeitaos(mLT)
	
{
	GC = new Gerenciador_Colisao();
	lista_entes = new ListaEntidades();
	setMapa(jsonPath);
	criarMapa();
	this->operator++(); // Fase também é ente
};
Fase::Fase() :
	j1(nullptr),
	j2(nullptr),
	ent(nullptr),
	GC(nullptr),
	lista_entes(nullptr),
	spriteSize(32.0f),
	maxLagos(0),
	maxLeitaos(0)

{
	
};
const float Fase::gravidade(2.3f);

Fase::~Fase() {

	lista_entes->listaEntidades.limpar();
	j1 = nullptr;
	j2 = nullptr;
	ent = nullptr;
	delete(lista_entes);
	delete(GC);
};

ListaEntidades* Fase::getListaEntidades() const {
	return lista_entes;
}


void Fase::setJogadores(Jogador* pJ1, Jogador* pJ2) {
	j1 = pJ1;
	j2 = pJ2;

	GC->setJogadores(j1, j2);
	lista_entes->listaEntidades.incluir(j1);
	if (j2 != nullptr) { lista_entes->listaEntidades.incluir(j2); }
		
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

// Método que vai desenhar apenas os tilesets da camada "Visual", sem criar nenhuma entidade
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

				// Configurar a porção da textura do tileset
				bloco.setTextureRect(sf::IntRect({ tu * tileSize, tv * tileSize }, { tileSize,tileSize }));

				// Configurar posição
				bloco.setPosition(sf::Vector2f(static_cast<float>(x * tileSize), static_cast<float>(y * tileSize)));
				GG->getWindow()->draw(bloco);
			}
		}

		break; // só a camada "Plataformas"
	}
}

void Fase::inicializarEntidades(Entidade* e, const float x, const float y, const float size) {
	if (e != nullptr) {
		e->setPos(x, y);
		e->getCorpo().setSize(sf::Vector2f(size, size));

		// Se não for bloco, aumentar o ID
		if (dynamic_cast<Bloco*>(e) == nullptr){
			e->operator++();
		}

		getListaEntidades()->listaEntidades.incluir(e);

		// Inclusão no Gerenciador de Colisão, checa se é inimigo ou obstaculo
		if (dynamic_cast<Inimigo*>(e) != nullptr) {
			GC->incluirInimigo(static_cast<Inimigo*>(e));
		}
		else if (dynamic_cast<Obstaculo*>(e) != nullptr) {
			GC->incluirObstaculo(static_cast<Obstaculo*>(e));
		}

		e = nullptr;
	}
}


void Fase::aplicarGravidade() {
	for (int i = 0; i < lista_entes->listaEntidades.getLen(); i++) {
		Entidade* ent = lista_entes->listaEntidades.getItem(i);

		// Se a entidade pode sofrer gravidade...
		if (ent->getSofreGravidade() == true) {
			if (ent != nullptr) {
				ent->getCorpo().move(sf::Vector2f(0.0f, gravidade));
			}
		}
	}
}

void Fase::criarBloco() {
	ent = static_cast<Entidade*>(new Bloco());
}

void Fase::criarLeitao() {
	ent = static_cast<Entidade*>(new Leitao());
}

// Fazer depois
void Fase::criarPlataformas() {
	// ent = static_cast<Entidade*>(new Plataforma());
}

// Fazer depois
void Fase::criarCenario() {

}

void Fase::criarJogador(const float posX, const float posY, const float size) {

	// Se tiver apenas um jogador, crie apenas um
	if (j1 != nullptr && j2 == nullptr) {

		j1->setPos(posX, posY);
		j1->getCorpo().setSize(sf::Vector2f(size, size));
		j1->operator++();

	}
	// Se tiver 2, cria os dois
	else {

		j1->setPos(posX, posY);
		j1->getCorpo().setSize(sf::Vector2f(size, size));
		j1->operator++();

		// Cria um segundo jogador do lado do primeiro
		j2->setPos(posX + size, posY);
		j2->getCorpo().setSize(sf::Vector2f(size, size));
		j2->operator++();

	}
}

void Fase::gerenciarColisoes() {
	GC->setLE(lista_entes);
	GC->executar();
}

void Fase::executar() {
	gerenciarColisoes();
	aplicarGravidade();
}




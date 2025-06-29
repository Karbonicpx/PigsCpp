#include "Fase.h"

using namespace PigsCpp::Fases;
using namespace std;


Fase::Fase(string jsonPath, const int mLG, const int mLT) :
	j1(nullptr),
	j2(nullptr),
	ent(nullptr),
	maxLagos(mLG),
	maxLeitaos(mLT),
	texturaFundo("textures/Fase1BG.png"),
	fundo(texturaFundo)
	
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
	maxLagos(0),
	maxLeitaos(0),
	texturaFundo("textures/Fase1BG.png"),
	fundo(texturaFundo)

{
	
};
const float Fase::gravidade(3.0f);

Fase::~Fase() {

	lista_entes->listaEntidades.limpar();
	j1 = nullptr;
	j2 = nullptr;
	ent = nullptr;
	delete(lista_entes);
	delete(GC);
	lista_entes = nullptr;
	GC = nullptr;
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

	GG->getWindow()->draw(fundo); // Desenha o fundo primeiro

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

void Fase::inicializarEntidades(Entidade* e, const float x, const float y) {
	if (e != nullptr) {

		if (dynamic_cast<Leitao*>(e) != nullptr){
			e->setPos(x, y);
		}
		else if (dynamic_cast<Baconzilla*>(e) != nullptr) {
			e->setPos(x, y);
		}
		else if (dynamic_cast<Toucinho*>(e) != nullptr) {
			if (x > 200.f && x < 900.f || x < 50.f) {
				dynamic_cast<Toucinho*>(e)->inverterDir();
			}
			e->setPos(x, y);
		}
		else e->setPos(x, y);
		

		// Se não for bloco ou obstaculo, aumentar o ID
		if (dynamic_cast<Bloco*>(e) == nullptr || dynamic_cast<Obstaculo*>(e) == nullptr){
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
	ent = dynamic_cast<Entidade*>(new Bloco());
}

void Fase::criarLeitao() {
	ent = dynamic_cast<Entidade*>(new Leitao());
}


void Fase::criarPlataformas() {
	// ent = dynamic_cast<Entidade*>(new Plataforma());
}

void Fase::criarPorta(int idFase) {
	ent = dynamic_cast<Porta*>(new Porta(idFase));
}


// Fazer depois
void Fase::criarCenario() {
	fundo.setTexture(texturaFundo);
	fundo.setPosition(sf::Vector2f(0.f, 0.f));
}

void Fase::criarJogador(const float posX, const float posY) {

	// Se tiver apenas um jogador, crie apenas um
	if (j1 != nullptr && j2 == nullptr) {

		j1->setPos(posX, posY);
		j1->setPosRespawn(posX, posY);
		j1->operator++();

	}
	// Se tiver 2, cria o segundo
	else {

		j1->setPos(posX, posY);
		j1->setPosRespawn(posX, posY);
		j1->operator++();
		// Cria um segundo jogador do lado do primeiro
		j2->setPos(posX + j1->getCorpo().getSize().x, posY);
		j2->setPosRespawn(posX + j1->getCorpo().getSize().x, posY);
		j2->operator++();

	}
}

void Fase::gerenciarMorteInimigo() {
	for (int i = 0; i < lista_entes->listaEntidades.getLen(); i++) {

		Entidade* e = lista_entes->listaEntidades.getItem(i);

		// Se for inimigo, remove do Gerenciador de Colisão caso ele tenha vida menor ou igual a 0
		Inimigo* inim = dynamic_cast<Inimigo*>(e);
		if (inim != nullptr && inim->getVidas() <= 0) {
			GC->removerInimigo(inim);
			lista_entes->listaEntidades.remover(e);
		}

	}
}


void Fase::gerenciarCriacaoProjeteis() {
	for (int i = 0; i < lista_entes->listaEntidades.getLen(); i++) {
		Entidade* e = lista_entes->listaEntidades.getItem(i);
		Projetil* p = dynamic_cast<Projetil*>(e);

		if (p != nullptr) {
			if (p->isAtivo()) {
				GC->incluirProjetil(p);
			}
			else {
				GC->removerProjetil(p);
				lista_entes->listaEntidades.remover(e);
			}
		}
	}
}

void Fase::gerenciarColisoes() {
	GC->setLE(lista_entes);
	GC->executar();
	gerenciarMorteInimigo();
	// gerenciarCriacaoProjeteis();
}

Gerenciador_Colisao* Fase::getGC() const {
	return GC;
}

void Fase::executar() {
	gerenciarColisoes();
	aplicarGravidade();
}

void Fase::carregarJogo() {
	std::ifstream arq("save.txt");
	if (!arq.is_open()) {
		std::cerr << "Erro ao abrir arquivo de salvamento.\n";
		return;
	}

	std::string tipo;
	while (arq >> tipo) {
		if (tipo == "JOGADOR") {
			float x, y, velocidade, direcaoMartelo;
			int vidas, pontos;
			arq >> x >> y >> vidas >> velocidade >> pontos >> direcaoMartelo;

			Jogador* j = new Jogador();
			j->setPos(x, y);
			j->setVidas(vidas);
			j->setVelocidade(velocidade);
			//j->setPontos(pontos);

			lista_entes->listaEntidades.incluir(j);
		}

		// Adicione aqui os blocos para: INIMIGO, TRONCO, ESPINHO, BOMBA etc.
	}

	arq.close();
}




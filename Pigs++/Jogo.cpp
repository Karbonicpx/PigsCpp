#include "Jogo.h"

using namespace PigsCpp;
using namespace Gerenciadores;
using namespace Fases;
using namespace Entidades::Personagens;

Jogo::Jogo(int idFase) :
    jogador1(nullptr),
    jogador2(nullptr),
    GG(*Gerenciador_Grafico::getInstancia()),
    idFase(idFase),
    fase(nullptr)
{
    

    // Instanciar fase
    if (idFase == 1) {
        fase = new Floresta();
    }
    else if (idFase == 2) {
        fase = new Subterraneo();
    }
    else {
        fase = new Floresta(); // fallback
    }

    // Instanciar jogadores
    jogador1 = new Jogador("textures/Jogador1.png", true, fase->getListaEntidades());
    jogador2 = new Jogador("textures/Jogador2.png", false, fase->getListaEntidades());
    fase->setJogadores(jogador1, jogador2);

    Ente::setGG(Gerenciador_Grafico::getInstancia());
}

Jogo::~Jogo() {
    if (fase != nullptr) {
        delete fase;
        fase = nullptr;
    }
    if (jogador1 != nullptr) {
        delete jogador1;
        jogador1 = nullptr;
    }
    if (jogador2 != nullptr) {
        delete jogador2;
        jogador2 = nullptr;
    }
}

void Jogo::executar() {
    fase->criarEntidades(&GG);

    // Para salvar:
    if (sf::Keyboard::isKeyPressed(Key::F5)) {
        SaveManager::salvarJogo(fase, "save.txt");
    }
    // Para carregar:
    if (sf::Keyboard::isKeyPressed(Key::F9)) {
        SaveManager::carregarJogo(fase);
    }

    while (GG.estaAberta()) {
        while (const std::optional<sf::Event> evento = GG.getWindow()->pollEvent()) {
            if (evento->is<sf::Event::Closed>()) {
                GG.fechar();
            }
        }

        executarEntidades(fase);
        fase->executar();

        // Verifica se precisa trocar de fase
        if (fase->getGC()->getTrocarFase()) {


            int idNovaFase = fase->getGC()->getIdNovaFase();
            // Reseta o estado de troca
            fase->getGC()->resetarTrocaFase();

            // Libera a fase atual da memória
            delete fase;
            fase = nullptr;

            if (idNovaFase == 2) {
                fase = new Subterraneo();
            }
            else {
                GG.fechar();
                return;
            }

            idFase = idNovaFase;

            // Configura jogadores na nova fase
            fase->setJogadores(jogador1, jogador2);
            fase->criarEntidades(&GG);

         
        }

        GG.clear();
        fase->desenharTileset(&GG, "textures/Floresta.png");
        desenharEntidades(fase);
        GG.mostrar();
    }
}

   

void Jogo::executarEntidades(Fase* f) {
    for (int i = 0; i < f->getListaEntidades()->listaEntidades.getLen(); i++) {
        Entidade* temp = f->getListaEntidades()->listaEntidades.getItem(i);
        temp->executar();
    }
}

void Jogo::desenharEntidades(Fase* f) {
    for (int i = 0; i < f->getListaEntidades()->listaEntidades.getLen(); i++) {
        Entidade* temp = f->getListaEntidades()->listaEntidades.getItem(i);
        temp->desenhar();
    }
}

Fase* Jogo::getFase() const {
    return fase;
}
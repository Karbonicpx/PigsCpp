#include "Jogo.h"

using namespace PigsCpp::Gerenciadores;
using namespace PigsCpp::Entidades::Personagens;
using namespace PigsCpp::Fases;

// Construtora: Necessário inicializar as variáveis dentro do construtor porém forá das { },
// Por conta da versão do C++ de 2003


Jogo::Jogo() :
// O que está acontecendo aqui?
// O gerenciador gráfico está no modelo de projeto chamado "singleton"
// Nesse modelo, fazemos com que apenas uma instância static de uma classe específica possa existir
// Então, estamos fazendo com que GG receba essa instância como variável
// Assim, só podendo existir um GG por jogo
 GG(*Gerenciador_Grafico::getInstancia())
{
    // Inicializando jogador
    jogador1 = new Jogador(true);
    jogador2 = new Jogador(false);
    fase = new Castelo();
    fase->setJogadores(jogador1, jogador2);

    // Fazendo com que os entes tenham sua variável pGG apontando para a instância única
    Ente::setGG(Gerenciador_Grafico::getInstancia());
    
   
}

Jogo::~Jogo() {
}

void Jogo::executar() {

    inicializar(fase, "textures/Castelo.png");

}

void Jogo::inicializar(Fases::Castelo* f, std::string texturePath) {
    f->criarEntidades(&GG);

    while (GG.estaAberta())
    {
        // Loop que vai rodar para cada frame do jogo
        while (const std::optional event = GG.getWindow()->pollEvent())
        {
            // Quando a janela fechar, o jogo fecha
            if (event->is<sf::Event::Closed>())
                GG.fechar();
        }


        // Aqui onde vai ser executado todos as entidades do jogo
        executarEntidades(f);

        // Tratamento de colisões da fase e gravidade
        f->executar();
        // Renderização (sempre no ciclo clear --> draw --> display)
        GG.clear();
        f->desenharTileset(&GG, texturePath);
        desenharEntidades(f);
        GG.mostrar();
    }
}

void Jogo::desenharEntidades(Fases::Castelo* f) {
   
    for (int i = 0; i < f->getListaEntidades()->listaEntidades.getLen(); i++) {

        Entidade* temp = f->getListaEntidades()->listaEntidades.getItem(i);
        temp->desenhar();
    }
}

void Jogo::executarEntidades(Fases::Castelo* f) {
    // Toda entidade que faz alguma coisa, deve ter seu método executar, na qual esse loop vai chamar
    for (int i = 0; i < f->getListaEntidades()->listaEntidades.getLen(); i++) {

        Entidade* temp = f->getListaEntidades()->listaEntidades.getItem(i);
        temp->executar();
    }
    
}

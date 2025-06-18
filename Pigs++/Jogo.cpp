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
    jogador1 = new Jogador();
    fase = new Floresta();
    fase->setJogadores(jogador1);

    // Fazendo com que os entes tenham sua variável pGG apontando para a instância única
    Ente::setGG(Gerenciador_Grafico::getInstancia());
    
   
}

Jogo::~Jogo() {
}

void Jogo::inicializar(Fases::Floresta* f, std::string texturePath) {
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


        
        // Toda entidade que faz alguma coisa, deve ter seu método executar, na qual esse loop vai chamar
        for (int i = 0; i < f->getListaEntidades()->listaEntidades.getLen(); i++) {

            Entidade* temp = f->getListaEntidades()->listaEntidades.getItem(i);
            temp->executar();
        }
        // Renderização (sempre no ciclo clear --> draw --> display)
        GG.clear();
        f->desenharTileset(&GG, texturePath);
        for (int i = 0; i < f->getListaEntidades()->listaEntidades.getLen(); i++) {

            Entidade* temp = f->getListaEntidades()->listaEntidades.getItem(i);
            temp->desenhar();
        }
        GG.mostrar();
    }
}
void Jogo::executar() {

    inicializar(fase, "textures/Floresta.png");
    
}
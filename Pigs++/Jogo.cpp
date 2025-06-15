#include "Jogo.h"

using namespace PigsCpp::Gerenciadores;
using namespace PigsCpp::Entidades::Personagens;
using namespace PigsCpp::Fases;

// Construtora: Necessário inicializar as variáveis dentro do construtor porém forá das { },
// Por conta da versão do C++ de 2003


Jogo::Jogo():
 f2(nullptr),
// O que está acontecendo aqui?
// O gerenciador gráfico está no modelo de projeto chamado "singleton"
// Nesse modelo, fazemos com que apenas uma instância static de uma classe específica possa existir
// Então, estamos fazendo com que GG receba essa instância como variável
// Assim, só podendo existir um GG por jogo
 GG(*Gerenciador_Grafico::getInstancia())
{
    // Inicializando jogador
    jogador1 = new Jogador();
    f1 = new Floresta();
    f1->setJogadores(jogador1);

    // Fazendo com que os entes tenham sua variável pGG apontando para a instância única
    Ente::setGG(Gerenciador_Grafico::getInstancia());
    

}

Jogo::~Jogo() {
}

void Jogo::executar() {

    f1->criarEntidades(&GG);
    while (GG.estaAberta())
    {
        // Loop que vai rodar para cada frame do jogo
        while (const std::optional event = GG.getWindow()->pollEvent())
        {
            // Quando a janela fechar, o jogo fecha
            if (event->is<sf::Event::Closed>())
                GG.fechar();
        }

        // Toda entidade que faz alguma coisa, deve ter seu método executar 
        // Chamado embaixo desse comentário
        jogador1->executar();
       

        // Renderização (sempre no ciclo clear --> draw --> display)
        GG.clear();
		f1->desenharTileset(&GG, "textures/Floresta.png");
        for (int i = 0; i < f1->getListaEntidades()->listaEntidades.getLen(); i++) {

            Entidade* temp = f1->getListaEntidades()->listaEntidades.getItem(i);
            temp->desenhar();
        }
        GG.mostrar();
    }
}
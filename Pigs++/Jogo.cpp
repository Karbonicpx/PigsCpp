#include "Jogo.h"

using namespace PigsCpp::Gerenciadores;
using namespace PigsCpp::Entidades::Personagens;
using namespace PigsCpp::Fases;

// Construtora: Necess�rio inicializar as vari�veis dentro do construtor por�m for� das { },
// Por conta da vers�o do C++ de 2003


Jogo::Jogo():

// O que est� acontecendo aqui?
// O gerenciador gr�fico est� no modelo de projeto chamado "singleton"
// Nesse modelo, fazemos com que apenas uma inst�ncia static de uma classe espec�fica possa existir
// Ent�o, estamos fazendo com que GG receba essa inst�ncia como vari�vel
// Assim, s� podendo existir um GG por jogo
 GG(*Gerenciador_Grafico::getInstancia())
{
    // Inicializando jogador
    jogador1 = new Jogador();
    f = new Fase(jogador1, "fasesjson/Floresta.json");

    // Fazendo com que os entes tenham sua vari�vel pGG apontando para a inst�ncia �nica
    Ente::setGG(Gerenciador_Grafico::getInstancia());
    

}

Jogo::~Jogo() {
}

void Jogo::executar() {

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

        // Toda entidade que faz alguma coisa, deve ter seu m�todo executar 
        // Chamado embaixo desse coment�rio
        jogador1->executar();
       

        // Renderiza��o (sempre no ciclo clear --> draw --> display)
        GG.clear();
		f->desenharPlataformas(&GG, "textures/Floresta.png");
        for (int i = 0; i < f->getListaEntidades()->listaEntidades.getLen(); i++) {

            Entidade* temp = f->getListaEntidades()->listaEntidades.getItem(i);
            temp->desenhar();
        }
        GG.mostrar();
    }
}
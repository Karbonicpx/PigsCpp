#include "Jogo.h"

using namespace PigsCpp;

// Construtora: Necess�rio inicializar as vari�veis dentro do construtor por�m for� das { },
// Por conta da vers�o do C++ de 2003
Jogo::Jogo() :
    
    // Janela que vai ser usada no projeto
    window(sf::VideoMode({ 1000, 1000 }), "Pigs++")
{
    jogador1.setJanela(&window);
    jogador1.setPos(250.f, 100.f);
   
};

Jogo::~Jogo() {
}
const void Jogo::executar() {

    
    // Loop que vai executar em cada frame do jogo, para verifica��o de eventos
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Chame todas as fun��es de executarentre o while e window.clear
        jogador1.executar();
       
        // ATEN��O:
        // Para toda entidade, ela precisa ser desenhada entre o clear e display
        // Por conta do ciclo clear --> draw --> display
        window.clear();
        jogador1.desenhar();
        window.display();
    }
}

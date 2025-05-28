#include "Jogo.h"

using namespace PigsCpp;


Jogo::Jogo():
    // Construtora: Necessário inicializar as variáveis dentro do construtor porém forá das { },
    // Por conta da versão do C++ de 2003

	window(sf::VideoMode({ 1000, 1000 }), "Pigs++"),
	shape(sf::Vector2f(100.f, 100.f))
{
	shape.setFillColor(sf::Color::Green);
}

Jogo::~Jogo() {

}
const void Jogo::executar() {

    // Carregando a textura do arquivo
    // sf::Texture texture;
    // texture.loadFromFile("texture.png");
    // 
    // Loop que vai executar em cada frame do jogo, para verificação de eventos
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }


        // Teclado, movendo o objeto para a direita
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            shape.move(sf::Vector2f(0.1f, 0.f));
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}

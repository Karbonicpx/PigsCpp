#include "Inimigo.h"

using namespace PigsCpp::Entidades::Personagens;

Inimigo::Inimigo(const std::string texturePath, const float bodyX, const float bodyY, const float v, const int vida):
    Personagem(texturePath, bodyX, bodyY, v, vida), 
    direcao(1){
    
    // Aleatorizando o nivel maldade de 1 a 3
    nivel_maldade = (rand() % 3) + 1;
}

Inimigo::Inimigo():Personagem(), direcao(1), nivel_maldade(0){
   
}

Inimigo::~Inimigo(){
    setMaldade(-1);
}



const int Inimigo::getMaldade() const {
    return nivel_maldade;
}
void Inimigo::setMaldade(const int m){
    nivel_maldade = m;
}

void Inimigo::inverterDir() {
    direcao *= -1;

    // Pega a escala atual
    sf::Vector2f escala = corpo.getScale();

    // Inverte o eixo X (mantém Y)
    corpo.setScale(sf::Vector2f( - escala.x, escala.y));

    // Ajusta a origem para não ficar desalinhado
    sf::Vector2f origem = corpo.getOrigin();
    if (direcao == -1) {
        corpo.setOrigin(sf::Vector2f(0.f, origem.y));
    }
    else {
        corpo.setOrigin(sf::Vector2f(corpo.getSize().x, origem.y));
    }
}
void Inimigo::salvarDataBuffer(){        // terminar

}

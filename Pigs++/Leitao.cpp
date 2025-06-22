#include "Leitao.h"

using namespace PigsCpp::Entidades::Personagens;

Leitao::Leitao() : 
    Inimigo("textures/Leitao.png", 25.0f, 25.0f, gerarAleatorioFloat(1.5f, 2.5f), 1),
    raio(gerarAleatorioFloat(20.0f, 30.0f))
{
    // Cor do leitao para visualizacao
    corpo.setFillColor(sf::Color::Magenta);
   
    setMaldade(1);

    direcao = -1;
}


Leitao::~Leitao() {

}
void Leitao::executar() {
    
    mover();
}
void Leitao::danificar(Jogador* p) {
    // Dano ao jogador
    if (p) {
        p->setVidas(p->getVidas() - getMaldade());
    }
}


void Leitao::salvar() {
    // Implementar logica de salvamento
}


void Leitao::mover() {

    sf::Vector2f deslocamento(velocidade * direcao, 0.f);
    corpo.move(deslocamento);

    float posX = corpo.getPosition().x;
    float limiteEsquerda = posInicial - raio;
    float limiteDireita = posInicial + raio;

    if (posX <= limiteEsquerda) {
        corpo.setPosition(sf::Vector2f(limiteEsquerda, corpo.getPosition().y));
        direcao = 1;
    }
    else if (posX >= limiteDireita) {
        corpo.setPosition(sf::Vector2f(limiteDireita, corpo.getPosition().y));
        direcao = -1;
    }
}

void Leitao::setRaio(const float r) {
    raio = r;
}

float Leitao::getRaio() const {
    return raio;
}



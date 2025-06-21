#include "Leitao.h"

using namespace PigsCpp::Entidades::Personagens;

Leitao::Leitao() : 
    Inimigo(gerarAleatorioFloat(1.0f, 2.0f), 1),
    raio(gerarAleatorioFloat(15.0f, 20.0f))
{
    // Cor do leitao para visualizacao
    corpo.setFillColor(sf::Color::Magenta);
<<<<<<< Updated upstream
   
=======
    setMaldade(1);
	
>>>>>>> Stashed changes
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



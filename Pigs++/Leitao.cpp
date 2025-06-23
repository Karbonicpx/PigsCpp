#include "Leitao.h"

using namespace PigsCpp::Entidades::Personagens;

Leitao::Leitao() : 
    Inimigo("textures/Leitao.png", 25.0f, 25.0f, gerarAleatorioFloat(1.5f, 2.2f), 1),
    raio(gerarAleatorioFloat(20.0f, 30.0f))
{
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


void Leitao::salvar(std::ofstream& arq) {
    arq << "LEITAO ";
    Inimigo::salvarDataBuffer(arq);
    arq << raio << std::endl;
}


void Leitao::mover() {

    
    sf::Vector2f deslocamento(velocidade * direcao, 0.f);
    corpo.move(deslocamento);

    float posX = corpo.getPosition().x;
    float limite = posInicial + direcao * raio;

    if ((direcao == 1 && posX >= limite) || (direcao == -1 && posX <= limite)) {
        corpo.setPosition(sf::Vector2f(limite, corpo.getPosition().y));
        inverterDir();
    }
}

void Leitao::setRaio(const float r) {
    raio = r;
}

float Leitao::getRaio() const {
    return raio;
}



#include "Espinho.h"

using namespace PigsCpp;
using namespace Entidades;
                                                                                        
Espinho::Espinho():
    Obstaculo("textures/Espinho.png", 32.0f, 21.0f, true), 
    danosidade((rand() % 3) + 1)  { // 1 - 3
}
Espinho::~Espinho() {

}
void Espinho::executar() {

}
void Espinho::obstaculizar(Jogador* p) { // Método chamado quando o jogador colide com o espinho
    if (p == nullptr) {
        return;
    }

    sf::Vector2f posEnt = p->getCorpo().getPosition();
    sf::Vector2f tamEnt = p->getCorpo().getSize();
    sf::Vector2f posEsp = corpo.getPosition();
    sf::Vector2f tamEsp = corpo.getSize();

    // Calcula bordas
    float entLeft = posEnt.x;
    float entRight = posEnt.x + tamEnt.x;
    float entTop = posEnt.y;
    float entBottom = posEnt.y + tamEnt.y;

    float espLeft = posEsp.x;
    float espRight = posEsp.x + tamEsp.x;
    float espTop = posEsp.y;
    float espBottom = posEsp.y + tamEsp.y;

    // Verifica interseção
    bool colidindo = (entRight > espLeft &&
        entLeft < espRight &&
        entBottom > espTop &&
        entTop < espBottom);

    if (!colidindo)
        return;

    // Se veio de cima (pé do jogador toca o topo do espinho)
    if (entBottom >= espTop && entTop < espTop) {
        // Alinha no topo
        p->setPos(entLeft, espTop - tamEnt.y);

        // Aplica dano
        if (p != nullptr) {
            int vidas = p->getVidas();
            p->setVidas(vidas - danosidade);
        }
    }
    else {
        // Bloqueia pelas laterais e por baixo, igual a um bloco

        // Calcula profundidade da interseção
        float sobreX = std::min(entRight, espRight) - std::max(entLeft, espLeft);
        float sobreY = std::min(entBottom, espBottom) - std::max(entTop, espTop);

        if (sobreX < sobreY) {
            // Colisão no eixo X
            if (entLeft < espLeft) {
                p->setPos(espLeft - tamEnt.x, entTop); // Pela esquerda
            }
            else {
                p->setPos(espRight, entTop); // Pela direita
            }
        }
        else {
            // Colisão no eixo Y (embaixo)
            if (entTop > espTop) {
                p->setPos(entLeft, espBottom); // Por baixo
            }
        }
    }
}
void Espinho::salvar(std::ofstream& arq) {
    arq << "ESPINHO ";
    salvarDataBuffer(arq);
    arq << danosidade << std::endl;

}
void Espinho::salvarDataBuffer(std::ofstream& arq) {
    Obstaculo::salvarDataBuffer(arq);
}
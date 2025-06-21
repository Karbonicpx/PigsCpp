#include "Bloco.h"

using namespace PigsCpp::Entidades;
Bloco::Bloco() : Entidade(false, true), blockSize(32.0f)  {

	// Deixando ele "invisivel"
	corpo.setFillColor(sf::Color(255, 255, 255, 0));
}

Bloco::~Bloco(){}

void Bloco::setSize(const float size) { blockSize = size; }
float Bloco::getSize() const { return blockSize; }
void Bloco::executar() {}

void Bloco::salvar() {

}

// Método que vai impedir da entidade atravessar o bloco

void Bloco::blocar(Entidade* e) {
    
    if (e == nullptr) {
        return;
    }

    sf::FloatRect rectEnt = e->getCorpo().getGlobalBounds();
    sf::FloatRect rectBloco = corpo.getGlobalBounds();

    float left = std::max(rectEnt.position.x, rectBloco.position.x);
    float top = std::max(rectEnt.position.y, rectBloco.position.y);
    float right = std::min(rectEnt.position.x + rectEnt.size.x, rectBloco.position.x + rectBloco.size.x);
    float bottom = std::min(rectEnt.position.y + rectEnt.size.y, rectBloco.position.y + rectBloco.size.y);

    float interWidth = right - left;
    float interHeight = bottom - top;

    if (interWidth <= 0 || interHeight <= 0) {
        return;
    }

    if (interWidth < interHeight) {
        // Colisão no eixo X (esquerda ou direita)
        if (rectEnt.position.x < rectBloco.position.x) {
            // Pela esquerda
            e->setPos(rectBloco.position.x - rectEnt.size.x, rectEnt.position.y);

           
        }
        else {
            // Pela direita
            e->setPos(rectBloco.position.x + rectBloco.size.x, rectEnt.position.y);

            
        }
    }
    else {
        // Colisão no eixo Y (cima ou baixo)
        if (rectEnt.position.y < rectBloco.position.y) {
            // Por cima (pé no chão)
            e->setPos(rectEnt.position.x, rectBloco.position.y - rectEnt.size.y);

            // Se for um jogador tocando no chão, permite ele pular
            if (dynamic_cast<Jogador*>(e) != nullptr) {
                dynamic_cast<Jogador*>(e)->setPodePular(true);
			}
        }
        else {
            // Por baixo (bateu no teto)
            e->setPos(rectEnt.position.x, rectBloco.position.y + rectBloco.size.y);
        }
    }
    
}

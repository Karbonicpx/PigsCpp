#include "Bloco.h"

using namespace PigsCpp::Entidades;
Bloco::Bloco() : 
    Entidade("textures/Bloco.png", 32.0f, 32.0f, false, false), 
    blockSize(32.0f) {

	// Deixando ele "invisivel"
	corpo.setFillColor(sf::Color(255, 255, 255, 0));
}

Bloco::~Bloco(){}

void Bloco::setSize(const float size) { blockSize = size; }
float Bloco::getSize() const { return blockSize; }
void Bloco::executar() {}

void Bloco::salvar(std::ofstream& arq) {
    Entidade::salvarDataBuffer(arq);
    arq << blockSize << " " << std::endl;
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

    // Colisão no eixo X (esquerda ou direita)
    if (interWidth < interHeight) {

        // Independente daonde a bomba cair, ela tem que ser deletava
        if (dynamic_cast<Bomba*>(e) != nullptr) {
            dynamic_cast<Bomba*>(e)->desativar();
        }
  
        if (rectEnt.position.x < rectBloco.position.x) {

            // Se não for toucinho ou baconzilla, seta a colisão pela esquerda
            if (dynamic_cast<Leitao*>(e) == nullptr && dynamic_cast<Baconzilla*>(e) == nullptr) {
                e->setPos(rectBloco.position.x - rectEnt.size.x, rectEnt.position.y);
            }
              
        }
        else {
            // Pela direita
            

            // Se não for toucinho ou baconzilla, seta a colisão pela direita
            if (dynamic_cast<Leitao*>(e) == nullptr && dynamic_cast<Baconzilla*>(e) == nullptr) {
                e->setPos(rectBloco.position.x + rectBloco.size.x, rectEnt.position.y);
            }
        }
    }

    // Colisão no eixo Y (cima ou baixo)
    else {

        // Independente daonde a bomba cair, ela tem que ser deletada
        if (dynamic_cast<Bomba*>(e) != nullptr) {
            dynamic_cast<Bomba*>(e)->desativar();
        }

        
        if (rectEnt.position.y < rectBloco.position.y) {

            // Se não for toucinho ou baconzilla, seta a colisão por cima
            if (dynamic_cast<Leitao*>(e) == nullptr && dynamic_cast<Baconzilla*>(e) == nullptr) {
                e->setPos(rectEnt.position.x, rectBloco.position.y - rectEnt.size.y);
            }
           

            // Se for um jogador tocando no chão, permite ele pular
            if (dynamic_cast<Jogador*>(e) != nullptr) {
                dynamic_cast<Jogador*>(e)->setPodePular(true);
			}
        }
        else {
            // Se não for toucinho ou baconzilla, seta a colisão por baixo
            if (dynamic_cast<Leitao*>(e) == nullptr && dynamic_cast<Baconzilla*>(e) == nullptr) {
                e->setPos(rectEnt.position.x, rectBloco.position.y + rectBloco.size.y);
            }
           

            if (dynamic_cast<Jogador*>(e) != nullptr) {
                dynamic_cast<Jogador*>(e)->setSofreGravidade(true);
            }
        }
    }
    
}

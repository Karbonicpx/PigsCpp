#include "Lago.h"

using namespace PigsCpp;
using namespace Entidades;
                                                                                    
Lago::Lago():
    Obstaculo("textures/Lago.png", 32.0f, 32.0f, false), 
    largura((rand() % 3) + 1) { // 1 - 3

}
Lago::~Lago() {

}
void Lago::executar(){

}
void Lago::obstaculizar(Jogador* p) {

    sf::Vector2f posLago = corpo.getPosition();
    sf::Vector2f tamLago = sf::Vector2f(corpo.getSize().x + largura, corpo.getSize().y);

    sf::Vector2f posJogador = p->getCorpo().getPosition();
    sf::Vector2f tamJogador = p->getCorpo().getSize();

    // Define os limites do Lago
    float lagoEsquerda = posLago.x;
    float lagoDireita = posLago.x + tamLago.x;
    float lagoTopo = posLago.y;
    float lagoBaixo = posLago.y + tamLago.y;

    // Define os limites do Jogador
    float jogadorEsquerda = posJogador.x;
    float jogadorDireita = posJogador.x + tamJogador.x;
    float jogadorTopo = posJogador.y;
    float jogadorBaixo = posJogador.y + tamJogador.y;

    // Verificar se há interseção (colisão) entre o Lago e o Jogador
    bool colidindo = !(jogadorDireita < lagoEsquerda ||
        jogadorEsquerda > lagoDireita ||
        jogadorBaixo < lagoTopo ||
        jogadorTopo > lagoBaixo);

    if (colidindo) {
        // Jogador dentro da poça — aplica lentidão
        p->setPisandoPoca(true);
    }
    else {
        // Não está colidindo
        p->setPisandoPoca(false);
    }
}
void Lago::salvar(std::ofstream& arq) {

}
void Lago::salvarDataBuffer() {

}
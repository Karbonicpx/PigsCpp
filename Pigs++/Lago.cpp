#include "Lago.h"

using namespace PigsCpp;
using namespace Entidades;

Lago::Lago() :
    Obstaculo("textures/Lago.png", 32.0f, 32.0f, false),
    largura((rand() % 3) + 1) { // 1 - 3

}
Lago::~Lago() {

}
void Lago::executar() {

}
void Lago::obstaculizar(Jogador* p) {


    // Posição e tamanho do lago
    sf::FloatRect hitboxLago = corpo.getGlobalBounds();

    // Aumenta a largura da hitbox de acordo com a quantidade de blocos
    hitboxLago.size.x += largura;


    // Hitbox do jogador
    sf::FloatRect hitboxJogador = p->getCorpo().getGlobalBounds();

    // Verifica se o jogador está dentro da área do lago
    if (hitboxLago.findIntersection(hitboxJogador).has_value()) {
        p->setPisandoPoca(true);
    }
}
void Lago::salvar(std::ofstream& arq) {
    arq << "LAGO ";
    salvarDataBuffer(arq);
    arq << largura << std::endl;
}
void Lago::salvarDataBuffer(std::ofstream& arq) {
    Obstaculo::salvarDataBuffer(arq);
}

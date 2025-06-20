#include "Lago.h"

using namespace PigsCpp;
using namespace Entidades;

Lago::Lago():Obstaculo(true, false), largura(0){
	
    corpo.setFillColor(sf::Color::Blue);

}
Lago::~Lago() {

}
void Lago::executar(){

}
void Lago::obstaculizar(Jogador* p) {
    if (p == nullptr) {
        return;
    }

    // Aplica o efeito de lentidão
    p->setPisandoPoca(true);
}
void Lago::salvar() {

}
void Lago::salvarDataBuffer() {

}
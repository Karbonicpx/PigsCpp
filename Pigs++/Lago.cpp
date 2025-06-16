#include "Lago.h"

using namespace PigsCpp;
using namespace Entidades;

Lago::Lago():Obstaculo(), largura(0){
	corpo.setFillColor(sf::Color::Transparent);

}
Lago::~Lago() {

}
void Lago::executar(){

}
void Lago::obstaculizar(Jogador* p) {
	if (p) {
		p->setVelocidade(0.5); // Reduz a velocidade do jogador ao entrar no lago
	}
}
void Lago::salvar() {

}
void Lago::salvarDataBuffer() {

}
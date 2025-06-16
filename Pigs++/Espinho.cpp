#include "Espinho.h"

using namespace PigsCpp;
using namespace Entidades;

Espinho::Espinho():Obstaculo(), danosidade(1) {
	setDanoso(true);
}
Espinho::~Espinho() {

}
void Espinho::executar() {

}
void Espinho::obstaculizar(Jogador* p) { // Método chamado quando o jogador colide com o espinho
    int vidasAtuais = p->getVidas();
    p->setVidas(vidasAtuais - danosidade);
}
void Espinho::salvar() {

}
void Espinho::salvarDataBuffer() {

}
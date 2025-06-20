#include "Obstaculo.h"

using namespace PigsCpp::Entidades;

Obstaculo::Obstaculo(const bool sV, const bool dN) : Entidade(false, sV), danoso(dN){

}

Obstaculo::Obstaculo() : Entidade(false, false), danoso(false) {

}
Obstaculo::~Obstaculo() {

}
void Obstaculo::salvarDataBuffer() {

}
void Obstaculo::setDanoso(bool dano) {
	danoso = dano;
}
bool Obstaculo::getDanoso() const {
	return danoso;
}


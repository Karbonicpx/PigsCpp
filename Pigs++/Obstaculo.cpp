#include "Obstaculo.h"

using namespace PigsCpp::Entidades;

Obstaculo::Obstaculo() : Entidade(), danoso(false){

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


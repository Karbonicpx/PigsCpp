#include "Obstaculo.h"

using namespace PigsCpp::Entidades;

Obstaculo::Obstaculo(const std::string texturePath, const float bodyX, const float bodyY, const bool dN) :
	Entidade(texturePath, bodyX, bodyY, true, false), 
	danoso(dN){

}

Obstaculo::Obstaculo() : 
	Entidade(), 
	danoso(false) {

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


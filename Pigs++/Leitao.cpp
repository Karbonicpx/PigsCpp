#pragma once
#include "Leitao.h"

using namespace PigsCpp;
using namespace Entidades;
using namespace Personagens;

Leitao::Leitao() : Inimigo(), tamanho(0), forca(0){
    // Cor do leitao para visualizacao
    corpo.setFillColor(sf::Color::Magenta);
}
Leitao::~Leitao() {
    setForca(0);
    setTamanho(0);
}
const void Leitao::executar() {
    // Comportamento do leitao aqui
}
const void Leitao::danificar(Jogador* p) {
    // Dano ao jogador
    if (p) {
        int dano = 10; // Exemplo de dano
        p->setVidas(p->getVidas() - dano);
    }
}
const void Leitao::salvar() {
    // Implementar logica de salvamento
}
const void Leitao::mover(){
    
}
// Getters e Setters
const int Leitao::getForca() const {return forca;} 
const short int Leitao::getTamanho() const {return tamanho;}
const void Leitao::setForca(int f) {forca = f;}
const void Leitao::setTamanho(short int t) {tamanho = t;}

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
void Leitao::executar() {
    // Comportamento do leitao aqui
}
void Leitao::danificar(Jogador* p) {
    // Dano ao jogador
    if (p) {
        int dano = 10; // Exemplo de dano
        p->setVidas(p->getVidas() - dano);
    }
}
void Leitao::salvar() {
    // Implementar logica de salvamento
}
void Leitao::mover(){
    
}
// Getters e Setters
const short int Leitao::getForca() const {return forca;} 
const int Leitao::getTamanho() const {return tamanho;}
void Leitao::setForca(short int f) {forca = f;}
void Leitao::setTamanho(short int t) {tamanho = t;}

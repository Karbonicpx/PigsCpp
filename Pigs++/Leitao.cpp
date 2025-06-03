#pragma once
#include "Leitao.h"

using namespace PigsCpp;
using namespace Entidades;

Leitao::Leitao() : Inimigo(), raio(10.0f), tamanho(0), forca(0){
    // Cor do leitao para visualizacao
    corpo.setFillColor(sf::Color::Magenta);
}
Leitao::~Leitao() {
    setForca(0);
    setTamanho(0);
    setRaio(0.0f);
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
const void Leitao::salvarDataBuffer() {
    // Logica para salvar dados do leitao
}
const void Leitao::salva() {
    // Implementar logica de salvamento
}
const void Leitao::mover(){
    
}
// Getters e Setters
const int Leitao::getForca() {return forca;} 
const int Leitao::getTamanho() {return tamanho;}
const int Leitao::getRaio() {return static_cast<int>(raio);}
const void Leitao::setForca(int f) {forca = f;}
const void Leitao::setTamanho(int t) {tamanho = t;}
const void Leitao::setRaio(float r) {raio = r;}


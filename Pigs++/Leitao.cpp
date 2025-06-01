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
void Leitao::salvarDataBuffer() {
    // Logica para salvar dados do leitao
}
void Leitao::salva() {
    // Implementar logica de salvamento
}
// Getters e Setters
int Leitao::getForca() {return forca;} 
int Leitao::getTamanho() {return tamanho;}
int Leitao::getRaio() {return static_cast<int>(raio);}
void Leitao::setForca(int f) {forca = f;}
void Leitao::setTamanho(int t) {tamanho = t;}
void Leitao::setRaio(float r) {raio = r;}


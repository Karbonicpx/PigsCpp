#pragma once
#include "Toucinho.h"

using namespace PigsCpp;
using namespace Entidades;

Toucinho::Toucinho() : Inimigo(), raio(15.0f), tamanho(0), forca(0) {
    // Cor do tocinho para visualizacao
    corpo.setFillColor(sf::Color::Purple);
}
Toucinho::~Toucinho() {
    setForca(0);
    setTamanho(0);
    setRaio(0.0f);
}
const void Toucinho::executar() {
    // Comportamento do tocinho aqui
}
const void Toucinho::danificar(Jogador* p) {
    // Dano ao jogador
    if (p) {
        int dano = 15; // Exemplo de dano
        p->setVidas(p->getVidas() - dano);
    }
}
const void Toucinho::salva() {
    // Implementar logica de salvamento
}
const void Toucinho::mover() {
    // Implementar logica de movimento
}
// Getters e Setters
const int Toucinho::getForca() {return forca;}
const int Toucinho::getTamanho() {return tamanho;}
const int Toucinho::getRaio() {return static_cast<int>(raio);}
const void Toucinho::setForca(int f) {forca = f;}
const void Toucinho::setTamanho(int t) {tamanho = t;}
const void Toucinho::setRaio(float r) {raio = r;}

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
void Toucinho::executar() {
    // Comportamento do tocinho aqui
}
void Toucinho::danificar(Jogador* p) {
    // Dano ao jogador
    if (p) {
        int dano = 15; // Exemplo de dano
        p->setVidas(p->getVidas() - dano);
    }
}
void Toucinho::salva() {
    // Implementar logica de salvamento
}
// Getters e Setters
int Toucinho::getForca() {return forca;}
int Toucinho::getTamanho() {return tamanho;}
int Toucinho::getRaio() {return static_cast<int>(raio);}
void Toucinho::setForca(int f) {forca = f;}
void Toucinho::setTamanho(int t) {tamanho = t;}
void Toucinho::setRaio(float r) {raio = r;}

#pragma once
#include "Toucinho.h"

using namespace PigsCpp;
using namespace Entidades;
using namespace Personagens;

Toucinho::Toucinho() : Inimigo(), raio(15.0f), tamanho(0), forca(0) {
    // Cor do tocinho para visualizacao
    corpo.setFillColor(sf::Color::Cyan);
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
void Toucinho::salvar() {
    // Implementar logica de salvamento
}
void Toucinho::mover() {
    // Implementar logica de movimento
}
// Getters e Setters
const short int Toucinho::getForca() const {return forca;}
const int Toucinho::getTamanho() const {return tamanho;}
const int Toucinho::getRaio() const {return static_cast<int>(raio);}
void Toucinho::setForca(short int f) {forca = f;}
void Toucinho::setTamanho(int t) {tamanho = t;}
void Toucinho::setRaio(float r) {raio = r;}

#pragma once 
#include "Baconzilla.h"

using namespace PigsCpp;
using namespace Entidades;

Baconzilla::Baconzilla() : Inimigo(), raio(20.0f), tamanho(0), forca(0) {
    // Cor do Baconzilla para visualizacao
    corpo.setFillColor(sf::Color::Red);
}
Baconzilla::~Baconzilla() {
    setForca(0);
    setTamanho(0);
    setRaio(0.0f);
}
void Baconzilla::executar() {
    // Comportamento do Baconzilla aqui
}
void Baconzilla::danificar(Jogador* p) {
    // Dano ao jogador
    if (p) {
        int dano = 20; // Exemplo de dano
        p->setVidas(p->getVidas() - dano);
    }
}
void Baconzilla::salvarDataBuffer() {
    // Logica para salvar dados do Baconzilla
}
void Baconzilla::salva() {
    // Implementar logica de salvamento
}
// Getters e Setters
int Baconzilla::getForca() { return forca; }
int Baconzilla::getTamanho() { return tamanho; }
int Baconzilla::getRaio() { return static_cast<int>(raio); }
void Baconzilla::setForca(int f) { forca = f; }
void Baconzilla::setTamanho(int t) { tamanho = t; }
void Baconzilla::setRaio(float r) { raio = r; }

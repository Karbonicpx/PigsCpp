#include "Baconzilla.h"

using namespace PigsCpp;
using namespace Entidades;
using namespace Personagens;

Baconzilla::Baconzilla(): raio(20.0f), tamanho(0), forca(0) {
    // Cor do Baconzilla para visualizacao
    corpo.setFillColor(sf::Color::Red);
};
Baconzilla::~Baconzilla() {
    setForca(0);
    setTamanho(0);
    setRaio(0.0f);
};
void Baconzilla::executar() {
    // Comportamento do Baconzilla aqui
};
void Baconzilla::danificar(Jogador* p) {
    // Dano ao jogador
    if (p) {
        int dano = 20; // Exemplo de dano
        p->setVidas(p->getVidas() - dano);
    }
};
void Baconzilla::salva() {
    // Implementar logica de salvamento
};
void Baconzilla::mover() {

};
// Getters e Setters
const short int Baconzilla::getForca() const { return forca; }
const int Baconzilla::getTamanho() const { return tamanho; }
const int Baconzilla::getRaio() const { return static_cast<int>(raio); }
void Baconzilla::setForca(short int f) { forca = f; }
void Baconzilla::setTamanho(int t) { tamanho = t; }
void Baconzilla::setRaio(float r) { raio = r; }

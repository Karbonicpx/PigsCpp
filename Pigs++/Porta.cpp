#include "Porta.h"

using namespace PigsCpp::Entidades;
using namespace PigsCpp::Entidades::Personagens;

Porta::Porta(int idProxima) :
    Entidade("textures/Template.png", 32.f, 32.f, false, false),
    podeEntrar(true),
    idProximaFase(idProxima),
    trocarFase(false)
{
    // Corpo invisivel
    corpo.setFillColor(sf::Color(255, 255, 255, 0));

}

Porta::~Porta() {}

void Porta::executar() {
  
}

void Porta::verificarEntrada(Jogador* j) {
    if (j == nullptr) return;

    // Verificar colisão
    if (corpo.getGlobalBounds().findIntersection(j->getCorpo().getGlobalBounds())) {

        j->setEntrandoPorta(true);

        // Verificar tecla pressionada para cima
        if (j->entrouNaPorta()) {

            // Delay de segurança pra não detectar várias vezes
            if (podeEntrar || relogioEntrada.getElapsedTime().asSeconds() > 1.f) {
                podeEntrar = false;
                relogioEntrada.restart();
                trocarFase = true;
            }
        }
        else {
            j->setEntrandoPorta(false);
            podeEntrar = true;
        }
    }
}

bool Porta::getTrocarFase() {
    return trocarFase;
}

int Porta::getIdProxFase() {
    return idProximaFase;
}

void Porta::salvar(std::ofstream& arq) {
    // Se precisar salvar no futuro
    //podeEntrar;
    //int idProximaFase;
    //bool trocarFase;
}
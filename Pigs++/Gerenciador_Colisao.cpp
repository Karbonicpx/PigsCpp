#include "Gerenciador_Colisao.h"
using namespace PigsCpp::Gerenciadores;
using namespace sf;

// Inicializando ponteiros dos jogadores
Gerenciador_Colisao::Gerenciador_Colisao() :
    jog1(nullptr),
    jog2(nullptr)
{

}

// Evitando memory leaks e deletando os ponteiros
Gerenciador_Colisao::~Gerenciador_Colisao() {
    // LObstaculos.clear();
    // LInimigos.clear();
    // LProjetil.clear();
    jog1 = nullptr;
    jog2 = nullptr;
}

// Setando os jogadores
const void Gerenciador_Colisao::setJogadores(Personagens::Jogador* j1, Personagens::Jogador* j2) {
    jog1 = j1;
    jog2 = j2;
}

// Basicamente, vamos verificar quem é quem através dos IDs dos entes
// e adicioná-los às listas de acordo com o "tipo" de entidade que são
const void Gerenciador_Colisao::includeEntidade(Entidade* ent) {
    if (ent->getId() == 3 || ent->getId() == 9 || ent->getId() == 8 || ent->getId() == 11) { // obstaculo
        // LObst.push_back(static_cast<Obstaculos::Obstaculo*>(ent));
    }

    if (ent->getId() == 12) {
        // LObstaculo.push_back(static_cast<Obstaculos::Obstaculo*>(ent));
    }

    else if (ent->getId() == 4 || ent->getId() == 6 || ent->getId() == 7) { // inimigo
        // LInimigo.push_back(static_cast<Personagens::Inimigo*>(ent));
    }

    else if (ent->getId() == 1) { // jogador 1
        // jog1 = static_cast<Personagens::Jogador*>(ent);
    }

    else if (ent->getId() == 2) { // jogador 2
        // jog2 = static_cast<Personagens::Jogador*>(ent);
    }

    else if (ent->getId() == 5) { // projetil
        // LProjetil.push_back(static_cast<Projetil*>(ent));
    }
}

// Removendo as entidades das listas quando elas "morrem" ou saiem da tela
const void Gerenciador_Colisao::removeEntidade(Entidade* ent) {
    if (ent->getId() == 4) {
        // LInimigo.remove(static_cast<Personagens::Inimigo*>(ent));
    }

    if (ent->getId() == 6) {
        // LInimigo.remove(static_cast<Personagens::Inimigo*>(ent));
    }

    else if (ent->getId() == 1) {
        setJogadores(nullptr, jog2);
    }

    else if (ent->getId() == 2) {
        setJogadores(jog1, nullptr);
    }

    else if (ent->getId() == 12) {
        // LObstaculo.remove(static_cast<Obstaculos::Plataforma*>(ent));
    }

}

// Aqui vamos verificar a colisão entre duas entidades
const bool Gerenciador_Colisao::veriColisao(Entidade* ent1, Entidade* ent2) {


    // O que isso significa?
    // Ele está pegando o corpo do jogador, e delimitando uma borda nele
    // Essa borda ocupa toda a área do jogador, por isso tem o tipo de floatRect,
    // Que retorna o valor dessa área

    FloatRect rect1 = ent1->getCorpo().getGlobalBounds();
    FloatRect rect2 = ent2->getCorpo().getGlobalBounds();

    // O que está acontecendo?
    // O find intersection é uma função própria do SFML 3.0
    // Ele vai basicamente retornar a área de sobreposição entre dois corpos
    // Ou seja, quando colidir, uma nova área em que os dois corpos estão "encima" vai ser registrada
    // E para retornar true ou false, usamos .has_value(), que checa se há algum valor numérico nessa comparação
    // Caso tenha, quer dizer que colidiu, então é true. Se não tem, não colidiu, logo é false

    return rect1.findIntersection(rect2).has_value();
}

// Implementar após as listas serem criadas
const void Gerenciador_Colisao::verificaObs() {

}

// Implementar após as listas serem criadas
const void Gerenciador_Colisao::verificaIni() {

}

// Implementar após as listas serem criadas
const void Gerenciador_Colisao::veriProjetil() {

}



// Aqui vamos checar a colisão de todos os tipos de entidade em uma só função
const void Gerenciador_Colisao::executar() {
    verificaIni();
    verificaObs();
    veriProjetil();
};
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
void Gerenciador_Colisao::setJogadores(Personagens::Jogador* j1, Personagens::Jogador* j2) {
    jog1 = j1;
    jog2 = j2;
}


const bool Gerenciador_Colisao::verificarColisao(Entidade* ent1, Entidade* ent2) {


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

void Gerenciador_Colisao::tratarColisoesJogsObstacs() {


}

void Gerenciador_Colisao::tratarColisoesJogsInimgs() {


}

void Gerenciador_Colisao::tratarColisoesJogsBombas() {


}

void Gerenciador_Colisao::incluirInimigo() {


}

void Gerenciador_Colisao::incluirObstaculo() {

}

void Gerenciador_Colisao::incluirBomba() {

}

void Gerenciador_Colisao::removerInimigo() {

}

void Gerenciador_Colisao::removerObstaculo() {

}

void Gerenciador_Colisao::removerBomba() {

}
// Aqui vamos checar a colisão de todos os tipos de entidade em uma só função
void Gerenciador_Colisao::executar() {
    // verificaIni();
    // verificaObs();
    // veriProjetil();
};
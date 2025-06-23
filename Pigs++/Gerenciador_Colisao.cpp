#include "Gerenciador_Colisao.h"
using namespace PigsCpp::Gerenciadores;
using namespace sf;

// Inicializando ponteiros dos jogadores
Gerenciador_Colisao::Gerenciador_Colisao() :
    jog1(nullptr),
    jog2(nullptr),
    LEsGC(nullptr),
    trocarFase(false),
    idNovaFase(-1)
{
    LOs.clear();
    LBs.clear();
    LIs.clear();
}

// Evitando memory leaks e deletando os ponteiros
Gerenciador_Colisao::~Gerenciador_Colisao() {
    jog1 = nullptr;
    jog2 = nullptr;
    LEsGC->listaEntidades.limpar();
    LOs.clear();
    LBs.clear();
    LIs.clear();
    delete(LEsGC);
}

// Setando os jogadores
void Gerenciador_Colisao::setJogadores(Personagens::Jogador* j1, Personagens::Jogador* j2) {
    jog1 = j1;
    jog2 = j2;
}

void Gerenciador_Colisao::setLE(ListaEntidades* LE) {
    LEsGC = LE;
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

// Jogador vs Obstaculo
void Gerenciador_Colisao::tratarColisoesJogsObstacs() {
    for (std::list<Obstaculo*>::iterator it = LOs.begin(); it != LOs.end(); it++) {
        Obstaculo* obs = *it;

        if (jog1 != nullptr && verificarColisao(jog1, obs)) {
            obs->obstaculizar(jog1);
        }
        if (jog2 != nullptr && verificarColisao(jog2, obs)) {
            obs->obstaculizar(jog2);
        }
    }
}

// Jogador vs Inimigo
void Gerenciador_Colisao::tratarColisoesJogsInimgs() {
    for (std::vector<Inimigo*>::iterator it = LIs.begin(); it != LIs.end(); it++) {
        Inimigo* ini = *it;

        if (jog1 != nullptr && verificarColisao(jog1, ini)) {
            ini->danificar(jog1);
        }
        if (jog2 != nullptr && verificarColisao(jog2, ini)) {
            ini->danificar(jog2);
        }
    }
}

// Jogador vs Bombas
void Gerenciador_Colisao::tratarColisoesJogsBombas() {
    for (std::set<Bomba*>::iterator it = LBs.begin(); it != LBs.end(); it++) {
        Bomba* b = *it;

        // Fazer depois
        if (jog1 != nullptr && verificarColisao(jog1, b)) {
           
            jog1->setVidas(jog1->getVidas() - b->explodir());
        }
        if (jog2 != nullptr && verificarColisao(jog2, b)) {

            jog2->setVidas(jog1->getVidas() - b->explodir());
        }
    }
}

void Gerenciador_Colisao::tratarColisoesJogsPortas() {
    for (int i = 0; i < LEsGC->listaEntidades.getLen(); i++) {
            
        Entidade* ent = LEsGC->listaEntidades.getItem(i);

        if (dynamic_cast<Porta*>(ent) != nullptr) {

            
            dynamic_cast<Porta*>(ent)->verificarEntrada(jog1);

            if (jog2 != nullptr) { dynamic_cast<Porta*>(ent)->verificarEntrada(jog2); }  

            trocarFase = dynamic_cast<Porta*>(ent)->getTrocarFase();
            idNovaFase = dynamic_cast<Porta*>(ent)->getIdProxFase();
        }
    }
}

// Isso aqui é um tratamento exclusivo, pois bloco deriva apenas de entidade
void Gerenciador_Colisao::tratarColisoesEntsBlocos() {
    
    for (int i = 0; i < LEsGC->listaEntidades.getLen(); i++) {

        Entidade* ent = LEsGC->listaEntidades.getItem(i);

        // Se a entidade for nula ou não ser uma entidade com ID (obstáculo e bloco)
        if (ent == nullptr || dynamic_cast<Bloco*>(ent) != nullptr || ent->getId() < 0) {
            continue;
        }

        // Agora ent é qualquer entidade que NÃO seja bloco
        // Testa contra TODOS os blocos da lista
        for (int j = 0; j < LEsGC->listaEntidades.getLen(); j++) {

            Entidade* b = LEsGC->listaEntidades.getItem(j);

            // Verifica se b é um bloco
            if (b != nullptr && dynamic_cast<Bloco*>(b) != nullptr) {

				// Verifica se a entidade colide com o bloco
                if (ent != nullptr && verificarColisao(ent, b)) {
                    dynamic_cast<Bloco*>(b)->blocar(ent);

                  
                }
            }
        }
    }
    
}

void Gerenciador_Colisao::tratarColisoesInimTroncos() {

    for (int i = 0; i < LEsGC->listaEntidades.getLen(); i++) {

        Entidade* ent = LEsGC->listaEntidades.getItem(i);

        // Verifica se é um inimigo válido (tem ID e é realmente um inimigo)
        Inimigo* inim = dynamic_cast<Inimigo*>(ent);

        if (inim == nullptr || inim->getId() < 0) {
            continue;
        }

        // Verifica contra todos os troncos da lista
        for (int j = 0; j < LEsGC->listaEntidades.getLen(); j++) {

            Entidade* e = LEsGC->listaEntidades.getItem(j);

            // Se não for tronco, ignora
            Tronco* tronco = dynamic_cast<Tronco*>(e);
            if (tronco == nullptr) {
                continue;
            }

            // Verifica se há colisão entre o inimigo e o tronco
            if (verificarColisao(inim, tronco)) {
                tronco->obstaculizarIni(inim);
            }
        }
    }
}

// Incluir entidades
void Gerenciador_Colisao::incluirInimigo(Inimigo* ini) {
    LIs.push_back(ini);
    
}

void Gerenciador_Colisao::incluirObstaculo(Obstaculo* obs) {
    LOs.push_back(obs);
}

void Gerenciador_Colisao::incluirBomba(Bomba* b) {
    LBs.insert(b);
}

// Remover entidades
void Gerenciador_Colisao::removerInimigo(Inimigo* ini) {
    std::vector<Inimigo*>::iterator it = std::find(LIs.begin(), LIs.end(), ini);
    if (it != LIs.end()) {
        LIs.erase(it);
    }
}

void Gerenciador_Colisao::removerBomba(Bomba* b) {
    std::set<Bomba*>::iterator it = std::find(LBs.begin(), LBs.end(), b);
    if (it != LBs.end()) {
        LBs.erase(it);
    }
}

const int Gerenciador_Colisao::getIdNovaFase() const {
    return idNovaFase;
}

const bool Gerenciador_Colisao::getTrocarFase() const {
    return trocarFase;
}

void Gerenciador_Colisao::resetarTrocaFase() {
    trocarFase = false;
}

// Executa todas as colisões da fase
void Gerenciador_Colisao::executar() {
    tratarColisoesJogsObstacs();
    tratarColisoesJogsInimgs();
    tratarColisoesJogsBombas();
    tratarColisoesEntsBlocos();
    tratarColisoesInimTroncos();
    tratarColisoesJogsPortas();
}
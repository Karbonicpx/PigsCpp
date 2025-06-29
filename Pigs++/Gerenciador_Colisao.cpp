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
    LPs.clear();
    LIs.clear();
}

// Evitando memory leaks e deletando os ponteiros
Gerenciador_Colisao::~Gerenciador_Colisao() {
    // Limpando ponteiros de obstáculos
    for (std::list<Obstaculo*>::iterator it = LOs.begin(); it != LOs.end(); ++it) {
        if (*it != nullptr) {
            delete* it;
        }
    }
    LOs.clear();

    // Limpando ponteiros de inimigos
    for (std::vector<Inimigo*>::iterator it = LIs.begin(); it != LIs.end(); ++it) {
        if (*it != nullptr) {
            delete* it;
        }
    }
    LIs.clear();

    // Limpando ponteiros de projéteis
    for (std::set<Projetil*>::iterator it = LPs.begin(); it != LPs.end(); ++it) {
        if (*it != nullptr) {
            delete* it;
        }
    }
    LPs.clear();

    // Limpando ponteiros dos jogadores
    jog1 = nullptr;
    jog2 = nullptr;
<<<<<<< Updated upstream
    LEsGC->listaEntidades.limpar();
    LOs.clear();
    LPs.clear();
    LIs.clear();

    delete(LEsGC);
    LEsGC = nullptr;
=======

    // Limpando lista de entidades gerais
    if (LEsGC != nullptr) {
        LEsGC->listaEntidades.limpar();
        delete LEsGC;
        LEsGC = nullptr;
    }
>>>>>>> Stashed changes
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
    // O find intersection é uma função própria do SFML 3.0.0
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

        if (jog1 != nullptr && jog1->getVidas() > 0 && verificarColisao(jog1, obs)) {
            obs->obstaculizar(jog1);
        }
        if (jog2 != nullptr && jog2->getVidas() > 0 && verificarColisao(jog2, obs)) {
            obs->obstaculizar(jog2);
        }
    }
}

// Jogador vs Inimigo
void Gerenciador_Colisao::tratarColisoesJogsInimgs() {
    for (std::vector<Inimigo*>::iterator it = LIs.begin(); it != LIs.end(); it++) {
        Inimigo* ini = *it;

        if (jog1 != nullptr && jog1->getVidas() > 0 && verificarColisao(jog1, ini) && ini->getVidas() > 0) {
            ini->danificar(jog1);
        }
        if (jog2 != nullptr && jog2->getVidas() > 0 && verificarColisao(jog2, ini) && ini->getVidas() > 0) {
            ini->danificar(jog2);
        }
    }
}

// Jogador vs Bombas
void Gerenciador_Colisao::tratarColisoesJogsBombas() {
    for (std::set<Projetil*>::iterator it = LPs.begin(); it != LPs.end(); it++) {
        Projetil* p = *it;

        Bomba* b = dynamic_cast<Bomba*>(p);
<<<<<<< Updated upstream
        // Fazer depois
        if (jog1 != nullptr && jog1->getVidas() > 0 && verificarColisao(jog1, b)) {
           
=======

        if (jog1 != nullptr && jog1->getVidas() > 0 && verificarColisao(jog1, b)) {

>>>>>>> Stashed changes
            jog1->setVidas(jog1->getVidas() - b->colidir());
            b->desativar();
        }
        if (jog2 != nullptr && jog2->getVidas() > 0 && verificarColisao(jog2, b)) {

            jog2->setVidas(jog1->getVidas() - b->colidir());
            b->desativar();
        }
    }
}

// Usa a lista de entidades pois porta é uma entidade
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
    for (std::vector<Inimigo*>::iterator itInim = LIs.begin(); itInim != LIs.end(); ++itInim) {
        Inimigo* inim = *itInim;

        if (inim == nullptr || inim->getId() < 0) {
            continue;
        }

        for (std::list<Obstaculo*>::iterator itObs = LOs.begin(); itObs != LOs.end(); ++itObs) {
            Tronco* tronco = dynamic_cast<Tronco*>(*itObs);

            if (tronco == nullptr) {
                continue;
            }

            if (verificarColisao(inim, tronco)) {
                tronco->obstaculizarIni(inim);
            }
        }
    }
}

void Gerenciador_Colisao::tratarColisoesInimMartelos() {
<<<<<<< Updated upstream
    for (int i = 0; i < LEsGC->listaEntidades.getLen(); i++) {

        Entidade* ent = LEsGC->listaEntidades.getItem(i);
        Inimigo* inim = dynamic_cast<Inimigo*>(ent);
=======
    for (std::vector<Inimigo*>::iterator itInim = LIs.begin(); itInim != LIs.end(); ++itInim) {
        Inimigo* inim = *itInim;
>>>>>>> Stashed changes

        if (inim == nullptr || inim->getId() < 0) {
            continue;
        }

<<<<<<< Updated upstream
        for (int j = 0; j < LEsGC->listaEntidades.getLen(); j++) {

            Entidade* e = LEsGC->listaEntidades.getItem(j);
            Martelo* m = dynamic_cast<Martelo*>(e);

            if (m == nullptr) {
=======

        for (int i = 0; i < LEsGC->listaEntidades.getLen(); i++) {
            Entidade* ent = LEsGC->listaEntidades.getItem(i);
            Martelo* m = dynamic_cast<Martelo*>(ent);

            if (m == nullptr || !m->isAtivo()) {
>>>>>>> Stashed changes
                continue;
            }

            if (verificarColisao(inim, m)) {
<<<<<<< Updated upstream
                // Dano ao inimigo
                inim->setVidas(inim->getVidas() - m->colidir());

                // Desativa o martelo após colisão
=======
                inim->setVidas(inim->getVidas() - m->colidir());
>>>>>>> Stashed changes
                m->desativar();
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

void Gerenciador_Colisao::incluirProjetil(Projetil* p) {
<<<<<<< Updated upstream
    LPs.insert(p);
=======

    if (dynamic_cast<Bomba*>(p) != nullptr) {
        LPs.insert(p);
    }

>>>>>>> Stashed changes
}

// Remover entidades
void Gerenciador_Colisao::removerInimigo(Inimigo* ini) {
    std::vector<Inimigo*>::iterator it = std::find(LIs.begin(), LIs.end(), ini);
    if (it != LIs.end()) {
        LIs.erase(it);
<<<<<<< Updated upstream
        delete* it;
=======

>>>>>>> Stashed changes
    }
}

void Gerenciador_Colisao::removerProjetil(Projetil* p) {
    std::set<Projetil*>::iterator it = std::find(LPs.begin(), LPs.end(), p);
    if (it != LPs.end()) {
        LPs.erase(it);
<<<<<<< Updated upstream
        delete* it;
=======

>>>>>>> Stashed changes
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
    tratarColisoesJogsPortas();
    tratarColisoesInimTroncos();
    tratarColisoesInimMartelos();
    tratarColisoesEntsBlocos();
<<<<<<< Updated upstream
}
=======

    // Colisão troncos e bombas
    for (std::set<Projetil*>::iterator itProj = LPs.begin(); itProj != LPs.end(); ++itProj) {
        Bomba* bomba = dynamic_cast<Bomba*>(*itProj);

        if (bomba == nullptr || !bomba->isAtivo()) {
            continue;
        }

        for (std::list<Obstaculo*>::iterator itObs = LOs.begin(); itObs != LOs.end(); ++itObs) {
            Tronco* tronco = dynamic_cast<Tronco*>(*itObs);

            if (tronco == nullptr) {
                continue;
            }

            if (verificarColisao(bomba, tronco)) {
                bomba->desativar(); // Bomba desativa ao colidir
            }
        }
    }
}
>>>>>>> Stashed changes

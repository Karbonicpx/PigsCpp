#include "Baconzilla.h"

using namespace PigsCpp::Entidades::Personagens;

Baconzilla::Baconzilla(ListaEntidades* lE) : 
    Inimigo("textures/Baconzilla.png", 45.0f, 45.0f, gerarAleatorioFloat(0.2f, 0.25f), 3),
    Atirador(gerarAleatorioFloat(90.f, 120.f), lE),
    tempoTrocaDirecao(gerarAleatorioFloat(0.5, 1.0f)),
    tamanho((rand() % 3) + 1), // 1 a 3
    forca((rand() % 5) + 1) // 1 a 5
   
{
    velocidade = gerarAleatorioFloat(0.1f, 0.2f);
    direcao = -1;
    
};
Baconzilla::~Baconzilla() {
   
};

// Método virtual puro
void Baconzilla::executar() {
    if (numVidas > 0) {
        mover();
        projetilRecarga();
    }
    else {
        nivel_maldade = 0;
        tamanho = 0;
        forca = 0;
        corpo.setFillColor(sf::Color(255, 255, 255, 0));
    }
   
};

void Baconzilla::danificar(Jogador* p) { // chamado quando o projetil colidir com o jogador
    // Dano ao jogador
    if (p) {
        p->setVidas(p->getVidas() - (forca + getMaldade() + tamanho));
    }
};
void Baconzilla::salvar(std::ofstream& arq) {
    arq << "BACONZILLA ";
    Inimigo::salvarDataBuffer(arq);
    arq << forca << " " << tamanho << " " << tempoProjetil << std::endl;
};

void Baconzilla::mover() {
    sf::Vector2f deslocamento(velocidade * direcao, 0);
    corpo.move(deslocamento);

    // Relógio: se passou tempo suficiente, checa troca de direção
    if (relogio.getElapsedTime().asSeconds() >= tempoTrocaDirecao) {
        relogio.restart();

        // Gera 0 ou 1 aleatório
        int troca = rand() % 2;

        if (troca == 1) {
            inverterDir(); // inverte direção
        }
    }
}


void Baconzilla::atirarProjetil() {
    sf::Vector2f origem = corpo.getPosition();
    float dirX = direcao * 3.0f;
    float dirY = -5.5f;
    sf::Vector2f vel(dirX, dirY);

    // Cria a bomba
    if (dirX < 0) {
        Bomba* b = new Bomba(origem.x + corpo.getSize().x / 2, origem.y, sf::Vector2f(vel.x - forca, vel.y));
        listaEntidades->listaEntidades.incluir(b);
    }
    else {
        Bomba* b = new Bomba(origem.x + corpo.getSize().x / 2, origem.y, sf::Vector2f(vel.x + forca, vel.y));
        listaEntidades->listaEntidades.incluir(b);
    }
   
}



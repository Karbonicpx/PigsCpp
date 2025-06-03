#include "Jogo.h"

using namespace PigsCpp;
using namespace PigsCpp::Gerenciadores;

// Construtora: Necessário inicializar as variáveis dentro do construtor porém forá das { },
// Por conta da versão do C++ de 2003
Jogo::Jogo()
{
    // Configura o jogador com a janela do gerenciador gráfico
    jogador1.setJanela(GG.getWindow());
    jogador1.setPos(250.f, 100.f);
    jogador2.setJanela(GG.getWindow());
    jogador2.setPos(500.f, 100.f);

}

Jogo::~Jogo() {
}

const void Jogo::executar() {
    while (GG.estaAberta())
    {
        // Processa eventos
        while (const std::optional event = GG.getWindow()->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                GG.fechar();
        }

        // Atualiza lógica do jogo
        jogador1.executar();

        if (GC.veriColisao(&jogador1, &jogador2)) {
            printf("Colidiu\n");
        };

        // Renderização
        GG.clear();
        GG.setCorpo(jogador1.getCorpo());
        GG.desenhar();
        GG.setCorpo(jogador2.getCorpo());
        GG.desenhar();
        GG.mostrar();
    }
}
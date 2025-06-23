#pragma once

#include <SFML/Graphics.hpp>
#include "Jogo.h"
#include "Gerenciador_Grafico.h"

namespace PigsCpp {
    class Menu : public Ente {
    private:
        Gerenciadores::Gerenciador_Grafico* GG;
        Jogo* jogo;

        sf::Texture texturaFundo;
        sf::Sprite fundo;

        sf::Font fonte;
        sf::Text titulo;
        sf::Text opcaoFase1;
        sf::Text opcaoFase2;
        sf::Text opcaoSair;

        int indiceSelecionado;

    public:
        Menu();
        ~Menu();

        void executar();
        void desenharMenu();
        void moverCima();
        void moverBaixo();
        void confirmarSelecao();
    };
}
#pragma once

#include <SFML/Graphics.hpp>
#include "Jogo.h"
#include "Gerenciador_Grafico.h"
#include "SaveManager.h"

namespace PigsCpp {
    class Menu : public Ente {
    private:

        int indiceSelecionado;
        Gerenciadores::Gerenciador_Grafico* GG;
        Jogo* jogo;


        sf::Texture texturaFundo;
        sf::Sprite fundo;

        sf::Font fonte;
        sf::Text titulo;
        sf::Text opcaoFase1;
        sf::Text opcaoFase2;
        sf::Text opcaoSair;
        sf::Text opcaoCarregar;
        sf::Text opcaoSalvar;

        
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
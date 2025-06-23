#include "Menu.h"

using namespace PigsCpp;
using namespace Gerenciadores;

Menu::Menu() :
    GG(Gerenciador_Grafico::getInstancia()),
    jogo(nullptr),
    indiceSelecionado(0),
    texturaFundo("textures/MenuBG.png"),
    fundo(texturaFundo),
    fonte("textures/Pixellari.ttf"),
    titulo(fonte, "PIGS++", 60),
    opcaoFase1(fonte, "Jogar Fase 1", 40),
    opcaoFase2(fonte, "Jogar Fase 2", 40),
    opcaoSair(fonte, "Sair", 40)
{
 
    fundo.setPosition(sf::Vector2f(0.f, 0.f));

    // Título
    titulo.setFillColor(sf::Color::White);
    titulo.setOutlineColor(sf::Color::Black);
    titulo.setOutlineThickness(4.f);
    titulo.setPosition(sf::Vector2f(700.f, 50.f));

    // Opção Fase 1
    opcaoFase1.setFillColor(sf::Color::White);
    opcaoFase1.setOutlineColor(sf::Color::Black);
    opcaoFase1.setOutlineThickness(4.f);
    opcaoFase1.setPosition(sf::Vector2f(700.f, 200.f));

    // Opção Fase 2
    opcaoFase2.setFillColor(sf::Color::White);
    opcaoFase2.setOutlineColor(sf::Color::Black);
    opcaoFase2.setOutlineThickness(4.f);
    opcaoFase2.setPosition(sf::Vector2f(700.f, 300.f));

    // Opção Sair
    opcaoSair.setFillColor(sf::Color::White);
    opcaoSair.setOutlineColor(sf::Color::Black);
    opcaoSair.setOutlineThickness(4.f);
    opcaoSair.setPosition(sf::Vector2f(700.f, 400.f));
}

Menu::~Menu() {
    if (jogo != nullptr) {
        delete jogo;
        jogo = nullptr;
    }
}

void Menu::executar() {
    while (GG->estaAberta()) {
        // Eventos
        while (const std::optional<sf::Event> evento = GG->getWindow()->pollEvent()) {
            if (evento->is<sf::Event::Closed>()) {
                GG->fechar();
            }
            if (const sf::Event::KeyPressed* keyEvent = evento->getIf<sf::Event::KeyPressed>()) {
                sf::Keyboard::Key tecla = keyEvent->code;

                if (tecla == sf::Keyboard::Key::Up) {
                    moverCima();
                }
                else if (tecla == sf::Keyboard::Key::Down) {
                    moverBaixo();
                }
                else if (tecla == sf::Keyboard::Key::Enter) {
                    confirmarSelecao();
                }
            }
        }

        // Renderização
        GG->clear();
        desenharMenu();
        GG->mostrar();
    }
}

void Menu::desenharMenu() {
    GG->getWindow()->draw(fundo);
    GG->getWindow()->draw(titulo);
    GG->getWindow()->draw(opcaoFase1);
    GG->getWindow()->draw(opcaoFase2);
    GG->getWindow()->draw(opcaoSair);
}

void Menu::moverBaixo() {
    if (indiceSelecionado == 2) {
        indiceSelecionado = 0;
    }
    else if (indiceSelecionado == 1) {
        indiceSelecionado = 2;
    }
    else {
        indiceSelecionado = 1;
    }

    if (indiceSelecionado == 0) {
        opcaoFase1.setFillColor(sf::Color::Green);
        opcaoFase2.setFillColor(sf::Color::White);
        opcaoSair.setFillColor(sf::Color::White);
    }
    else if (indiceSelecionado == 1) {
        opcaoFase1.setFillColor(sf::Color::White);
        opcaoFase2.setFillColor(sf::Color::Red);
        opcaoSair.setFillColor(sf::Color::White);
    }

    else {
        opcaoFase1.setFillColor(sf::Color::White);
        opcaoFase2.setFillColor(sf::Color::White);
        opcaoSair.setFillColor(sf::Color::Blue);
    }
}

void Menu::moverCima() {

    if (indiceSelecionado == 2) {
        indiceSelecionado = 1;
    }
    else if (indiceSelecionado == 1) {
        indiceSelecionado = 0;
    }
    else {
        indiceSelecionado = 2;
    }

    if (indiceSelecionado == 2) {
        opcaoFase1.setFillColor(sf::Color::White);
        opcaoFase2.setFillColor(sf::Color::White);
        opcaoSair.setFillColor(sf::Color::Blue);
    }
    else if (indiceSelecionado == 1) {
        opcaoFase1.setFillColor(sf::Color::White);
        opcaoFase2.setFillColor(sf::Color::Red);
        opcaoSair.setFillColor(sf::Color::White);
    }

    else {
        opcaoFase1.setFillColor(sf::Color::Green);
        opcaoFase2.setFillColor(sf::Color::White);
        opcaoSair.setFillColor(sf::Color::White);
    }
}

void Menu::confirmarSelecao() {
    if (jogo != nullptr) {
        delete jogo;
        jogo = nullptr;
    }

    if (indiceSelecionado == 0) {
        // Jogar Fase 1
        jogo = new Jogo(1);
        jogo->executar();
    }
    else if (indiceSelecionado == 1) {
        // Jogar Fase 2
        jogo = new Jogo(2);
        jogo->executar();
    }

    else {
        // Sair do jogo
        GG->fechar();
    }
}

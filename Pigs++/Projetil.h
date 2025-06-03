#pragma once 
#include "Entidade.h"
#include <SFML/Graphics.hpp>

namespace PigsCpp {
    namespace Entidades {
        
        class Projetil : public Entidade {

        protected:
        float velocidade; // Velocidade do projétil
        sf::Vector2f direcao; // Direção do projétil
        sf::CircleShape forma; // Forma do projétil
        bool ativo;

        public:
        Projetil(float x, float y, float vel, sf::Vector2f dir);
        virtual ~Projetil();
        const void mover();
        const void desativar();
        const bool isAtivo() const;
        const void executar(sf::RenderWindow& window);
        const void salvar();
        };
    };
};
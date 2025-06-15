#pragma once 
#include "Entidade.h"
#include <SFML/Graphics.hpp>

namespace PigsCpp {
    namespace Entidades {
        
        // Projétil
        class Bomba : public Entidade {

        protected:
        float velocidade; // Velocidade do projétil
        sf::Vector2f direcao; // Direção do projétil
        sf::CircleShape forma; // Forma do projétil
        bool ativo; // Quando estiver ativo, ela estará no jogo. Quando ela colidir com alguma coisa, a bomba é removida

        public:
        Bomba();
        Bomba(float x, float y, float vel, sf::Vector2f dir);
        ~Bomba();
        void mover();
        const bool isAtivo() const;
        void inverterAtivo();
        void executar();
        void salvar();

        const float getVel() const;
        };
    };
};
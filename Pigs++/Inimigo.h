#pragma once
#include "Jogador.h"

namespace PigsCpp {
    namespace Entidades {
        namespace Personagens {
            class Inimigo : public Personagem {

            protected:

                int nivel_maldade;
                int direcao;

            public:

                Inimigo(const std::string texturePath, const float bodyX, const float bodyY, const float v, const int vida);
                Inimigo();
                ~Inimigo();
                const int getMaldade() const;
                void setMaldade(const int m);
                void inverterDir();
                void salvarDataBuffer(std::ofstream& arq);
                virtual void executar() = 0;
                virtual void danificar(Jogador* p) = 0;
                virtual void salvar(std::ofstream& arq) = 0;
                virtual void mover() = 0;

            };
        };
    };
};

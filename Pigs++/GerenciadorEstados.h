#pragma once

#include "Estado.h"
#include <map>

// Todos os créditos a esse codigo vão para os desenvolvedor do projeto "ForestPP",
// Desenvolvido por: Murilo Unten e Robson Junior
// Link do projeto: https://github.com/MuriloUnten/forestpp

namespace PigsCpp {

    namespace Gerenciadores
    {
        class GerenciadorEstados
        {
        private:
            GerenciadorEstados();
            static GerenciadorEstados* instancia;

            std::map<idEstado, Menus::Estado*> mapEstados;
            idEstado idEstadoAtual;
            idEstado ultimoIDEstado;


        public:
            ~GerenciadorEstados();
            static GerenciadorEstados* getInstancia();
            static void deletarInstancia();

            void adicionarEstado(Menus::Estado* estado);
            void setEstado(idEstado novoIDEstado);
            void mudarEstado(idEstado novoEstado);
            void atualizarEstado(Menus::Estado* novoEstado);
            void executarEstado();
            void desenharEstado();

        };
    }// namespace Managers
}

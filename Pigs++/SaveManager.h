#pragma once
#include <fstream>
#include "Fase.h"

class SaveManager {
public:
    static void salvarJogo(Fase* fase, const std::string& caminho) {
        std::ofstream arq(caminho);
        if (!arq.is_open()) return;

        // Salva todos os jogadores e entidades
        ListaEntidades* lista = fase->getListaEntidades();
        for (int i = 0; i < lista->listaEntidades.getLen(); i++) {
            Entidade* e = lista->listaEntidades.getItem(i);
            if (e) e->salvar(arq);
        }
        arq.close();
    }

    // Exemplo de carregamento (simplificado)
    static void carregarJogo(Fase* fase, const std::string& caminho) {
        // Aqui você pode chamar fase->carregarJogo() ou implementar a lógica de leitura
        fase->carregarJogo();
    }
};


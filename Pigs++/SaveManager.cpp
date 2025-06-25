#include "SaveManager.h"

using namespace PigsCpp::Fases;

SaveManager::SaveManager() {

}

SaveManager::~SaveManager() {

}

void SaveManager::salvarJogo(Fase* fase, const std::string& caminho) {
    std::ofstream arq(caminho);
    if (!arq.is_open()) return;

    // Salva todos os jogadores e entidades
    ListaEntidades* lista = fase->getListaEntidades();

    for (int i = 0; i < lista->listaEntidades.getLen(); i++) {
        Entidade* e = lista->listaEntidades.getItem(i);
        if (e) e->salvar(arq);
    }
    arq.close();
};

void SaveManager::carregarJogo(Fase* fase) {
    std::ifstream arquivo("save.txt");
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de save: " << "save.txt" << std::endl;
        return;
    }

    fase->carregarJogo();
    arquivo.close();
}

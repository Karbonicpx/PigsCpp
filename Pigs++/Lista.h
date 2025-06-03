#pragma once
#include "Elemento.h"

// LEIA!
// OBS: Todos os créditos ao desenvolvedor do código desse arquivo, Felipe Alvez Barboza,
// retirado através de um tutorial de uma playlist feita pelo mesmo, no canal "Dev Felipe", 
// ensinando a como desenvolver uma lista template.

using namespace PigsCpp::Listas;

namespace PigsCpp {
    namespace Listas {
        template <class TL> class Lista {
        private:

            // Lista feita aos moldes de uma lista encadeada!
            // Não precisamos de um "pProx" por que ele já esta dentro da classe Elemento!
            Elemento<TL>* pPrimeiro; // Ponteiro para a cabeça da lista encadeada
            Elemento<TL>* pUltimo; // Ponteiro para o fim da lista encadeada    
            int len; // Tamanho da lista

        public:
            Lista();
            ~Lista();

            // Retorna-se o tamanho da lista
            int getLen() { return len; }


            // Retornando qualquer item em dada posição por parâmetro
            TL* getItem(int posicao) {

                Elemento<TL>* temp = pPrimeiro;

                if (posicao == 0)
                    return temp->getItem();

                // Enquanto não chegar na posição, ele vai pegar o proximo elemento
                for (int i = 0; i < posicao; i++)
                    temp = temp->getProx();

                // Retornando o item após chegar na posição desejada
                return temp->getItem();
            }

            // Incluindo um item na lista
            void incluir(TL* item) {

                // If será executado quando o elemento a ser incluido é o primeiro da lista
                if (pPrimeiro == nullptr) {
                    pPrimeiro = new Elemento<TL>;
                    pPrimeiro->setItem(item);
                    pUltimo = pPrimeiro;
                }
                // Caso não seja o primeiro, sera executado esse else
                else {
                    Elemento<TL>* temp = new Elemento<TL>;
                    temp->setItem(item);
                    pUltimo->setProx(temp);
                    pUltimo = temp;
                }
                len++;
            }

            // Removendo um item na lista
            void remover(TL* item) {
                Elemento<TL>* temp = pPrimeiro;
                Elemento<TL>* tempAnt = nullptr;
                
                // Enquanto não chegar no item, esse loop vai ser executado
                while (temp->getItem() != item) {
                    tempAnt = temp;
                    temp = temp->getProx();
                }

                // Condições "Ifs" que vão ser executadas em casos de o item a ser removido esteja como:

                // Primeiro na lista;
                if (temp == pPrimeiro) {
                    pPrimeiro = temp->getProx();
                }
                // Ultimo na lista;
                else if (temp == pUltimo) {
                    tempAnt->setProx(nullptr);
                    pUltimo = tempAnt;
                }
                // Em qualquer posição diferente do inicio e fim
                else {
                    tempAnt->setProx(temp->getProx());
                }
                delete temp;
            }

            // Limpando toda a lista
            void limpar() {
                Elemento<TL>* temp = pPrimeiro;
                Elemento<TL>* tempAnt = nullptr;

                // Enquanto o temp não for nulo, ou seja, não for o fim da lista
                while (temp != nullptr) {

                     
                    tempAnt = temp;
                    // Passa pro proximo, deleta o item anterior e deleta o nó do item anterior
                    temp = temp->getProx();
                    delete tempAnt->getItem();
                    delete tempAnt;
                }

                pPrimeiro = nullptr;
                pUltimo = nullptr;
                len = 0; // Reseta o tamanho da lista
            }
        };

        template <class TL>
        inline Lista<TL>::Lista() {
            pPrimeiro = nullptr;
            pUltimo = nullptr;
            len = 0;
        }

        template <class TL>
        inline Lista<TL>::~Lista() {
            limpar();
        }
    }
}



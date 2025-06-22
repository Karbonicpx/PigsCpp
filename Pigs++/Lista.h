#pragma once

namespace PigsCpp {
    namespace Listas {

        template <class TL>
        class Lista {
        private:
            // Classe Elemento aninhada
            class Elemento {
            private:
                TL* item;
                Elemento* pProx;

            public:
                Elemento() : item(nullptr), pProx(nullptr) {}
                ~Elemento() {}

                void setProx(Elemento* pProx) { this->pProx = pProx; }
                void setItem(TL* item) { this->item = item; }

                Elemento* getProx() { return pProx; }
                TL* getItem() { return item; }
            };

            // Atributos da Lista
            Elemento* pPrimeiro;
            Elemento* pUltimo;
            int len;

        public:
            Lista();
            ~Lista();

            int getLen() { return len; }

            void operator--() { len--; }

            TL* getItem(int posicao) {
                Elemento* temp = pPrimeiro;
                if (posicao == 0)
                    return temp->getItem();

                for (int i = 0; i < posicao; i++)
                    temp = temp->getProx();

                return temp->getItem();
            }

            void incluir(TL* item) {
                if (pPrimeiro == nullptr) {
                    pPrimeiro = new Elemento();
                    pPrimeiro->setItem(item);
                    pUltimo = pPrimeiro;
                }
                else {
                    Elemento* temp = new Elemento();
                    temp->setItem(item);
                    pUltimo->setProx(temp);
                    pUltimo = temp;
                }
                len++;
            }

            void remover(TL* item) {
                Elemento* temp = pPrimeiro;
                Elemento* tempAnt = nullptr;

                while (temp->getItem() != item) {
                    tempAnt = temp;
                    temp = temp->getProx();
                }

                if (temp == pPrimeiro) {
                    pPrimeiro = temp->getProx();
                }
                else if (temp == pUltimo) {
                    tempAnt->setProx(nullptr);
                    pUltimo = tempAnt;
                }
                else {
                    tempAnt->setProx(temp->getProx());
                }
                delete temp;
				temp = nullptr;
                len--;
            }

            void limpar() {
                Elemento* temp = pPrimeiro;
                Elemento* tempAnt = nullptr;

                while (temp != nullptr) {
                    tempAnt = temp;
                    temp = temp->getProx();
                    delete tempAnt->getItem();
                    delete tempAnt;
                }

                pPrimeiro = nullptr;
                pUltimo = nullptr;
                len = 0;
            }
        };

        // Implementações fora da classe
        template <class TL>
        Lista<TL>::Lista() : pPrimeiro(nullptr), pUltimo(nullptr), len(0) {}

        template <class TL>
        Lista<TL>::~Lista() {
            limpar();
        }

    }
}
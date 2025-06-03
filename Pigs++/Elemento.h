#pragma once

// LEIA!
// OBS: Todos os créditos ao desenvolvedor do código desse arquivo, Felipe Alvez Barboza,
// retirado através de um tutorial de uma playlist feita pelo mesmo, no canal "Dev Felipe", 
// ensinando a como desenvolver uma lista template.

namespace PigsCpp {
    namespace Listas {
        template <class TE> class Elemento {
        private:
            TE* item; // Item que vai estar dentro de cada nó
            Elemento<TE>* pProx; // Ponteiro para o próximo elemento dentro de uma lista     

        public:
            Elemento();
            ~Elemento();

            void setProx(Elemento<TE>* pProx) { this->pProx = pProx; }
            void setItem(TE* item) { this->item = item; }

            Elemento<TE>* getProx() { return pProx; }
            TE* getItem() { return item; }
        };

        template <class TE>
        inline Elemento<TE>::Elemento() {
            pProx = nullptr;
            item = nullptr;
        }

        template <class TE>
        inline Elemento<TE>::~Elemento() {}
    }
}


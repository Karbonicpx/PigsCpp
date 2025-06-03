#pragma once
#include <SFML/Graphics.hpp>

/* LEIA !!
 OBS: Todos os créditos ao código dos arquivos .h e .cpp dessa classe,
 se deve aos integrantes do grupo de extensão PETECO, na universidade UTFPR,
 na qual foi feita uma oficina direcionada ao desenvolvimento dos gerenciadores
 dirigida por eles, realizada em 30/05/2025, das 17:00 as 19:00, na sala do PETECO.
*/

using namespace sf;

namespace PigsCpp {
    namespace Gerenciadores {

        class Gerenciador_Grafico
        {
        private:
            RectangleShape corpo;
            RenderWindow* janela;

        public:
            Gerenciador_Grafico();
            ~Gerenciador_Grafico();

            RenderWindow* getWindow() const;
            const void setCorpo(RectangleShape corpo);
            const bool estaAberta() const;
            const void clear();
            const void desenhar();
            const void desenhar(const Texture* textura);
            const void mostrar();
            const void fechar();
        };
    };
};

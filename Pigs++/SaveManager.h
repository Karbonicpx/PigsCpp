#pragma once
#include <fstream>
#include "Fase.h"

namespace PigsCpp {

    namespace Gerenciadores {
        class SaveManager {
<<<<<<< Updated upstream

        private:
           

        public:
            SaveManager();
            ~SaveManager();
            static void salvarJogo(Fases::Fase* fase, const std::string& caminho);
            static void carregarJogo(Fases::Fase* fase);
            

            

        };
    }
   
=======

        private:


        public:
            SaveManager();
            ~SaveManager();
            static void salvarJogo(Fases::Fase* fase, const std::string& caminho);
            static void carregarJogo(Fases::Fase* fase);




        };
    }

>>>>>>> Stashed changes
};

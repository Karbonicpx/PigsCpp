#include "Jogo.h"

using namespace PigsCpp;

int main()
{
   
	Jogo jogoObj;
	jogoObj.executar();

	// Destruindo a instância estática
	Gerenciador_Grafico::destruirInstancia();
	return 0;
	
	
	
}
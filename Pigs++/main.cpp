#include "Jogo.h"

using namespace PigsCpp;

int main()
{
   
	Jogo jogoObj;
	jogoObj.executar();

	// Destruindo a inst�ncia est�tica
	Gerenciador_Grafico::destruirInstancia();
	return 0;
	
	
	
}
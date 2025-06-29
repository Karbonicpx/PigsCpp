#include "Martelo.h"

using namespace PigsCpp::Entidades;

Martelo::Martelo(float x, float y, sf::Vector2f vel) :
	Projetil("textures/Martelo.png", 33.0f, 13.0f, x, y, vel, 1),
	velocidadeGiro(10.f)
{
	corpo.setOrigin(sf::Vector2f(corpo.getSize().x / 2.f, corpo.getSize().y / 2.f));

	// Ajuste de posição para compensar a origem no centro
	corpo.setPosition(sf::Vector2f(x + corpo.getSize().x / 2.f, y + corpo.getSize().y / 2.f));
}
Martelo::~Martelo() {}

<<<<<<< Updated upstream
void Martelo::mover() 
=======
void Martelo::mover()
>>>>>>> Stashed changes
{

	if (velocidade.x < 0) {
		float angulo = corpo.getRotation().asDegrees();
		sf::Angle anguloNovo = sf::degrees(angulo - velocidadeGiro);
		corpo.setRotation(anguloNovo);
	}
	else {
		float angulo = corpo.getRotation().asDegrees();
		sf::Angle anguloNovo = sf::degrees(angulo + velocidadeGiro);
		corpo.setRotation(anguloNovo);
	}
<<<<<<< Updated upstream
	
=======

>>>>>>> Stashed changes
	corpo.move(velocidade);
}

void Martelo::salvar(std::ofstream& arq) {
<<<<<<< Updated upstream
	Entidade::salvarDataBuffer(arq);
	arq << velocidade.x << " "
	<< velocidade.y << " " 
	<< ativo << " " 
	<< dano << std::endl;
=======
	arq << velocidade.x << " "
		<< velocidade.y << " "
		<< velocidadeGiro << std::endl;
>>>>>>> Stashed changes
}

void Martelo::executar() {

<<<<<<< Updated upstream
	
	if (ativo) {	
=======

	if (ativo) {
>>>>>>> Stashed changes
		mover();
	}
	else {
		corpo.setFillColor(sf::Color(255, 255, 255, 0));
<<<<<<< Updated upstream
		dano = 0;	
	}
}
=======
		dano = 0;
	}
}
>>>>>>> Stashed changes

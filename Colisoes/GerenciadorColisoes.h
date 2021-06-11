#pragma once
#include "stdafx.h"
#include "ListaBolas.h"
#include "ControladorVetorial.h"

class GerenciadorColisoes
{
private:

	ListaBolas* LBolas;
	ControladorVetorial vetController;

public:

	GerenciadorColisoes();
	~GerenciadorColisoes();
	void checkCollisions();
	bool testCollisions(Bola* b1, Bola* b2);
	void setListaBolas(ListaBolas* l);
	sf::Vector2f calculateDistance(sf::Vector2f d1, sf::Vector2f d2);
	void resolveCollision(Bola* b1, Bola* b2);
};


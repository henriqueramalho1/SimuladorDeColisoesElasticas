#pragma once
#include "stdafx.h"

class ControladorVetorial
{
private:

public:

	ControladorVetorial();
	~ControladorVetorial();
	sf::Vector2f rotate(sf::Vector2f vet, float angle);
	sf::Vector2f normalize(sf::Vector2f vet);
	float module(sf::Vector2f vet);
	float dot(sf::Vector2f vet1, sf::Vector2f vet2);
};


#include "stdafx.h"
#include "ControladorVetorial.h"

ControladorVetorial::ControladorVetorial()
{
}

ControladorVetorial::~ControladorVetorial()
{
}

sf::Vector2f ControladorVetorial::rotate(sf::Vector2f vet, float angle)
{
    sf::Vector2f rotVet;

    rotVet.x = vet.x * cos(angle) - vet.y * sin(angle);
    rotVet.y = vet.x * sin(angle) + vet.y * cos(angle);

    return rotVet;
}

sf::Vector2f ControladorVetorial::normalize(sf::Vector2f vet)
{
    float module = sqrt(vet.x * vet.x + vet.y * vet.y);
    sf::Vector2f normalizedVet = vet / module;

    return normalizedVet;
}

float ControladorVetorial::module(sf::Vector2f vet)
{
    float module = sqrt(vet.x * vet.x + vet.y * vet.y);

    return module;
}

float ControladorVetorial::dot(sf::Vector2f vet1, sf::Vector2f vet2)
{
    float dot = vet1.x * vet2.x + vet1.y * vet2.y;
    return dot;
}

#pragma once
#include "stdafx.h"
#include "ControladorVetorial.h"

class Bola
{
private:

	sf::CircleShape shape;
	const float mass;
	sf::Texture texture;
	const float radius;
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::RenderWindow* window;
	float* dt;

public:

	Bola(string t = "", float r = 0.f, sf::Vector2f p = sf::Vector2f(50.f, 50.f), sf::Vector2f v = sf::Vector2f(0.f, 0.f), sf::RenderWindow* w = NULL, float* dtime = NULL);
	~Bola();
	void update();
	void draw();
	void setPosition(sf::Vector2f newPos);
	void setVelocity(sf::Vector2f newVel);
	sf::Vector2f getPosition();
	sf::Vector2f getVelocity();
	const float getRadius() const;
	const float getMass() const;
};


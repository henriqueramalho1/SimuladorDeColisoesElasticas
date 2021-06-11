#include "stdafx.h"
#include "Bola.h"

Bola::Bola(string t, float r, sf::Vector2f p, sf::Vector2f v, sf::RenderWindow* w, float* dtime):
	shape(r),
	mass(1.f),
	texture(),
	radius(r),
	position(p),
	velocity(v),
	window(w),
	dt(dtime)
{
	shape.setOrigin(radius, radius);

	if (t != "")
	{
		texture.loadFromFile(t);
		shape.setTexture(&texture);
	}
	else
	{
		shape.setFillColor(sf::Color::Blue);
	}
} 

Bola::~Bola()
{
	dt = NULL;
}

void Bola::update()
{
	position += velocity * (*dt);
	shape.setPosition(position);

	if (position.x < radius)
	{
		position.x = radius;
		velocity.x *= -1.f;
	}
	if (position.x > 800.f - radius)
	{
		position.x = 800.f - radius;
		velocity.x *= -1.f;
	}
	if (position.y < radius)
	{
		position.y = radius;
		velocity.y *= -1.f;
	}
	if (position.y > 600.f - radius)
	{
		position.y = 600.f - radius;
		velocity.y *= -1.f;
	}
}

void Bola::draw()
{
	window->draw(shape);
}

void Bola::setPosition(sf::Vector2f newPos)
{
	position = newPos;
}

void Bola::setVelocity(sf::Vector2f newVel)
{
	velocity = newVel;
}

sf::Vector2f Bola::getPosition()
{
	return position;
}

sf::Vector2f Bola::getVelocity()
{
	return velocity;
}

const float Bola::getRadius() const
{
	return radius;
}

const float Bola::getMass() const
{
	return mass;
}

#include "stdafx.h"
#include "GerenciadorColisoes.h"

GerenciadorColisoes::GerenciadorColisoes():
	LBolas(NULL),
	vetController()
{
}

GerenciadorColisoes::~GerenciadorColisoes()
{
	LBolas = NULL;
}

void GerenciadorColisoes::checkCollisions()
{
	for (int i = 0; i < LBolas->getSize(); i++)
	{
		Bola* b1 = LBolas->getBolaAt(i);

		for (int j = i + 1; j < LBolas->getSize(); j++)
		{
			Bola* b2 = LBolas->getBolaAt(j);

			if (testCollisions(b1, b2))
			{
				cout << "vb1 : " << b1->getVelocity().x << "//" << b1->getVelocity().y << " Norma : " << vetController.module(b1->getVelocity()) << endl;
				cout << "vb2 : " << b2->getVelocity().x << "//" << b2->getVelocity().y << " Norma : " << vetController.module(b2->getVelocity()) << endl;

				resolveCollision(b1, b2);
			}
		}
	}
}

bool GerenciadorColisoes::testCollisions(Bola* b1, Bola* b2)
{
	sf::Vector2f distance = calculateDistance(b1->getPosition(), b2->getPosition());
	float modDistance = sqrt(distance.x * distance.x + distance.y * distance.y);

	if (modDistance <= b1->getRadius() + b2->getRadius())
	{
		return true;
	}

	return false;
}

void GerenciadorColisoes::setListaBolas(ListaBolas* l)
{
	LBolas = l;
}

sf::Vector2f GerenciadorColisoes::calculateDistance(sf::Vector2f d1, sf::Vector2f d2)
{
	sf::Vector2f distance;

	distance = d1 - d2;

	return distance;
}

void GerenciadorColisoes::resolveCollision(Bola* b1, Bola* b2)
{
	cout << "Ki : " << 1 / 2.f * (vetController.module(b1->getVelocity()) * vetController.module(b1->getVelocity())) + 1 / 2.f * (vetController.module(b2->getVelocity()) * vetController.module(b2->getVelocity())) << endl;

	sf::Vector2f velocityDiff = b1->getVelocity() - b2->getVelocity();
	sf::Vector2f distance = b1->getPosition() - b2->getPosition();

	float overlap = b1->getRadius() + b2->getRadius() - vetController.module(distance);

	sf::Vector2f normalDir = vetController.normalize(distance);
	sf::Vector2f newDx = 0.5f * overlap * normalDir;

	b1->setPosition(b1->getPosition() + newDx);
	b2->setPosition(b2->getPosition() - newDx);

	sf::Vector2f projVel1 = vetController.dot(b1->getVelocity(), normalDir) * normalDir;
	sf::Vector2f projVel2 = vetController.dot(b2->getVelocity(), normalDir) * normalDir;

	sf::Vector2f perpendicularDir(normalDir.y, -normalDir.x);

	sf::Vector2f perpendicularVel1 = vetController.dot(b1->getVelocity(), perpendicularDir) * perpendicularDir;
	sf::Vector2f perpendicularVel2 = vetController.dot(b2->getVelocity(), perpendicularDir) * perpendicularDir;

	sf::Vector2f newVel1 = projVel2 + perpendicularVel1;
	sf::Vector2f newVel2 = projVel1 + perpendicularVel2;

	b1->setVelocity(newVel1);
	b2->setVelocity(newVel2);

	cout << "Kf : " << 1/2.f * (vetController.module(b1->getVelocity()) * vetController.module(b1->getVelocity())) + 1/2.f * (vetController.module(b2->getVelocity()) * vetController.module(b2->getVelocity())) << endl;

}

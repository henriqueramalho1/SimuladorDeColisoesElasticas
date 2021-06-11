#include "stdafx.h"
#include "GerenciadorEventos.h"

GerenciadorEventos::GerenciadorEventos(sf::RenderWindow* w, float* dtime):
	window(w),
	dt(dtime),
	cooldown(0.f),
	LBolas(NULL)
{
}

GerenciadorEventos::~GerenciadorEventos()
{
	window = NULL;
}

void GerenciadorEventos::verificarEvento()
{
	sf::Event ev;
	window->pollEvent(ev);

	cooldown += *dt;

	if (ev.type == sf::Event::Closed)
	{
		window->close();
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && cooldown >= 0.5f)
	{
		criarBola();
		cooldown = 0.f;
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && !LBolas->empty() && cooldown >= 0.5f)
	{
		removerBola();
		cooldown = 0.f;
	}

}

void GerenciadorEventos::criarBola()
{
	Bola* bola = NULL;
	bola = new Bola("", 50.f, static_cast<sf::Vector2f> (sf::Mouse::getPosition(*window)), sf::Vector2f(200.f, 100.f), window, dt);
	LBolas->include(bola);
}

void GerenciadorEventos::removerBola()
{
	Bola* bola = LBolas->remove();
	delete bola;
}

void GerenciadorEventos::setListaBolas(ListaBolas* l)
{
	LBolas = l;
}

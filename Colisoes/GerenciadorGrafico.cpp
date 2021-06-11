#include "stdafx.h"
#include "GerenciadorGrafico.h"

GerenciadorGrafico::GerenciadorGrafico():
	window(sf::VideoMode(800, 600),"Collider"),
	clock(),
	dt(0.f),
	LBolas(NULL)
{
}

GerenciadorGrafico::~GerenciadorGrafico()
{
}

void GerenciadorGrafico::restartClock()
{
	dt = clock.restart().asSeconds();
}

void GerenciadorGrafico::update()
{
	LBolas->update();
}

void GerenciadorGrafico::draw()
{
	LBolas->draw();
}

void GerenciadorGrafico::display()
{
	window.display();
}

void GerenciadorGrafico::clear()
{
	window.clear();
}

sf::RenderWindow* GerenciadorGrafico::getWindow()
{
	return &window;
}

float* GerenciadorGrafico::getDt()
{
	return &dt;
}

void GerenciadorGrafico::setListaBolas(ListaBolas* l)
{
	LBolas = l;
}

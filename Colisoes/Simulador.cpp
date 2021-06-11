#include "stdafx.h"
#include "Simulador.h"

Simulador::Simulador():
	GGrafico(),
    GEventos(GGrafico.getWindow(), GGrafico.getDt()),
    GColisoes(),
    window(NULL),
    listaBolas()
{
    window = GGrafico.getWindow();

    GGrafico.setListaBolas(&listaBolas);
    GEventos.setListaBolas(&listaBolas);
    GColisoes.setListaBolas(&listaBolas);
}

Simulador::~Simulador()
{
}

void Simulador::executar()
{
    while (window->isOpen())
    {
        GGrafico.restartClock();

        GEventos.verificarEvento();

        GGrafico.update();

        GColisoes.checkCollisions();

        GGrafico.clear();

        GGrafico.draw();

        GGrafico.display();
    }
}

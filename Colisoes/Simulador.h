#pragma once
#include "stdafx.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisoes.h"
#include "Bola.h"
#include "ListaBolas.h"

class Simulador
{
private:

	GerenciadorGrafico GGrafico;
	GerenciadorEventos GEventos;
	GerenciadorColisoes GColisoes;
	sf::RenderWindow* window;
	ListaBolas listaBolas;

public:

	Simulador();
	~Simulador();
	void executar();
};


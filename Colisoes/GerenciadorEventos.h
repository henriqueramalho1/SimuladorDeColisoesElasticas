#pragma once
#include "stdafx.h"
#include "ListaBolas.h"
#include "Bola.h"

class GerenciadorEventos
{
private:

	sf::RenderWindow* window;
	float* dt;
	float cooldown;
	ListaBolas* LBolas;

public:

	GerenciadorEventos(sf::RenderWindow* w = NULL, float* dtime = NULL);
	~GerenciadorEventos();
	void verificarEvento();
	void criarBola();
	void removerBola();
	void setListaBolas(ListaBolas* l);
};


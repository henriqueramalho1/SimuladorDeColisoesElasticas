#pragma once
#include "stdafx.h"
#include "ListaBolas.h"

class GerenciadorGrafico
{
private:

	sf::RenderWindow window;
	sf::Clock clock;
	float dt;
	ListaBolas* LBolas;

public:
	
	GerenciadorGrafico();
	~GerenciadorGrafico();
	void restartClock();
	void update();
	void draw();
	void display();
	void clear();
	sf::RenderWindow* getWindow();
	float* getDt();
	void setListaBolas(ListaBolas* l);
};


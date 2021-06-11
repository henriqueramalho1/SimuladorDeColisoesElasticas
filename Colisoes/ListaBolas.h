#pragma once
#include "stdafx.h"
#include "Bola.h"

class ListaBolas
{
private:

	vector<Bola*> lista;

public:

	ListaBolas();
	~ListaBolas();
	void include(Bola* b);
	Bola* remove();
	void draw();
	void update();
	bool empty();
	int getSize();
	Bola* getBolaAt(int i);
};


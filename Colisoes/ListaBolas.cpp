#include "stdafx.h"
#include "ListaBolas.h"

ListaBolas::ListaBolas():
	lista()
{
}

ListaBolas::~ListaBolas()
{
	if (!lista.empty())
	{
		vector<Bola*>::iterator it;

		for (it = lista.begin(); it != lista.end(); it++)
		{
			Bola* bola = *it;
			delete bola;
		}
	}

	lista.clear();

	cout << "Deletando bolas" << endl;
	cout << "Tamanho lista : " << getSize() << endl;
}

void ListaBolas::include(Bola* b)
{
	if (b != NULL)
	{
		lista.push_back(b);
	}
	else
	{
		cout << "ERRO: Ponteiro bola nulo" << endl;
		exit(9);
	}
}

Bola* ListaBolas::remove()
{
	Bola* bola;
	vector<Bola*>::reverse_iterator it;

	it = lista.rbegin();
	bola = *it;
	lista.pop_back();
	return bola;
}

void ListaBolas::draw()
{
	vector<Bola*>::iterator it;

	for (it = lista.begin(); it != lista.end(); it++)
	{
		(*it)->draw();
	}
}

void ListaBolas::update()
{
	vector<Bola*>::iterator it;

	for (it = lista.begin(); it != lista.end(); it++)
	{
		(*it)->update();
	}
}

bool ListaBolas::empty()
{
	return lista.empty();
}

int ListaBolas::getSize()
{
	return static_cast<int>(lista.size());
}

Bola* ListaBolas::getBolaAt(int i)
{
	if (i >= 0 && i < lista.size())
	{
		return lista[i];
	}
	else
	{
		cout << "ERRO: Acesso indevido de memoria" << endl;
		exit(90);
	}
}

#pragma once

#pragma once
#include<iostream>
using namespace std;

class Multime {
	int* date;
	int dim; //dimensiune maxima
	int n; //numarul curent de elemente
public:
	Multime();//constructor
	Multime(int);//alt constructor cu o dimensiune data
	~Multime();//destructor
	void adauga(int); //functie de adaugare
	void extrage(int);//scoate din multime

	friend ostream& operator<<(ostream&, const Multime&); //afisare
	Multime& operator+=(int);
	Multime& operator-=(int);
	Multime operator+(const Multime&);
	Multime(const Multime&);//definim un constructor de copiere pt a folosi op +!!!!!!!
	Multime& operator=(const Multime&);//avem nevoie si de supraincarcarea operatorului = !!!!
};
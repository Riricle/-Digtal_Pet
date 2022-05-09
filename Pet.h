#pragma once
#include <iostream>
#include <string>
using namespace std;
class Pet 
{
public:
	virtual void Feed() = 0;
	virtual void Drink() = 0;
	virtual void Play() = 0;
	virtual void Action() = 0;
	virtual void showPet() = 0;
	virtual int Sold() = 0;

	string name;
	int HP = 3;
	int span = 5;
	int price = 10;
	int eng = 10;
	int status = 0;
};


#pragma once
#include "Pokemon.h"
class Battle
{
private:
	Pokemon* fighters[2];
	bool turn;

	void ShowPossibilities();
	void NextTurn();
	void PlayTurn();

public:
	Battle(Pokemon* f, Pokemon* s);
	~Battle();

	void Start();
	void DisplayStatus();
};


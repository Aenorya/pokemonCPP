#include "Battle.h"
#include <iostream>

using namespace std;

Battle::Battle(Pokemon* first, Pokemon* second)
{
	fighters[0] = first;
	fighters[1] = second;
	turn = true;
}

Battle::~Battle()
{
}

void Battle::ShowPossibilities()
{

}

void Battle::NextTurn()
{
	turn = !turn;
	PlayTurn();
}

void Battle::PlayTurn()
{
	//Trouver le pok�mon dont c'est le tour
	int playing = 0;
	//int playing = turn ? 0 : 1;
	if (!turn) {
		playing = 1;
	}
	//Annoncer le d�but du tour
	cout << fighters[playing]->GetName() << " commence son tour.\n";
	//Afficher le resum� du pok�mon dont c'est le tour
	fighters[playing]->SumUpPokemon();

	//Demander au joueur ce qu'il veut faire
	int attack = 0;

	bool valid = false;
	//Tant que l'input n'est pas un index valide, redemander
	while (!valid) {
		cout << "Entrez le num�ro de l'attaque souhait�e : ";
		cin >> attack;
		if (fighters[playing]->ExistsAbility(attack)) {
			cout << "C'est super tu as le droit de faire �a\n";
			valid = true;
		}
		else {
			cout << "Entre le num�ro d'une capacit� assign�e... \n";
		}
	}
	//Si turn est vrai other = 1 sinon other = 0
	int other = turn ? 1 : 0;
	//Attaque l'autre pok�mon
	fighters[playing]->Attack(*fighters[other], attack);
	//Si l'attaque �tait fatale, stop
	if (fighters[other]->GetLife() == 0) {
		cout << "C'est la fin du combat\n";
	}
	//Sinon, prochain tour
	else {
		NextTurn();
	}
}


void Battle::Start()
{
	PlayTurn();
}

void Battle::DisplayStatus()
{
}

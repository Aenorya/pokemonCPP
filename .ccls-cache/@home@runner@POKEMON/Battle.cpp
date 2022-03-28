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
	//Trouver le pokémon dont c'est le tour
	int playing = 0;
	//int playing = turn ? 0 : 1;
	if (!turn) {
		playing = 1;
	}
	//Annoncer le début du tour
	cout << fighters[playing]->GetName() << " commence son tour.\n";
	//Afficher le resumé du pokémon dont c'est le tour
	fighters[playing]->SumUpPokemon();

	//Demander au joueur ce qu'il veut faire
	int attack = 0;

	bool valid = false;
	//Tant que l'input n'est pas un index valide, redemander
	while (!valid) {
		cout << "Entrez le numéro de l'attaque souhaitée : ";
		cin >> attack;
		if (fighters[playing]->ExistsAbility(attack)) {
			cout << "C'est super tu as le droit de faire ça\n";
			valid = true;
		}
		else {
			cout << "Entre le numéro d'une capacité assignée... \n";
		}
	}
	//Si turn est vrai other = 1 sinon other = 0
	int other = turn ? 1 : 0;
	//Attaque l'autre pokémon
	fighters[playing]->Attack(*fighters[other], attack);
	//Si l'attaque était fatale, stop
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

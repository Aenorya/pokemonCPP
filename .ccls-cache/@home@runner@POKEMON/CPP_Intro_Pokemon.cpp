// CPP_Intro_Pokemon.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Pokemon.h"
#include "Battle.h"
#include "Trainer.h"

using namespace std;

int main()
{
    cout << "Hello World!\n";
    vector<DamageType> resist = vector<DamageType>{DamageType::Electric, DamageType::Psych};
    Pokemon pikachu = Pokemon("Pikachu", "Jaune", resist, 10);
    //pikachu.SumUpPokemon();
    Ability strike = Ability("Attaque Eclair", "Fait des Eclairs", DamageType::Electric, 5, 3);
    pikachu.AddAbilityAt(strike, 0);
    //pikachu.SumUpPokemon();
    Ability pika = Ability("Trognon", "Est trop mignon", DamageType::Psych, 3, 1);
    /*pikachu.Hurt(12, DamageType::Electric);
    pikachu.Hurt(10, DamageType::Fire);*/
    pikachu.AddAbilityAt(pika, 1);

    pikachu.SumUpPokemon();
    Pokemon racaillou = 
        Pokemon("Racaillou", "un caillou avec des gros bras", vector<DamageType>{ DamageType::Electric}, 10);
    Ability hit = Ability("Taper", "Tape fort", DamageType::Physical, 3, 2);

    racaillou.AddAbilityAt(hit, 0);
    racaillou.SumUpPokemon();

    //Battle firstBattle = Battle(&pikachu, &racaillou);
    //firstBattle.Start();
    //pikachu.SumUpPokemon();
    // racaillou.SumUpPokemon();
    // pikachu.Heal(1000);
    // pikachu.SumUpPokemon();
		// vector<Pokemon*> sachasPokemons;
		// sachasPokemons.push_back(&pikachu);
		// sachasPokemons.push_back(&racaillou);

		racaillou.Hurt(8, DamageType::Psych);

		Trainer sacha = Trainer("Sacha", "un jeune garcon qui sera un jour le meilleur dresseur",vector<Pokemon*>{&pikachu, &racaillou},6);


		Pokemon stari = Pokemon("Stari", "une gentille étoile de mer", vector<DamageType>{DamageType::Water}, 9);
		Ability waterJet = Ability("Jet d'eau", "ca mouille", DamageType::Water, 4, 3);
		Ability splash = Ability("Eclabousser", "ca mouille aussi", DamageType::Water, 3, 1);
		stari.AddAbilityAt(waterJet, 0);
		stari.AddAbilityAt(splash, 1);
		Pokemon magicarp = Pokemon("Magicarp", "petit poisson deviendra grand", vector<DamageType>{DamageType::Water}, 11);
		magicarp.AddAbilityAt(splash, 0);

		Trainer misty = Trainer("Ondine", "une entraineuse débutante qui aime l'eau",vector<Pokemon*>{&stari, &magicarp}, 3);
		
		cout<<"============\n";
		sacha.SumUpTrainer();
		cout<<"============\n";
		misty.SumUpTrainer();
		cout<<"============\n";
	}
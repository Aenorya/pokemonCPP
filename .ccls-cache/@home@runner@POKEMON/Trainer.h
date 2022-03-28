#pragma once
#include <string>
#include <vector>
#include "Pokemon.h"

class Trainer{
private :
std::string mName;
std::string mDescription;
vector<Pokemon*> mPokemons;
int mPokeballCount;
//-1 si aucun pokemon séléctionné, l'index sinon
int mActivePokemon;

public:
Trainer();
Trainer(std::string name, std::string desc, int pokeballCount);
Trainer(std::string name, std::string desc, vector<Pokemon*> pokemons, int pokeballCount);
~Trainer();
std::string GetName();
int GetPokeballsCount();
int GetActivePokemon();
void AddPokeball();
void TryCatchPokemon(Pokemon* pokemon);

void SumUpTrainer();
void SumUpPokemons();


};
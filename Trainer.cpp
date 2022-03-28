#include "Trainer.h"
#include <iostream>
using namespace std;

Trainer::Trainer(){
	mName = "Sacha";
	mDescription = "du bourg-palette";
	mPokeballCount = 3;
	mActivePokemon = -1;
}
Trainer::Trainer(string name, string desc, int pokeballCount){
	mName = name;
	mDescription = desc;
	mPokeballCount = pokeballCount;
	mActivePokemon = -1;
}
Trainer::Trainer(string name, string desc, vector<Pokemon*> pokemons, int pokeballCount){
	mName = name;
	mDescription = desc;
	mPokeballCount = pokeballCount;
	mPokemons = pokemons;
	mActivePokemon = -1;
}
Trainer::~Trainer(){
	mPokemons.~vector();
}
string Trainer::GetName(){
	return mName;
}
int Trainer::GetPokeballsCount(){
	return mPokeballCount;
}
int Trainer::GetActivePokemon(){
	return mActivePokemon;
}
void Trainer::AddPokeball(){
	//mPokeballCount = mPokeballCount +1;
	//mPokeballCount +=1;
	mPokeballCount ++;
}
void Trainer::TryCatchPokemon(Pokemon* pokemon){
	cout<<mName<<" essaye d'attraper "<<pokemon->GetName()<<'\n';
	if(mPokeballCount < 1){
		cout<<mName<<" ne possede pas suffisamment de pokeballs\n";
	}
	else{
		mPokeballCount --;
	}
	if(!pokemon->IsWeak()){
		cout<<pokemon->GetName()<<" resiste a la capture\n";
	}else{
		cout<<mName<<" a capture "<<pokemon->GetName()<<" avec succes.\n";
		mPokemons.push_back(pokemon);
	}
}

void Trainer::SumUpTrainer(){
	cout<<mName<<" est "<<mDescription<<"\n";
	if(mPokemons.size() > 0){
		cout<<"Ses pokemons sont :\n";
		SumUpPokemons();
		}else{
		cout<<mName<<" n'a pas de pokemons pour le moment\n";
	}
}

void Trainer::SumUpPokemons(){
	for(int p = 0; p < mPokemons.size(); p++){
			cout<<"\t"<<p<<"\t"<<mPokemons[p]->GetName();
			if(mPokemons[p]->GetLife() == 0){
				cout<<" ~ Inactif.\n";
			}else{
				cout<<" ~ "<<mPokemons[p]->GetLife()<<" hp.\n";
			}
		}
	
}
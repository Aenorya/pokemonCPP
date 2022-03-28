#pragma once
#include "Ability.h"
#include <string>
#include <vector>
class Pokemon
{
private:
	std::string mName;
	std::string mDescription;
	int mMaxLifePoints;
	int mCurrentLifePoints;
	Ability mAbilities[4];
	vector<DamageType> mResistance;

public :
	Pokemon();
	Pokemon(std::string name, std::string description, int maxLifePoints);
	Pokemon(std::string name, std::string description, vector<DamageType> resistance, int maxLifePoints);
	~Pokemon();
	std::string GetName();
	int GetLife();
	bool IsWeak();
	void Hurt(int damage, DamageType type);
	void Attack(Pokemon& other, int ability);
	void PassOut();
	void Heal(int healPoints);
	void AddAbilityAt(Ability ability, int abilityIndex);
	bool ExistsAbility(int index);
	Ability GetAbilityAt(int index);
	void SumUpPokemon();
};


#include "Pokemon.h"
#include <iostream>

using namespace std;

Pokemon::Pokemon() {
	mName = "Default Pokemon";
	mDescription = "A simple pokemon";
	mMaxLifePoints = 10;
	mCurrentLifePoints = mMaxLifePoints;
}

Pokemon::Pokemon(string name, string description, int maxLifePoints){
	mName = name;
	mDescription = description;
	mMaxLifePoints = maxLifePoints;
	mCurrentLifePoints = mMaxLifePoints;
	mResistance = vector<DamageType>();
}

Pokemon::Pokemon(std::string name, std::string description, vector<DamageType> resistance, int maxLifePoints)
{
	mName = name;
	mDescription = description;
	mMaxLifePoints = maxLifePoints;
	mCurrentLifePoints = mMaxLifePoints;
	mResistance = resistance;
}

Pokemon::~Pokemon()
{
	mResistance.~vector();
}

bool Pokemon::IsWeak(){
	return (mCurrentLifePoints <= mMaxLifePoints*0.2);
}


std::string Pokemon::GetName()
{
	return mName;
}

int Pokemon::GetLife()
{
	return mCurrentLifePoints;
}

void Pokemon::Hurt(int damage, DamageType type)
{
	bool resists = false;
	for (int i = 0; i < mResistance.size(); i++) {
		if (mResistance[i] == type) {
			resists = true;
			break;
		}
	}
	if (resists) {
		damage /= 2; // damage = damage / 2;
	}
	cout << mName << " a pris " << damage << "hp de domages de type "<<DamageTypeString(type)<<".\n";
	if (mCurrentLifePoints - damage < 0) {
		mCurrentLifePoints = 0;
		PassOut();
	}
	else {
		mCurrentLifePoints -= damage;
		//mCurrentLifePoints = mCurrentLifePoints - damage;
	}
}

void Pokemon::Attack(Pokemon& other, int ability)
{
	Ability usedAbility = mAbilities[ability];
	cout << mName << " utilise " << usedAbility.GetName() << " sur " << other.GetName() << 
		" et inflige " << usedAbility.GetDamages()<<"hp.\n";

	other.Hurt(usedAbility.GetDamages(), usedAbility.GetDamageType());
}

void Pokemon::PassOut()
{
	cout << mName << " has passed out from exhaustion\n";
}

void Pokemon::Heal(int healPoints)
{
	if (mCurrentLifePoints + healPoints > mMaxLifePoints) {
		mCurrentLifePoints = mMaxLifePoints;
	}
	else {
		mCurrentLifePoints += healPoints;
		//mCurrentLifePoints = mCurrentLifePoints + healPoints;
	}
}

void Pokemon::AddAbilityAt(Ability ability, int abilityIndex)
{
	cout << mName << " a appris la capacit� " << ability.GetName()<<endl;
	if (abilityIndex >= 0 && abilityIndex < 4) {
		mAbilities[abilityIndex] = ability;
	}
}

bool Pokemon::ExistsAbility(int index)
{
	if (index >= 0 && index < 4) {
		return mAbilities[index].GetName() != "Unassigned";
	}
	return false;
}

Ability Pokemon::GetAbilityAt(int index)
{
	if (index >= 0 && index < 4) {
		return mAbilities[index];
	}
	else {
		return Ability();
	}
}

void Pokemon::SumUpPokemon()
{
	cout << "=============================================\n";
	cout << mName << " est un pokemon " << mDescription << " qui a " 
		<< mCurrentLifePoints <<" / "<<mMaxLifePoints << " hp.\n";
	for (int i = 0; i < 4; i++)
	{
		cout << "\t" << i << "\t";
		mAbilities[i].SumUpAbility();
	}
	cout << "\n=============================================\n";
}

#include "Ability.h"
#include <iostream>
#include <string>
using namespace std;

Ability::Ability() {
    mName = "Unassigned";
    mDescription = "A simple name";
    mDamages = 3;
    mCost = 2;
    mMaxEnergy = 10;
    mCurrentEnergy = mMaxEnergy;
    ActivableAbility = true;
}

Ability::Ability(string name, string abilityDescription, DamageType type, int damage, int cost)
{
    mName = name;
    mDescription = abilityDescription;
    mDamages = damage;
    mCost = cost;
    ActivableAbility = true;
    mDamageType = type;
}

Ability::~Ability()
{

}

string Ability::GetName()
{
    return mName;
}

string Ability::GetDescription()
{
    return mName;
}

int Ability::GetDamages()
{
    return mDamages;
}

DamageType Ability::GetDamageType()
{
    return mDamageType;
}

int Ability::GetCost()
{
    return mCost;
}

void Ability::Energy(int cost)
{
    if (mCurrentEnergy - mCost <= 0)
    {
        mCurrentEnergy = 0;
        NoEnergy();
    }
    else
    {
        mCurrentEnergy = mCurrentEnergy - cost;
    }
}

void Ability::NoEnergy()
{
    bool ActivableAbility = false;
    cout << "you don't have enough energy ! \n";
}

void Ability::SumUpAbility() {
    if (mName == "Unassigned") {
        cout << "Unassigned\n";
    }else{
        cout << mName << " ~ " << mDescription << " ~ Force : " << mDamages << " ~ Cout : " << mCost << " pts d'energie.\n";
    }
}
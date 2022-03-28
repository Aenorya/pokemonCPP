#pragma once
#include <string>
#include "DamageType.h"
using namespace std;

class Ability {
private:
    string mName;
    string mDescription;
    int mDamages;
    int mCost;
    int mCurrentEnergy;
    int mMaxEnergy;
    DamageType mDamageType;

public:
    Ability();
    Ability(string name, string abilityDescription, DamageType type, int damage, int cost);
    ~Ability();
    string GetName();
    string GetDescription();
    bool ActivableAbility;
    int GetDamages();
    DamageType GetDamageType();
    int GetCost();
    void Energy(int cost);
    void NoEnergy();
    void SumUpAbility();


};
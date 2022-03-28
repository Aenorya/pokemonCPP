#pragma once
enum class DamageType {
	Fire,
	Electric,
	Water,
	Physical,
	Psych
};

static std::string DamageTypeString(DamageType type) {
	switch (type) {
		case DamageType::Fire: 
			return "feu";
		case DamageType::Electric:
			return "electrique";
		case DamageType::Water:
			return "eau";
		case DamageType::Psych:
			return "psy";
		case DamageType::Physical:
			return "physique";
		default:
			return "inconnu";
	}
}
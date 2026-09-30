#include "NormalMonster.h"
#include <random>

NormalMonster::NormalMonster(string categorie, string nom, int hpMax, int attaque, int defense, int mercyGoal, vector<string> actions)
	: Monster(categorie, nom, hpMax, attaque, defense, mercyGoal, actions) {
}

int NormalMonster::attack() {
	mt19937 rng(random_device{}());
	uniform_int_distribution<int> dist(0, getHpMax());
	return dist(rng);
}

vector<string> NormalMonster::getAvailabeActions() {
	return { getActions()[0], getActions()[1] };
}

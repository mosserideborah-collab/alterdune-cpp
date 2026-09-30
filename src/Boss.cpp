#include "Boss.h"
#include <random>

Boss::Boss(string categorie, string nom, int hpMax, int attaque, int defense, int mercyGoal, vector<string> actions)
	: Monster(categorie, nom, hpMax, attaque, defense, mercyGoal, actions) {
}

int Boss::attack() {
	mt19937 rng(random_device{}());
	uniform_int_distribution<int> dist(0, getHpMax());
	return dist(rng);
}

vector<string> Boss::getAvailabeActions() {
	return { getActions()[0], getActions()[1], getActions()[2], getActions()[3] };
}

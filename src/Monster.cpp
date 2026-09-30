#include "Monster.h"

Monster::Monster(string categorie, string nom, int hpMax, int attaque, int defense, int mercyGoal, vector<string> actions)
	: Entity(nom, hpMax) {
	this->categorie = categorie;
	this->attaque = attaque;
	this->defense = defense;
	this->mercyGoal = mercyGoal;
	this->mercyActuel = 0;
	this->actions = actions;
}

string Monster::getCategorie() {
	return categorie;
}

int Monster::getAttaque() {
	return attaque;
}

int Monster::getDefense() {
	return defense;
}

int Monster::getMercyGoal() {
	return mercyGoal;
}

vector<string> Monster::getActions() const {
	return actions;
}

int Monster::getMercyActuel() {
	return mercyActuel;
}

void Monster::setMercyActuel(int mercy) {
	if (mercy >= 0)
		this->mercyActuel = mercy;
}

vector<string> Monster::getAvailableActions() const {
	return actions;
}

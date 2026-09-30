#include "Entity.h"

Entity::Entity(std::string nom, int hpMax)
	: nom(nom), hpMax(hpMax), hpActuel(hpMax) {
}

std::string Entity::getNom() const {
	return nom;
}

int Entity::getHpMax() const {
	return hpMax;
}

int Entity::getHpActuel() const {
	return hpActuel;
}

void Entity::setHpActuel(int hp) {
	if (hp < 0) hp = 0;
	this->hpActuel = hp;
}

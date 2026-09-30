#include "Player.h"
#include <random>

Player::Player(string nom, int hpMax)
	: Entity(nom, hpMax) {
	this->victoires = 0;
	this->tues = 0;
	this->epargnes = 0;
}

int Player::getVictoires() const {
	return victoires;
}

int Player::getTues() {
	return tues;
}

int Player::getEpargnes() {
	return epargnes;
}

Inventory& Player::getInventory() {
	return inventory;
}

void Player::setVictoires(int v) {
	this->victoires = v;
}

void Player::setEpargnes(int e) {
	this->epargnes = e;
}

void Player::setTues(int t) {
	this->tues = t;
}

int Player::attack() {
	mt19937 rng(random_device{}());
	uniform_int_distribution<int> dist(0, getHpActuel());
	return dist(rng);
}

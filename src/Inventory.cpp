#include "Inventory.h"
#include "Player.h"
#include <iostream>
using namespace std;

Inventory::Inventory() {}

const std::vector<Item>& Inventory::getItems() const {
	return items;
}

void Inventory::addItem(const Item& item) {
	items.push_back(item);
}

bool Inventory::isEmpty() const {
	return items.empty();
}

void Inventory::afficher() {
	for (int i = 0; i < (int)items.size(); i++) {
		cout << i << ". " << items[i].getNom() << " x" << items[i].getQuantite() << endl;
	}
}

int Inventory::size() {
	return (int)items.size();
}

void Inventory::useItem(int index, Player& player) {
	if (index < 0 || index >= (int)items.size()) {
		cout << "Item invalide !" << endl;
		return;
	}

	if (items[index].getQuantite() <= 0) {
		cout << "Plus de " << items[index].getNom() << " !" << endl;
		return;
	}

	int soin = items[index].getValeur();
	int nouveauHp = player.getHpActuel() + soin;
	if (nouveauHp > player.getHpMax())
		nouveauHp = player.getHpMax();
	player.setHpActuel(nouveauHp);
	cout << "Tu utilises " << items[index].getNom() << " et recuperes " << soin << " HP !" << endl;
	items[index].setQuantite(items[index].getQuantite() - 1);
}

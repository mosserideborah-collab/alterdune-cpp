#pragma once
#include <string>
#include <vector>
#include "Item.h"

class Player;
class Inventory {
private:
	std::vector<Item> items;

public:
	Inventory();
	const std::vector<Item>& getItems() const;
	void addItem(const Item& item);
	void useItem(int index, Player& player);
	void afficher();
	bool isEmpty() const;
	int size();
};

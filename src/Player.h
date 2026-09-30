#pragma once
#include "Inventory.h"
#include "Entity.h"
using namespace std;

class Player : public Entity {
private:
	int victoires;
	int tues;
	int epargnes;
	Inventory inventory;

public:
	Player(string nom, int hpMax);
	int getVictoires() const;
	int getTues();
	int getEpargnes();
	Inventory& getInventory();
	void setVictoires(int victoire);
	void setTues(int tues);
	void setEpargnes(int epargnes);
	int attack();
};

#pragma once
#include <string>
#include <vector>
#include "Entity.h"
using namespace std;

class Monster : public Entity {
private:
	string categorie;
	int attaque;
	int defense;
	int mercyGoal;
	int mercyActuel;
	vector<string> actions;

public:
	Monster(string categorie, string nom, int hpMax, int attaque, int defense, int mercyGoal, vector<string> actions);
	string getCategorie();
	int getAttaque();
	int getDefense();
	int getMercyGoal();
	int getMercyActuel();
	vector<string> getActions() const;
	void setMercyActuel(int mercy);
	virtual int attack() = 0;
	vector<string> getAvailableActions() const;
};

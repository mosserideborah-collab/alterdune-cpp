#pragma once
#include "Monster.h"
#include <string>
#include <vector>
using namespace std;

class MiniBoss : public Monster {
public:
	MiniBoss(string categorie, string nom, int hpMax, int attaque, int defense, int mercyGoal, vector<string> actions);

	int attack();
	vector<string> getAvailabeActions();
};

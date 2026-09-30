#pragma once
#include "Monster.h"
#include <vector>
using namespace std;

struct BestiaryEntry {
	Monster* monster;
	bool wasKilled;
};

class Bestiary {
private:
	vector<BestiaryEntry> entries;

public:
	void addEntry(Monster* monster, bool wasKilled);
	void afficher();
};

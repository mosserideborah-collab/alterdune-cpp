#pragma once
#include "Player.h"
#include "Monster.h"
#include "Bestiary.h"
#include "ACTCatalogue.h"
#include <vector>
#include <string>
using namespace std;

class Game {
private:
	Player player;
	vector<Monster*> monsters;
	Bestiary bestiary;
	ACTCatalogue catalogue;

public:
	Game();
	void run();
	void afficherMenu();
	void demarrerCombat();
	void afficherStats();
	void chargerItems(string fichier);
	void chargerMonstres(string fichier);
	void finDePartie();
};

#pragma once
#include <string>
using namespace std;

class ACTAction {
private:
	string identifiant;
	string texte;
	int impactMercy;

public:
	ACTAction();
	ACTAction(string identifiant, string texte, int impactMercy);

	string getIdentifiant();
	string getTexte();
	int getImpactMercy();
};

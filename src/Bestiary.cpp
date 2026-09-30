#include "Bestiary.h"
#include <iostream>

void Bestiary::addEntry(Monster* monster, bool wasKilled) {
	BestiaryEntry entry;
	entry.monster = monster;
	entry.wasKilled = wasKilled;
	entries.push_back(entry);
}

void Bestiary::afficher() {
	for (BestiaryEntry entry : entries) {
		cout << entry.monster->getNom() << endl;
		cout << entry.monster->getCategorie() << endl;
		if (entry.wasKilled)
			cout << "Resultat : Tue" << endl;
		else
			cout << "Resultat : Epargne" << endl;
		cout << "----------" << endl;
	}
}

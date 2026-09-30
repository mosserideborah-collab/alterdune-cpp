#pragma once
#include <string>
using namespace std;

class Item {
private:
	string nom;
	string type;
	int valeur;
	int quantite;

public:
	Item(string nom, string type, int valeur, int quantite);
	string getNom();
	string getType();
	int getValeur();
	int getQuantite();

	void setQuantite(int quantite);
};

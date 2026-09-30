#include "Item.h"

Item::Item(string nom, string type, int valeur, int quantite) {
	this->nom = nom;
	this->type = type;
	this->valeur = valeur;
	this->quantite = quantite;
}

string Item::getNom() {
	return nom;
}

string Item::getType() {
	return type;
}

int Item::getValeur() {
	return valeur;
}

int Item::getQuantite() {
	return quantite;
}

void Item::setQuantite(int quantite) {
	if (quantite >= 0)
		this->quantite = quantite;
}

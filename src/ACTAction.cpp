#include "ACTAction.h"

ACTAction::ACTAction(string identifiant, string texte, int impactMercy) {
	this->identifiant = identifiant;
	this->texte = texte;
	this->impactMercy = impactMercy;
}

ACTAction::ACTAction() {
	identifiant = "";
	texte = "";
	impactMercy = 0;
}

string ACTAction::getIdentifiant() {
	return identifiant;
}

string ACTAction::getTexte() {
	return texte;
}

int ACTAction::getImpactMercy() {
	return impactMercy;
}

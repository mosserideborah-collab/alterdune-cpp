#include "ACTCatalogue.h"

ACTCatalogue::ACTCatalogue() {
	actions.emplace("PRIER", ACTAction("PRIER", "Tu pries les dieux... le monstre est emu", 20));
	actions.emplace("COMPLIMENTER", ACTAction("COMPLIMENTER", "Tu flattes le monstre... il rougit", 15));
	actions.emplace("OFFRIR", ACTAction("OFFRIR", "Tu offres une olive... le monstre hesite", 25));
	actions.emplace("DANSER", ACTAction("DANSER", "Tu danses le sirtaki... le monstre s'ambiance avec toi", 10));
	actions.emplace("PHILOSOPHER", ACTAction("PHILOSOPHER", "Tu cites Socrate... le monstre reflechit", 15));
	actions.emplace("INSULTER", ACTAction("INSULTER", "Tu viens de l'insulter... mauvaise idee", -20));
	actions.emplace("SE MOQUER", ACTAction("SE MOQUER", "Tu viens de te moquer de lui... il s'enerve", -15));
	actions.emplace("IGNORER", ACTAction("IGNORER", "Tu l'ignores... il est vexe", -10));
	actions.emplace("CHANTER", ACTAction("CHANTER", "Tu chantes une ode... le monstre sourit", 10));
}

ACTAction ACTCatalogue::getAction(const std::string& identifiant) {
	return actions.at(identifiant);
}

bool ACTCatalogue::exists(const std::string& identifiant) {
	return actions.count(identifiant) > 0;
}

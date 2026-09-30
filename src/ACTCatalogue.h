#pragma once
#include <map>
#include <string>
#include "ACTAction.h"

class ACTCatalogue {
private:
	std::map<std::string, ACTAction> actions;

public:
	ACTCatalogue();
	ACTAction getAction(const std::string& identifiant);
	bool exists(const std::string& identifiant);
};

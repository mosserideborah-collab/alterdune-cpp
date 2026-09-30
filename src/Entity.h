#pragma once
#include <string>

class Entity {
private:
	std::string nom;
	int hpMax;
	int hpActuel;

public:
	Entity(std::string nom, int hpMax);
	std::string getNom() const;
	int getHpMax() const;
	int getHpActuel() const;
	void setHpActuel(int hp);
	virtual int attack() = 0;
};

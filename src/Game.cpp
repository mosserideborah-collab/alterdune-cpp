#include "Game.h"
#include "NormalMonster.h"
#include "MiniBoss.h"
#include "Boss.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
using namespace std;

Game::Game() : player("", 100) {}

void Game::run() {
	string nom;
	cout << "Entre ton nom : ";
	cin >> nom;
	player = Player(nom, 100);

	chargerItems("data/items.csv");
	chargerMonstres("data/monsters.csv");

	while (player.getVictoires() < 10) {
		afficherMenu();
		int choix;
		cin >> choix;

		if (choix == 1)
			bestiary.afficher();
		else if (choix == 2)
			demarrerCombat();
		else if (choix == 3)
			afficherStats();
		else if (choix == 4)
			player.getInventory().afficher();
		else if (choix == 5)
			break; // quitter
	}

	finDePartie();
}

void Game::afficherMenu() {
	cout << "===================" << endl;
	cout << "    ALTERDUNE" << endl;
	cout << "===================" << endl;
	cout << "1. Bestiaire" << endl;
	cout << "2. Demarrer un combat" << endl;
	cout << "3. Statistiques" << endl;
	cout << "4. Items" << endl;
	cout << "5. Quitter" << endl;
	cout << "===================" << endl;
	cout << "Ton choix : ";
}

void Game::afficherStats() {
	cout << "===================" << endl;
	cout << "NOM DU JOUEUR : " << player.getNom() << endl;
	cout << "HP : " << player.getHpActuel() << "/" << player.getHpMax() << endl;
	cout << "Monstres tues : " << player.getTues() << endl;
	cout << "Monstres epargnes : " << player.getEpargnes() << endl;
	cout << "Victoires : " << player.getVictoires() << "/10" << endl;
	cout << "===================" << endl;
}

void Game::chargerItems(string fichier) {
	ifstream file(fichier);

	if (!file.is_open()) {
		cout << "Erreur : fichier " << fichier << " introuvable !" << endl;
		exit(1);
	}

	string ligne;
	getline(file, ligne);

	while (getline(file, ligne)) {
		stringstream ss(ligne);
		string nom, type, valeurStr, quantiteStr;

		getline(ss, nom, ';');
		getline(ss, type, ';');
		getline(ss, valeurStr, ';');
		getline(ss, quantiteStr, ';');
		int valeur = stoi(valeurStr);
		int quantite = stoi(quantiteStr);

		Item item(nom, type, valeur, quantite);
		player.getInventory().addItem(item);
	}
	cout << "Items charges !" << endl;
}

void Game::chargerMonstres(string fichier) {
	ifstream file(fichier);

	if (!file.is_open()) {
		cout << "Erreur : fichier " << fichier << " introuvable !" << endl;
		exit(1);
	}

	string ligne;
	getline(file, ligne); // sauter la premiere ligne

	while (getline(file, ligne)) {
		stringstream ss(ligne);
		string categorie, nom, hpStr, atkStr, defStr, mercyStr, a1, a2, a3, a4;

		getline(ss, categorie, ';');
		getline(ss, nom, ';');
		getline(ss, hpStr, ';');
		getline(ss, atkStr, ';');
		getline(ss, defStr, ';');
		getline(ss, mercyStr, ';');
		getline(ss, a1, ';');
		getline(ss, a2, ';');
		getline(ss, a3, ';');
		getline(ss, a4, ';');

		int hp = stoi(hpStr);
		int atk = stoi(atkStr);
		int def = stoi(defStr);
		int mercy = stoi(mercyStr);

		vector<string> actions = { a1, a2, a3, a4 };

		Monster* monster = nullptr;
		if (categorie == "NORMAL")
			monster = new NormalMonster(categorie, nom, hp, atk, def, mercy, actions);
		else if (categorie == "MINIBOSS")
			monster = new MiniBoss(categorie, nom, hp, atk, def, mercy, actions);
		else if (categorie == "BOSS")
			monster = new Boss(categorie, nom, hp, atk, def, mercy, actions);

		if (monster != nullptr)
			monsters.push_back(monster);
	}
	cout << "Monstres charges !" << endl;
}

void Game::finDePartie() {
	cout << "===================" << endl;
	cout << "  FIN DE PARTIE !" << endl;
	cout << "===================" << endl;

	if (player.getTues() == 0)
		cout << "FIN PACIFISTE : tu as epargne tous les monstres !" << endl;
	else if (player.getEpargnes() == 0)
		cout << "FIN GENOCIDAIRE : tu as tue tous les monstres !" << endl;
	else
		cout << "FIN NEUTRE : tu as tue et epargne des monstres." << endl;
}

void Game::demarrerCombat() {
	if (monsters.empty()) {
		cout << "Aucun monstre charge !" << endl;
		return;
	}

	mt19937 rng(random_device{}());
	uniform_int_distribution<size_t> distMonstre(0, monsters.size() - 1);
	Monster* monstre = monsters[distMonstre(rng)];

	monstre->setHpActuel(monstre->getHpMax());
	monstre->setMercyActuel(0);

	cout << "Un " << monstre->getNom() << " apparait !" << endl;
	while (monstre->getHpActuel() > 0 && player.getHpActuel() > 0) {
		cout << "\n--- COMBAT ---" << endl;
		cout << monstre->getNom() << " HP : " << monstre->getHpActuel() << "/" << monstre->getHpMax() << endl;
		cout << "Mercy : " << monstre->getMercyActuel() << "/" << monstre->getMercyGoal() << endl;
		cout << "Tes HP : " << player.getHpActuel() << "/" << player.getHpMax() << endl;
		cout << "\nFIGHT(1)  ACT(2)  ITEM(3)  MERCY(4)" << endl;

		int choix;
		cin >> choix;

		if (choix == 1) {
			uniform_int_distribution<int> dist(0, monstre->getHpMax());
			int degats = dist(rng);
			int degatsReels = min(degats, monstre->getHpActuel());
			monstre->setHpActuel(monstre->getHpActuel() - degats);
			cout << "Tu infliges " << degatsReels << " degats !" << endl;
		}
		else if (choix == 2) {
			vector<string> actionsDisponibles = monstre->getAvailableActions();
			cout << "Choisis une action :" << endl;
			for (int i = 0; i < (int)actionsDisponibles.size(); i++) {
				if (actionsDisponibles[i] != "-")
					cout << i + 1 << ". " << actionsDisponibles[i] << endl;
			}
			int choixAct;
			cin >> choixAct;
			if (choixAct < 1 || choixAct > (int)actionsDisponibles.size()) {
				cout << "Choix invalide !" << endl;
				continue;
			}
			string identifiant = actionsDisponibles[choixAct - 1];
			if (catalogue.exists(identifiant)) {
				ACTAction action = catalogue.getAction(identifiant);
				cout << action.getTexte() << endl;
				int nouveauMercy = monstre->getMercyActuel() + action.getImpactMercy();
				if (nouveauMercy < 0) nouveauMercy = 0;
				if (nouveauMercy > monstre->getMercyGoal()) nouveauMercy = monstre->getMercyGoal();
				monstre->setMercyActuel(nouveauMercy);
				cout << "Mercy : " << monstre->getMercyActuel() << "/" << monstre->getMercyGoal() << endl;
			}
		}
		else if (choix == 3) {
			player.getInventory().afficher();
			cout << "Quel item ? ";
			int index;
			if (!(cin >> index)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Entree invalide !" << endl;
				continue;
			}
			if (index < 0 || index >= player.getInventory().size()) {
				cout << "Index invalide !" << endl;
				continue;
			}
			player.getInventory().useItem(index, player);
		}
		else if (choix == 4) {
			if (monstre->getMercyActuel() >= monstre->getMercyGoal()) {
				cout << "Tu epargnes le " << monstre->getNom() << " !" << endl;
				player.setVictoires(player.getVictoires() + 1);
				player.setEpargnes(player.getEpargnes() + 1);
				bestiary.addEntry(monstre, false);
				return;
			}
			else {
				cout << "Mercy pas encore disponible !" << endl;
			}
		}

		if (monstre->getHpActuel() <= 0) {
			cout << monstre->getNom() << " est vaincu !" << endl;
			player.setVictoires(player.getVictoires() + 1);
			player.setTues(player.getTues() + 1);
			bestiary.addEntry(monstre, true);
			return;
		}

		uniform_int_distribution<int> dist2(0, player.getHpMax());
		int degatsMontre = dist2(rng);
		int degatsReelsMontre = min(degatsMontre, player.getHpActuel());
		player.setHpActuel(player.getHpActuel() - degatsMontre);
		cout << monstre->getNom() << " t'attaque et inflige " << degatsReelsMontre << " degats !" << endl;
		if (player.getHpActuel() <= 0) {
			cout << "Tu es mort... GAME OVER !" << endl;
			exit(0);
		}
	}
}

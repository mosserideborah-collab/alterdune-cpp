# ALTERDUNE

A small turn-based RPG played in the console, inspired by Undertale and set in Greek mythology. We wrote it for our Object-Oriented Programming in C++ course at ESILV (2026). The goal was to practise encapsulation, inheritance, polymorphism and composition.

Team: Hela Mouakhar, Alice Nassiri and Déborah Mosseri.

## The game

You fight monsters picked at random: satyrs, harpies, a cyclops, the Minotaur, Medusa and the Hydra. On each turn you can:
- **FIGHT**: attack the monster
- **ACT**: talk to it (pray, compliment, dance the sirtaki, quote Socrates, insult it…). Each action raises or lowers the monster's *Mercy* gauge.
- **ITEM**: drink nectar or ambrosia to get HP back
- **MERCY**: spare the monster, once its Mercy gauge is full

After 10 victories the game ends, and the ending depends on what you did. You get a pacifist ending if you spared everyone, a genocide ending if you killed everyone, and a neutral ending otherwise. A bestiary keeps track of every monster you met.

## Build

```bash
make
./alterdune
```

Or: `g++ -std=c++17 src/*.cpp -o alterdune`. Run it from the repository root so it can find the `data/` folder.

## Structure

```
Entity (abstract)
├── Player          has an Inventory of Items
└── Monster (abstract)
    ├── NormalMonster
    ├── MiniBoss
    └── Boss

Game: menus and fights. It holds the Player, the monsters, the Bestiary and the ACTCatalogue.
```

Monsters and items are loaded from `data/monsters.csv` and `data/items.csv`, so you can add a monster without touching the code. The ACT actions are stored in a `std::map` (action ID → text and effect on Mercy).

## Things we would fix with more time
- use `std::unique_ptr` for the monsters instead of raw pointers
- make `getAvailableActions()` virtual, so each monster category only shows its own actions
- use the monsters' attack and defense stats in the damage formula
- handle bad input in the main menu

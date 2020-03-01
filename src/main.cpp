#include <iostream>
#include "automata.h"

int main() {

    Automata Drinks({ {"Water", 20}, {"Coffee", 40}, {"Tea", 30} });
    Drinks.on();
    Drinks.coin(60);
    Drinks.printMenu();
    Drinks.choice(2);
    Drinks.cancel();
    Drinks.choice(1);
    Drinks.off();

    return 0;
}
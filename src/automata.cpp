#include <iostream>
#include "automata.h"

bool Automata::isOn() {
    return state == STATES::OFF;
}

Automata::Automata(const vector<Drink> menu) {
    this->menu = menu;
}

void Automata::on() {
    state = STATES::WAIT;
    printState();
}

unsigned int Automata::off() {
    state = STATES::OFF;
    unsigned int cashToReturn = cash;
    cash = 0;
    cout << "Don't forget to take your change!" << endl << endl;
    printState();
    return cashToReturn;
}

unsigned int Automata::coin(unsigned int coins) {
    if (isOn())
        return 0;
    state = STATES::ACCEPT;
    cash += coins;
    printState();
    return cash;
}

void Automata::printMenu() {
    if (isOn())
        return;
    cout << "Menu:" << endl;
    for (size_t i = 0; i < menu.size(); i++)
        cout << i + 1 << ": " << menu[i].name << " - " << menu[i].price << endl;
    cout << endl;
}

void Automata::printState() {
    cout << "State: " << string_STATES[state] << endl;
    cout << "Current cash: " << cash << endl;
    cout << endl;
}

bool Automata::choice(unsigned int drink) {
    if (isOn())
        return false;
    state = STATES::CHECK;
    if (check(drink)) {
        cook(drink);
        printState();
        finish();
        printState();
        return true;
    }
    else {
        state = STATES::NOT_ENOUGH_MONEY;
        printState();
        return false;
    }
}

bool Automata::check(unsigned int drink) {
    if (isOn())
        return 0;
    return menu[drink - 1].price <= cash;
}

void Automata::cancel() {
    if (isOn())
        return;
    state = STATES::WAIT;
    cout << "Order cancellation..." << endl << endl;
    printState();
}

void Automata::cook(unsigned int drink) {
    if (isOn())
        return;
    cash -= menu[drink - 1].price;
    state = STATES::COOK;
}

void Automata::finish() {
    if (isOn())
        return;
    state = STATES::FINISH;
    printState();
    state = STATES::WAIT;
}
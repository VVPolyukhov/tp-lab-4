#pragma once

#include <vector>
#include <string>
using namespace std;

struct Drink {
    string name;
    unsigned int price;
};

class Automata {
private:
    enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK, FINISH, NOT_ENOUGH_MONEY };
    vector<string> string_STATES = { "OFF", "WAIT", "ACCEPT", "CHECK", "COOK", "FINISH", "NOT ENOUGH MONEY" };
    unsigned int cash = 0;
    STATES state = STATES::OFF;
    vector<Drink> menu;
public:
    Automata(const vector<Drink>);
    void on();
    unsigned int off();
    unsigned int coin(unsigned int);
    void printMenu();
    void printState();
    bool choice(unsigned int);
    bool check(unsigned int);
    void cancel();
    void cook(unsigned int);
    void finish();
    bool isOn();
};
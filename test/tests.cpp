#include "gtest/gtest.h"
#include "Automata.h"

TEST(lab4, test1)
{
	Automata Drinks({{"Water", 20}, {"Coffee", 40}, {"Tea", 30}});
    Drinks.on();
    unsigned int current_cash = Drinks.coin(30);    
    unsigned int result=30;
    EXPECT_EQ(current_cash, result);
}

TEST(lab4, test2)
{
	Automata Drinks({{"Water", 20}, {"Coffee", 40}, {"Tea", 30}});
    Drinks.on();
    Drinks.coin(30);
	Drinks.coin(2);
    unsigned int return_cash = Drinks.off();
	unsigned int result=32;
    EXPECT_EQ(return_cash, result);
}

TEST(lab4, test3)
{
	Automata Drinks({{"Water", 20}, {"Coffee", 40}, {"Tea", 30}});
    Drinks.on();
    Drinks.coin(14);
    Drinks.printMenu();
	Drinks.coin(6);
    bool recall = Drinks.choice(1);
	bool result = true;
    EXPECT_EQ(recall, result);
	
}

TEST(lab4, test4)
{
	Automata Drinks({{"Water", 20}, {"Coffee", 40}, {"Tea", 30}});
    Drinks.on();
    Drinks.coin(30);
    bool recall = Drinks.check(3);
	bool result = true;
    EXPECT_EQ(recall, result);
	
}
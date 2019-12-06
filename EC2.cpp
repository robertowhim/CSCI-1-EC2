/**

 * 

 * Chapter 11 Problem 13

 * Name: Roberto M Martinez

 * Date: 12/5/2019

 * Program summary:
 This program acts as a vending machine, program will take
 a user's input on which drink they would like. From there
 it will ask the user for money and the program will track
 how much money it has made and display it after the user quits.

 **/



#include <iostream>

#include <cassert>

#include <string>



using namespace std;


struct soda
{
    double cost;
    int amount;
};



/**

 Program Purpose: Have a vending machine with 5 different drinks and
 the user should be able to choose a drink or quit out of it.
 If the user choses a drink, they have to input how much they are 
 going to pay. They vending machine will keep track of how much 
 money it has made and display the amount once the user quits.


 **/

/** 
Input: the type of soda (struct) that has the information of the amount
of drink and it's cost, along with the money needed to buy it, the user
inputs the money to buy the drink
Output: the updated soda strcut, reduced the amount of drink.
Purpose: Check if user's pay amount is appropriate, then reduce the
amount of drinks in the vending machine.
**/
soda buy(soda type, double money);

/**
Input: The soda selected (option) by the user and how much money
the machine has made up to this point.
Output: The amount of money earned after the purchase of soda
that was selected.
Purpose: Adds the amount of money made, depending on type of drink,
to the money already made.
**/
double money_store(string option, double money_earned);

void test_buy();

void test_money_stored();

void test();

void run();


int main() {

  char t;

  cout << "Enter [t] to test, or any other character to run." << endl;

  cin >> t;

  if(t == 't') {

    test();

  } else {

    run();

  }

}

void test() 
{

    test_buy;
    test_money_stored;

}

/**
Pseudocode:
#Determine whether the customer wants a drink or quit.
#Sell a drink to customer.
## Determine which drink price and amount to use.
## Check if the customer's payment amount is valid.
## Reduce the amount of drinks left.
#Track amount of money made.
## Get amount of money spent by customer depending of the option
    the customer chose.
## Add amount of money spent by the customer to the total 
    money earned by the machine.
#Display money made when costumer is finished buying.
**/


void run() {

 soda cola = { cola.cost = 0.75, cola.amount = 20 };
    soda root_beer = { root_beer.cost = 0.75, root_beer.amount = 20 };
    soda lemon_lime = { lemon_lime.cost = 0.75, lemon_lime.amount = 20 };
    soda grape_soda = { grape_soda.cost = 0.80, grape_soda.amount = 20 };
    soda cream_soda = { cream_soda.cost = 0.80, cream_soda.amount = 20 };
    soda machine[5] = { cola, root_beer, lemon_lime, grape_soda, cream_soda };
    double money_earned = 0;
    string option = "start";
    while (option != "quit")
    {
        double money = 0;
        cout << "Which soda would you like?" << endl
            << "If you want to exit, type 'quit'." << endl
            << "Cola    Cost: " << machine[0].cost
            << " Amount: " << machine[0].amount << endl
            << "Root_Beer    Cost: " << machine[1].cost
            << " Amount: " << machine[1].amount << endl
            << "Lemon_Lime    Cost: " << machine[2].cost
            << " Amount: " << machine[2].amount << endl
            << "Grape_Soda    Cost: " << machine[3].cost
            << " Amount: " << machine[3].amount << endl
            << "Cream_Soda    Cost: " << machine[4].cost
            << " Amount: " << machine[4].amount << endl;
        cin >> option;
        if (option == "Cola")
        {
            machine[0] = buy(machine[0], money);
        }
        else if (option == "Root_Beer")
        {
            machine[1] = buy(machine[1], money);
        }
        else if (option == "Lemon_Lime")
        {
            machine[2] = buy(machine[2], money);
        }
        else if (option == "Grape_Soda")
        {
            machine[3] = buy(machine[3], money);
        }
        else if (option == "Cream_Soda")
        {
            machine[4] = buy(machine[4], money);
        }
        money_earned = money_store(option, money_earned);
    }
    cout << "Money earned by machine: " << money_earned << endl;

}



soda buy(soda type, double money)
{
    cout << "Please input money amount. (Does not accept more than 1$)" << endl;
    while (money > 1 || money <= type.cost)
    {
        cin >> money;
        if (money > 1 || money <= type.cost)
        {
            cout << "Invalid amount, please enter another amount" << endl;
            cin >> money;
        }
    }
    type.amount = type.amount - 1;
    return type;
}

double money_store(string option, double money_earned)
{
    if (option == "Cola")
    {
        money_earned = money_earned + 0.75;
    }
    else if (option == "Root_Beer")
    {
        money_earned = money_earned + 0.75;
    }
    else if (option == "Lemon_Lime")
    {
        money_earned = money_earned + 0.75;
    }
    else if (option == "Grape_Soda")
    {
        money_earned = money_earned + 0.8;
    }
    else if (option == "Cream_Soda")
    {
        money_earned = money_earned + 0.8;
    }
    return money_earned;
}

void test_buy()
{
    //I don't know how to test this
}

 void test_money_stored()
{
    assert(money_store("Cola", 0) == 0.75);
    assert(money_store("Lemon_Lime", 3.0) == 3.75);
    assert(money_store("NAO", 0) == 0);
}

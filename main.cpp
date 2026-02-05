#include <iostream>
#include "Menu.h"
#include "Ordering.h"
using namespace std;
using namespace seneca;

    int main() {
        Ordering order("drinks.csv", "foods.csv");

        if (!order) {
            cout << "Failed to open data files or the data files are corrupted!" << endl;
            return 1;
        }

        Menu mainMenu("Seneca Restaurant ", "End Program", 0);
        mainMenu << "Order" << "Print Bill" << "Start a New Bill" << "List Foods" << "List Drinks";

        Menu orderMenu ("Order Menu", "Back to main menu", 1);
        orderMenu << "Food" << "Drink";

        Menu confirmMenu("You have bills that are not saved, are you sue you want to exit?", "No", 0);
        confirmMenu << "Yes";

        bool complete = false;

        size_t mainSelection = -1;
        while (complete == false || mainSelection != 0) {
            mainSelection = mainMenu.select();
            switch (mainSelection) {
                case 1: {
                    size_t subSelection = -1;
                    while (subSelection != 0) {
                        subSelection = orderMenu.select();
                        if ( subSelection == 1) {
                            order.orderFood();
                        }
                        else if (subSelection == 2) {
                            order.orderDrink();
                        }
                    }
                    break;
                }
                case 2:
                    order.printBill();
                    break;
                case 3:
                    order.resetBill();
                    break;
                case 4:
                    order.listFoods();
                    break;
                case 5:
                    order.listDrinks();
                    break;
                case 0:
                    if (order.hasUnsavedBill() == true) {
                        size_t confirm = confirmMenu.select();
                        if (confirm == 1) {
                            complete = true;
                        }
                    } else {
                        complete = true;
                    }
                    break;
            }
        }

        return 0;
    }

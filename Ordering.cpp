/* Citation and Sources...
Final Project Milestone 4:
Module: Ordering
Filename: Ordering.cpp
Version 1.0
Author: Caroline Chen, StNo: 112747241, Email: cchen247@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason

-----------------------------------------------------------
Citation to indicate that you have done all the work yourself
-----------------------------------------------------------*/
#include "Ordering.h"
#include "Menu.h"
#include "Utils.h"
#include "constants.h"
#include <cstdio>
#include <fstream>
#include <iomanip>
using namespace std;
namespace seneca {

    void Ordering::billTitlePrint(ostream& ostr) const{
        ostr << "Bill # " << setw(3) << setfill('0') << billSerialNumber << setfill(' ')
         << " =============================" << endl;
    }

    void Ordering::printTotals(ostream& ostr, double totalAmount) const {
        ostr << fixed << setprecision(2);
        ostr << "                     Total:         " << totalAmount << endl;
        ostr << "                     Tax:           " << totalAmount * Tax << endl;
        ostr << "                     Total+Tax:     " << totalAmount + totalAmount * Tax << endl;
        ostr << "========================================" << endl;
    }

    size_t Ordering::countRecords(const char* filename) const {
        size_t count = 0;
        ifstream fin(filename);
        char character{};

        while (fin.get(character)) {
            if (character == '\n') count++;
        }
        return count;
    }

    Ordering::Ordering(const char* drinkFile, const char* foodFile) {
        size_t foodRecords = countRecords(foodFile);
        size_t drinkRecords = countRecords(drinkFile);

        ifstream fFood(foodFile);
        ifstream fDrink(drinkFile);

        if (fFood.good() && fDrink.good()) {
            food = new Food[foodRecords];
            drink = new Drink[drinkRecords];

            size_t foodCount = 0;
            size_t drinkCount = 0;

            for (size_t i = 0; i < foodRecords; i++) {
                if (!food[i].read(fFood)) break;
                foodCount++;
            }

            // Load drinks
            for (size_t i = 0; i < drinkRecords; i++) {
                if (!drink[i].read(fDrink)) break;
                drinkCount++;
            }

            if (foodCount != foodRecords || drinkCount != drinkRecords) {
                delete[] food;
                food = nullptr;
                delete[] drink;
                drink = nullptr;
            } else {
                foodCounter = foodCount;
                drinkCounter = drinkCount;
            }
        }
    }

    Ordering::~Ordering() {
        delete[] food;
        delete[] drink;

        for (size_t i = 0; i < billableCounter; i++) {
            delete billable[i];
        }
    }

    Ordering::operator bool() const {
        if (food != nullptr && drink != nullptr) {
            return true;
        } else {
            return false;
        }
    }

    size_t Ordering::noOfBillItems() const {
        return billableCounter;
    }

    bool Ordering::hasUnsavedBill() const {
        if (billableCounter > 0) {
            return true;
        } else {
            return false;
        }
    }

    void Ordering::listFoods(ostream& ostr) const {
        ostr << "List Of Avaiable Meals" << endl;
        ostr << "========================================" << endl;
        for (size_t i = 0; i < foodCounter; i++) {
            food[i].print() << endl;
        }
        ostr << "========================================" << endl;
    }

    void Ordering::listDrinks(ostream& ostr) const {
        ostr << "List Of Avaiable Drinks" << endl;
        ostr << "========================================" << endl;
        for (size_t i = 0; i < drinkCounter; i++) {
            drink[i].print() << endl;
        }
        ostr << "========================================" << endl;
    }

    void Ordering::orderFood() {
        Menu m("Food Menu", "Back to Order", 2);
        for (size_t i = 0; i < foodCounter; i++) {
            m << food[i].getName();
        }

        size_t selection = m.select();

        if (selection != 0) {
            Food* orderedFood = new Food(food[selection - 1]);

            if (orderedFood->order()) {
                billable[billableCounter++] = orderedFood;
            } else {
                delete orderedFood;
            }
        }
    }

    void Ordering::orderDrink() {
        Menu m("Drink Menu", "Back to Order", 2);
        for (size_t i = 0; i < drinkCounter; i++) {
            m << drink[i].getName();
        }

        size_t selection = m.select();

        if (billableCounter >= MaximumNumberOfBillItems) return;

        if (selection != 0) {
            Drink* orderedDrink = new Drink(drink[selection - 1]);

            if (orderedDrink->order()) {
                billable[billableCounter++] = orderedDrink;
            } else {
                delete orderedDrink;
            }
        }
    }

    void Ordering::printBill(ostream& ostr) const {
        double totalPrice = 0;

        billTitlePrint(ostr);

        for (size_t i = 0; i < billableCounter; i++) {
            billable[i]->print(ostr) << endl;
            totalPrice += billable[i]->price();
        }

        printTotals(ostr, totalPrice);
    }

    void Ordering::resetBill() {
        char filename[50]{};
        Utils utils;
        utils.makeBillFileName(filename, billSerialNumber);

        ofstream fout(filename);
        if (fout.good()) {
            printBill(fout);
        }

        cout << "Saved bill number " << billSerialNumber << endl;
        cout << "Starting bill number " << (billSerialNumber + 1) << endl;

        for (size_t i = 0; i < billableCounter; i++) {
            delete billable[i];
            billable[i] = nullptr;
        }

        billableCounter = 0;
        billSerialNumber++;
    }

} // seneca
#ifndef ORDERING_H
#define ORDERING_H
#include "constants.h"
#include "Drink.h"
#include "Food.h"
#include "Utils.h"

using namespace std;
namespace seneca {
    class Ordering {
        unsigned int foodCounter{};
        unsigned int drinkCounter{};
        unsigned int billableCounter{};
        unsigned int billSerialNumber{1};

        Food* food{};
        Drink* drink{};

        Billable* billable[MaximumNumberOfBillItems]{};

        void billTitlePrint(ostream& ostr) const;
        void printTotals(ostream& ostr, double totalAmount) const;

        size_t countRecords(const char* file) const;

    public:
        Ordering(const char* drinkFile, const char* foodFile);
        ~Ordering();

        operator bool() const;
        size_t noOfBillItems() const;
        bool hasUnsavedBill() const;

        void listFoods(ostream& ostr = cout) const;
        void listDrinks(ostream& ostr = cout) const;

        void orderFood();
        void orderDrink();

        void printBill(ostream& ostr = cout) const;
        void resetBill();

    };
} // seneca

#endif //ORDERING_H

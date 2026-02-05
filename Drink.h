/* Citation and Sources...
Final Project Milestone 3:
Module: Drink
Filename: Drink.h
Version 1.0
Author: Caroline Chen, StNo: 112747241, Email: cchen247@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason

-----------------------------------------------------------
Citation to indicate that you have done all the work yourself
-----------------------------------------------------------*/

#ifndef DRINK_H
#define DRINK_H
#include <iostream>
#include "Billable.h"
using namespace std;
namespace seneca {
    class Drink : public Billable {
        char m_size{};
    public:
        Drink();
        virtual ~Drink();

        virtual ostream& print(ostream& ostr = cout)const;
        virtual bool order();
        virtual bool ordered()const;
        virtual ifstream& read(ifstream& file);

        virtual double price() const;

    };
}
#endif //DRINK_H
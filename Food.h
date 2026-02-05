/* Citation and Sources...
Final Project Milestone 3:
Module: Food
Filename: Food.h
Version 1.0
Author: Caroline Chen, StNo: 112747241, Email: cchen247@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason

-----------------------------------------------------------
Citation to indicate that you have done all the work yourself
-----------------------------------------------------------*/

#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include "Billable.h"
using namespace std;
namespace seneca {
    class Food : public Billable {
        bool m_ordered{};
        bool m_child{};
        char* m_customize{};
    public:
        Food();
        virtual ~Food();
        Food(const Food& src);
        Food& operator=(const Food& src);

        virtual ostream& print(ostream& ostr = cout)const;
        virtual bool order();
        virtual bool ordered()const;
        virtual ifstream& read(ifstream& file);

        virtual double price()const;

    };

}
#endif //FOOD_H
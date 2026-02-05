/* Citation and Sources...
Final Project Milestone 3:
Module: Billable
Filename: Billable.h
Version 1.0
Author: Caroline Chen, StNo: 112747241, Email: cchen247@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason

-----------------------------------------------------------
Citation to indicate that you have done all the work yourself
-----------------------------------------------------------*/

#ifndef BILLABLE_H
#define BILLABLE_H
#include <iostream>
using namespace std;
namespace seneca {
    class Billable {
        char* m_name{};
        double m_price{};
    protected:
        void price(double value);
        void name(const char* name);
    public:
        Billable();
        Billable(const Billable& src);
        Billable& operator=(const Billable& src);
        virtual ~Billable() = 0;

        virtual double price() const;

        virtual ostream& print(ostream& ostr = cout)const = 0;
        virtual bool order() = 0;
        virtual bool ordered()const = 0;
        virtual ifstream& read(ifstream& file) = 0;

        friend double operator+(double money, const Billable& B);
        friend double& operator+=(double& money, const Billable& B);

        const char* getName() const;

        friend ostream& operator<<(ostream& ostr, const Billable& B);
    };
}
#endif //BILLABLE_H
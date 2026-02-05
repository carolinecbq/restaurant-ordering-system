/* Citation and Sources...
Final Project Milestone 3:
Module: Food
Filename: Food.cpp
Version 1.0
Author: Caroline Chen, StNo: 112747241, Email: cchen247@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason

-----------------------------------------------------------
Citation to indicate that you have done all the work yourself
-----------------------------------------------------------*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Billable.h"
#include "Food.h"
using namespace std;
namespace seneca {
    Food::Food(){
        m_ordered = false;
        m_child = false;
        m_customize = nullptr;
    }

    Food::~Food() {
        delete[] m_customize;
        m_customize = nullptr;
    }

    Food::Food(const Food &src) : Billable(src) {
        m_ordered = src.m_ordered;
        m_child = src.m_child;

        if (src.m_customize != nullptr) {
            m_customize = new char[strlen(src.m_customize) + 1];

            for (size_t i = 0; i <= strlen(src.m_customize); i++) {
                m_customize[i] = src.m_customize[i];
            }
        } else {
            m_customize = nullptr;
        }
    }

    Food& Food::operator=(const Food &src) {
        Billable::operator=(src);
        if (this != &src) {
            m_ordered = src.m_ordered;
            m_child = src.m_child;

            delete[] m_customize;
            m_customize = nullptr;

            if (src.m_customize != nullptr) {
                m_customize = new char[strlen(src.m_customize) + 1];
                strcpy(m_customize, src.m_customize);
            } else {
                m_customize = nullptr;
            }
        }
        return *this;
    }

    ostream& Food::print(ostream& ostr) const {

        ostr << left << setw(28) << setfill('.') << getName();

        if (m_ordered == true && m_child == true) {
            ostr << "Child";
        } else if (m_ordered == true) {
            ostr << "Adult";
        } else {
            ostr << ".....";
        }

        ostr << right << setw(7) << setfill(' ') << fixed << setprecision(2) << price();

        if (m_customize != nullptr && &ostr == &cout) {
            ostr << " >> ";
            for (size_t i = 0; i < 30 && m_customize[i] != '\0'; i++) {
                ostr << m_customize[i];
            }
        }
        return ostr;
    }

    bool Food::order() {
        cout << "         Food Size Selection\n";
        cout << "          1- Adult\n";
        cout << "          2- Child\n";
        cout << "          0- Back\n";
        cout << "         > ";

        int selection{};
        cin >> selection;

        if (!cin.good()) {
            cin.clear();
            cin.ignore(10000, '\n');
            return false;
        }

        cin.ignore(10000, '\n');


        if (selection == 1) {
            m_ordered = true;
            m_child = false;
        }
        else if (selection == 2) {
            m_ordered = true;
            m_child = true;
        }
        else {
            m_ordered = false;
            delete[] m_customize;
            m_customize = nullptr;
            return false;
        }


        cout << "Special instructions\n";
        cout << "> ";

        char special[100]{};
        cin.getline(special, 100);

        delete[] m_customize;
        m_customize = nullptr;

        if (special[0] != '\0') {
            m_customize = new char[strlen(special) + 1];
            for (size_t i = 0; i <= strlen(special); i++) {
                m_customize[i] = special[i];
            }
        } else {
            m_customize = nullptr;
        }

        return true;
    }

    bool Food::ordered() const {
        return m_ordered;
    }

    ifstream &Food::read(ifstream &file) {
        if (!file.good()) {
            return file;
        }

        char foodName[100]{};
        double foodPrice{};

        file.getline(foodName, 100, ',');
        file >> foodPrice;
        file.ignore(10000, '\n');

        if (file.good()) {
            name(foodName);
            Billable::price(foodPrice);

            m_child = false;
            m_ordered = false;
            delete[] m_customize;
            m_customize = nullptr;
        }

        return file;
    }

    double Food::price() const {
        if (m_ordered == true && m_child == true) {
            return Billable::price() / 2;
        } else {
            return Billable::price();
        }
    }
}

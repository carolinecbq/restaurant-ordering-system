/* Citation and Sources...
Final Project Milestone 3:
Module: Drink
Filename: Drink.cpp
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
#include "Drink.h"
using namespace std;
namespace seneca {

    Drink::Drink() {
        m_size = '\0';
    }

    Drink::~Drink() {

    }

    ostream& Drink::print(ostream& ostr) const {
        const char* name = getName();

        ostr << left << setw(28) << setfill('.') << name;

        const char* size;

        switch (m_size) {
            case 'S':
                size = "SML..";
                break;
            case 'M':
                size = "MID..";
                break;
            case 'L':
                size = "LRG..";
                break;
            case 'X':
                size = "XLR..";
                break;
            default:
                size = ".....";
                break;
        }

        ostr << size;

        ostr << setfill(' ') << right << setw(7) << fixed << setprecision(2) << price() << setfill(' ');

        return ostr;
    }

    bool Drink::order() {
        cout << "         Drink Size Selection\n";
        cout << "          1- Small\n";
        cout << "          2- Medium\n";
        cout << "          3- Larg\n";
        cout << "          4- Extra Large\n";
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

        switch (selection) {
            case 1:
                m_size = 'S';
                return true;
                break;
            case 2:
                m_size = 'M';
                return true;
                break;
            case 3:
                m_size = 'L';
                return true;
                break;
            case 4:
                m_size = 'X';
                return true;
                break;
            default:
                m_size = '\0';
                return false;
        }
    }

    bool Drink::ordered() const {
        if (m_size == 'S' || m_size == 'M' || m_size == 'L' || m_size == 'X') {
            return true;
        } else {
            return false;
        }
    }

    ifstream &Drink::read(ifstream &file) {
        if (!file.good()) {
            return file;
        }

        char drinkName[100]{};
        double drinkPrice{};


        file.getline(drinkName, 100, ',');
        file >> drinkPrice;
        file.ignore(10000, '\n');

        if (file.good()) {
            name(drinkName);
            Billable::price(drinkPrice);
            m_size = '\0';
        }

        return file;
    }


    double Drink::price() const {
        double base = Billable::price();

        if (!ordered()) {
            return base;
        }
        if (m_size == 'L') return base;

        switch (m_size) {
            case 'S':
                return base * 0.50;
            case 'M':
                return base * 0.75;
            case 'X':
                return base * 1.50;
            default:
                return base;
        }

    }





}
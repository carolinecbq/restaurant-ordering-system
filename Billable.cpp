#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Billable.h"
using namespace std;
namespace seneca {

    void Billable::price(double value) {
        m_price = value;
    }

    void Billable::name(const char* name) {
        delete[] m_name;
        m_name = nullptr;

        if (name != nullptr && name[0] != '\0') {
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
        } else {
            m_name = nullptr;
        }
    }

    Billable::Billable() {
        m_name = nullptr;
        m_price = 0.0;
    }

    Billable::Billable(const Billable &src) {
        m_price = src.m_price;

        if (src.m_name != nullptr) {
            m_name = new char[strlen(src.m_name) + 1];
            strcpy(m_name, src.m_name);
        } else {
            m_name = nullptr;
        }
    }

    Billable& Billable::operator=(const Billable &src) {
        if (this != &src) {
            m_price = src.m_price;

            delete[] m_name;
            m_name = nullptr;

            if (src.m_name != nullptr) {
                m_name = new char[strlen(src.m_name) + 1];
                strcpy(m_name, src.m_name);
            } else {
                m_name = nullptr;
            }
        }
        return *this;
    }

    Billable::~Billable() {
        delete[] m_name;
        m_name = nullptr;
    }

    double Billable::price() const {
        return m_price;
    }

    double operator+(double money, const Billable& B) {
        return money + B.price();
    }

    double& operator+=(double& money, const Billable& B) {
        money += B.price();
        return money;
    }

    const char* Billable::getName() const {
        return m_name;
    }

    ostream& operator<<(ostream& ostr, const Billable& B) {
        ostr << B.getName();
        return ostr;
    }


}

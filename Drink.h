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

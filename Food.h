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

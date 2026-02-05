#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "constants.h"
using namespace std;
namespace seneca {

    class Menu;

    class MenuItem {
        char* m_content{};
        unsigned int indents{};
        unsigned int indentSize{};
        int rowNum{};

        MenuItem();
        MenuItem(const char* content, unsigned int indentations, unsigned int indent_size, int rowValue);
        ~MenuItem();

        ostream& display(ostream& ostr = cout) const;

        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;

        operator bool() const;

        friend class Menu;
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    class Menu {
        unsigned int indents{};
        unsigned int indentSize{};
        unsigned int itemCount{};

        MenuItem title;
        MenuItem exitOption;
        MenuItem entryPrompt;

        MenuItem* items[MaximumNumberOfMenuItems]{};

    public:
        Menu(const char* title, const char* exitOption = "Exit", unsigned int indents = 0, unsigned int indentSize = 3);
        ~Menu();

        Menu& operator<<(const char* m_content);

        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;

        size_t select() const;

        friend size_t operator<<(ostream& ostr, const Menu& m);

    };


}
#endif //MENU_H

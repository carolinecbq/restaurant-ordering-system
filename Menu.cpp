//
// Created by carol on 2025-10-30.
//
/* Citation and Sources...
Final Project Milestone 2:
Module: Menu
Filename: Menu.cpp
Version 1.0
Author: Caroline Chen, StNo: 112747241, Email: cchen247@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2025/10/31  Forgot to add seneca namespace brackets
2025/10/31  Fixed display function (replaced while loop statement contents with isspace function)
2025/11/09 Added Milestone 2 functions
-----------------------------------------------------------
Citation to indicate that you have done all the work yourself
-----------------------------------------------------------*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Menu.h"
#include <cstring>
#include "constants.h"
#include "Utils.h"
using namespace std;
namespace seneca {
    MenuItem::MenuItem() {
        m_content = nullptr;
        indents = 0;
        indentSize = 0;
        rowNum = 0;
    }

    MenuItem::MenuItem(const char* content, unsigned int indentations, unsigned int indent_size, int rowValue) {
        if (content == nullptr || content[0] == '\0' || indentations > 4 || indent_size > 4 || rowValue > static_cast<int>(MaximumNumberOfMenuItems)) {
            m_content = nullptr;
            indents = 0;
            indentSize = 0;
            rowNum = 0;
        } else {
            m_content = new char[strlen(content) + 1];
            strcpy(m_content, content);
            indents = indentations;
            indentSize = indent_size;
            rowNum = rowValue;
        }
    }

    MenuItem::~MenuItem() {
        delete[] m_content;
        m_content = nullptr;
    }

    ostream& seneca::MenuItem::display(ostream& ostr) const {
        if (m_content != nullptr && m_content[0] != '\0') {
            for (unsigned int i = 0; i < indents * indentSize; i++) {
                ostr << " ";
            }

            if (rowNum >= 0) {
                ostr << setw(2) << (rowNum) << "- ";
                ostr << setfill(' ');
            }

            const char* trimmed = m_content;
            while (isspace(static_cast<unsigned char>(*trimmed))) {
                trimmed++;
            }
            ostr << trimmed;
        }
        return ostr;
    }

    MenuItem::operator bool() const {
        return (m_content != nullptr && m_content[0] != '\0');
    }

    Menu::Menu(const char* m_title, const char* m_exitOption, unsigned int m_indents, unsigned int m_indentSize)
    : indents(m_indents),
    indentSize(m_indentSize),
    title(m_title, indents, indentSize, -1),
    exitOption(m_exitOption, indents, indentSize, 0),
    entryPrompt("> ", indents, indentSize, -1)

    {
        for (unsigned int i = 0; i < MaximumNumberOfMenuItems; i++) {
            items[i] = nullptr;
        }
    }

    Menu::~Menu() {
        for (unsigned int i = 0; i < MaximumNumberOfMenuItems; i++) {
            if (items[i] != nullptr) {
                delete items[i];
                items[i] = nullptr;
            }
        }
    }

    Menu& Menu::operator<<(const char* m_content) {
        if (itemCount < MaximumNumberOfMenuItems) {
            items[itemCount] = new MenuItem(m_content, indents, indentSize, itemCount + 1);
            itemCount++;
        }
        return *this;
    }

    size_t Menu::select() const {
        title.display();
        if (title.m_content != nullptr && title.m_content[0] != '\0') {
            cout << endl;
        }

        for (unsigned int i = 0; i < itemCount; i++) {
            if (items[i] != nullptr) {
                items[i]->display();
                cout << endl;
            }
        }

        exitOption.display();
        cout << endl;

        entryPrompt.display();

        size_t selection = Utils::getInt(0,itemCount);

        return selection;
    }

    size_t operator<<(ostream& ostr, const Menu& m) {
        if (&ostr == &cout) {
            return m.select();
        } else {
            return 0;
        }
    }


}
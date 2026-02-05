/***********************************************************************
// OOP244 Project, Utils Module
//
// File	Utils.h
// Version 0.1
// started by Fardad
// Description
// utility function to be used in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
/* Citation and Sources...
Final Project Milestone 2:
Module: Utils
Filename: Utils.cpp
Version 1.0
Author: Caroline Chen, StNo: 112747241, Email: cchen247@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2025/11/09 Added Milestone 2 functions
2025/11/29 Added <sstream> in order to utilize string data type and string stream to fix output issues with MS56
-----------------------------------------------------------
Citation to indicate that you have done all the work yourself
-----------------------------------------------------------*/
#include <iostream>
#include "Utils.h"
#include <limits>
#include <sstream>
using namespace std;
namespace seneca {
   Utils ut;

   char* Utils::alocpy(const char* src) const{
      char* des{};
      return alocpy(des, src);
   }

   char* Utils::alocpy(char*& des, const char* src)const {
      delete[] des;
      des = nullptr;
      if (src) {
         des = new char[strlen(src) + 1];
         strcpy(des, src);
      }
      return des;
   }
   char* Utils::strcpy(char* des, const char* src)const {
      int i;
      for (i = 0; src[i]; i++) des[i] = src[i];
      des[i] = char(0);
      return des;
   }
   int Utils::strlen(const char* str)const {
      int len;
      for (len = 0; str[len]; len++);
      return len;
   }

   bool Utils::isspace(char ch)const {
      return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
   }

   bool Utils::isspace(const char* cstring) const{
      while (cstring && isspace(*cstring)) {
         cstring++;
      }
      return cstring && *cstring == 0;
   }

   int Utils::getInt() {
      int value = 0;
      bool valid = false;
      string line;

      while (!valid) {
         getline(cin, line);
         if (line.empty()) {
            cout << "You must enter a value: ";
            continue;
         }

         stringstream sLine(line);

         if (!(sLine >> value)) {
            cout << "Invalid integer: ";
            continue;
         }

         char character;
         if (sLine >> character) {
            cout << "Only an integer please: ";
            continue;
         }

         valid = true;
      }
      return value;
   }



   int Utils::getInt(int min, int max) {
      int value = 0;
      bool valid = false;

      while (!valid) {
         value = getInt();

         if (value < min || value > max) {
            cout << "Invalid value: [" << min << "<= value <=" << max << "], try again: ";
         } else {
            valid = true;
         }
      }

      return value;
   }

   char* Utils::makeBillFileName(char* filename, size_t billNo)const {
      char billFileName[21] = "bill_";
      size_t temp = billNo;
      int cnt = 5;
      int length;
      // Calculate the number of digits
      do {
         cnt++;
         temp /= 10;
      } while (temp > 0);
      length = cnt;
      // Convert each digit to character from the end
      while (billNo > 0) {
         billFileName[--cnt] = (billNo % 10) + '0';
         billNo /= 10;
      }
      // Handle the case when billNo is 0
      if (billFileName[cnt - 1] == '\0') {
         billFileName[--cnt] = '0';
      }
      // Attach .txt to the end of the file name
      for (int i = 0; ".txt"[i]; i++) {
         billFileName[length++] = ".txt"[i];
      }
      billFileName[length] = '\0';
      strcpy(filename, billFileName);
      return filename;
   }

}
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
Filename: Utils.h
Version 1.0
Author: Caroline Chen, StNo: 112747241, Email: cchen247@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2025/11/09 Added Milestone 2 functions
-----------------------------------------------------------
Citation to indicate that you have done all the work yourself
-----------------------------------------------------------*/
#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H
namespace seneca {
   class Utils {
   public:
      char* alocpy(const char* src)const;
      char* alocpy(char*& des, const char* src)const;
      char* strcpy(char* des, const char* src)const;
      int strlen(const char* str)const;
      bool isspace(char ch)const;
      bool isspace(const char* cstring)const;
       static int getInt();
       static int getInt(int min, int max);
       const char* getName() const;
       char* makeBillFileName(char* filename, size_t billNo) const;
   };
   extern Utils ut;   // makes the ut object available where Utils.h is included
                     // to call a Utils function call it as follows
                     // ut.strcpy(des, src);
}

#endif // !SENECA_UTILS_H

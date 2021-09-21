/*
 * COMP15 Homework Proj1Phase2, Spring 2020
 * RPNCalc.h
 * By: Bob Ranalli
 * Completed: October 24, 2020
 *
 * [BREIF_FILE_DESCRIPTION]
 * Purpose: The header file for RPNCalc.cpp which contains all includes and
 *          function declarations
 */


#ifndef _RPNCALC_H_
#define _RPNCALC_H_

#include <iostream>
#include <fstream>
#include <sstream>

#include "DatumStack.h"
#include "cstdio" //for got int func

class RPNCalc {

    public:
        //constructor
        RPNCalc();

        //destructor
        ~RPNCalc();

        //method
        void run(); //do



    private:

        //variables
        DatumStack stack;
        string parseRString(istream &input);

        //main commands
        bool checkCommand(string command, istream &input);

        void print(); //done
        void drop(); //done
        void dup(); //done
        void swap(); //done
        void execNot(); //done
        void equal(); //done
        void execOperation(string input); //done-ish
        void execIf();
        bool file();
        bool exec();

        //helper
        bool got_int(string s, int *resultp); //done
        void pushString(string input); //done
        bool isOperation(string input); //done
        bool isRString(string input);

};

#endif

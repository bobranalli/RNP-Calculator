/*
 * COMP15 Homework Proj1Phase1, Fall 2020
 * DatumStack.h
 * By: Bob Ranalli
 * Completed: October 12, 2020
 *
 * [BREIF_FILE_DESCRIPTION]
 * Purpose: The purpose of this file is to declare all functions for the
 *          DatumStack class and contains all headers that would otherwise be
 *          in the DatumStack.cpp
 */


#ifndef _DATUMSTACK_H_
#define _DATUMSTACK_H_

#include <vector>
#include <iostream>
#include "Datum.h"

using namespace std;

class DatumStack {
    public:
        //constructors
        DatumStack();
        DatumStack(Datum data[], int size);

        //methods
        bool isEmpty();
        int size();
        Datum top();

        void clear();
        void pop();
        void push(Datum elem);


        //destructor - not necessary (no extra allocated memory)


    private:
        vector <Datum> stack;

};

#endif

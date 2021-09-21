/*
 * COMP15 Homework Proj1Phase1, Fall 2020
 * testDatumStack.cpp
 * By: Bob Ranalli
 * Completed: October 12, 2020
 *
 * Purpose: Tests Datumstack.cpp and makes sure everything in the cpp was
 *          implemented correctly
 */

#include <iostream>
#include "DatumStack.h"
#include "Datum.h"
using namespace std;

void testingConstructorOne();
void testingConstructorTwo();

int main(){

    testingConstructorOne();
    testingConstructorTwo();

    return 0;
}

/*
 *  Name:      testingConstructorOne
 *  Purpose:   tests the first constructor and makes sure all functions run on
               it work properly/as expected
 *  Arguments: None
 *  Returns:   void
 */
void testingConstructorOne() {
    //Default Constructor
    cout << "----------------------------- " << endl;
    cout << "|TESTING DEFAULT CONSTRUCTOR |" << endl;
    cout <<  "---------------------------- " << endl;
    DatumStack ds1;

    cout << "ds1: Empty: " << ds1.isEmpty() << endl;              //true
    // cout << ds1.top().toString() << endl;      //empty <-should throw error

    ds1.clear();
    cout << "ds1: Empty (after clear): " << ds1.isEmpty() << endl;
    cout << "ds1: Size: " << ds1.size()<< endl;
    //ds1.pop() //empty <--- will throw runtime error

    Datum test_push(4);
    Datum test_push2("test");
    Datum test_push3(true);

    ds1.push(test_push);
    cout << "Top: " << ds1.top().toString() << endl;

    ds1.push(test_push2);
    cout << "Top: " << ds1.top().toString() << endl;

    ds1.push(test_push3);
    cout << "Top: " << ds1.top().toString() << endl;

    cout << "isEmpty before clear" << ds1.isEmpty() << endl;
    cout << "Size before clear: " << ds1.size() << endl;
    ds1.clear();
    cout << "isEmpty after clear: " << ds1.isEmpty() << endl;
    cout << "Size after clear: " << ds1.size() << endl;

}

/*
 *  Name:      testingConstructorOne
 *  Purpose:   tests the second constructor and makes sure all functions run on
               it work properly/as expected
 *  Arguments: None
 *  Returns:   void
 */
void testingConstructorTwo() {

    /* Testing Non-defult constructor */
    Datum d1(1);            //testing int Datum constructor
    Datum d2(true);         //testing bool Datum constructor
    Datum d3(false);        //testing bool Datum constructor
    Datum d4("-Datum 4-");  //testing string Datum constructor
    Datum d5(d1);          //testing copy Datum constructor

    cout << "------------------------- " << endl;
    cout << "|TESTING 2ND CONSTRUCTOR |" << endl;
    cout <<  "------------------------ " << endl;

    Datum ds_arr[] = {d1, d2, d3, d4, d5};
    int ds_arr_size = 5;
    DatumStack ds2(ds_arr, ds_arr_size);

    cout << "ds2: Size: " << ds2.size()<< endl;
    cout << "ds2: Is Empty: " << ds2.isEmpty()<< endl;
    cout << "Top: " << ds2.top().toString() << endl;
    ds2.pop();
    cout << "Top after pop (should get element 4): "
         << ds2.top().toString() << endl;

    Datum d6(2);
    Datum d7(false);
    Datum d8("Third pushed");
    ds2.push(d6);
    cout << "Top (after new int push): " << ds2.top().toString() << endl;

    ds2.push(d7);
    cout << "Top (after new bool push): " << ds2.top().toString() << endl;

    ds2.push(d8);
    cout << "Top (after new string push): " << ds2.top().toString() << endl;

    cout << "isEmpty before clear: " << ds2.isEmpty() << endl;
    cout << "Size before clear: " << ds2.size() << endl;
    ds2.clear();
    cout << "isEmpty after clear: " << ds2.isEmpty() << endl;
    cout << "Size after clear: " << ds2.size() << endl;
    //ds2.pop() //empty <--- will throw runtime error

}

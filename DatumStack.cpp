/*
 * COMP15 Homework Proj1Phase1, Fall 2020
 * DatumStack.cpp
 * By: Bob Ranalli
 * Completed: October 12, 2020
 *
 * Purpose: The purpuse of this file is to implement the DatumStack class.
 *          This file is where all functionality for the DatumStack can be
 *          seen and created
 */
#include "DatumStack.h"
using namespace std;

/*
 *  Name:      DatumStack
 *  Purpose:   Default construcor which has no requirement in this case
 *  Arguments: None
 *  Returns:   None
 */
DatumStack::DatumStack(){} //nothing to fill / populate

/*
 *  Name:      DatumStack
 *  Purpose:   Creates an instance of a DatumStack which populates through an
               inputted array. This is another form of a constructor.
 *  Arguments: An array of datums and the size of said array
 *  Returns:   DatumStack
 */
DatumStack::DatumStack(Datum data[], int size){
    for (int i = 0; i < size; i++) {
        push(data[i]);
    }
}

/*
 *  Name:      clear
 *  Purpose:   Removes everything from the DatumStack, leaving it blank
 *  Arguments: None
 *  Returns:   void
 */
void DatumStack::clear(){
    stack.clear();
}

/*
 *  Name:      size
 *  Purpose:   returns the size of the array, aka the # of Datums on the stack
 *  Arguments: None
 *  Returns:   the size as an integer
 */
int DatumStack::size(){
    return stack.size();
}

/*
 *  Name:      isEmpty
 *  Purpose:   The purpose is to assess if the number of Datums on the stack
               is 0 or not.
 *  Arguments: None
 *  Returns:   bool - true if it is empty, false if it is populated
 */
bool DatumStack::isEmpty(){
    return (size() == 0);
}

/*
 *  Name:      top
 *  Purpose:   Returns the top element from the DatumStack
 *  Arguments: None
 *  Returns:   Returns the top datam (from the back)
 */
Datum DatumStack::top(){
    if(isEmpty()){
        throw runtime_error("empty_stack");
    }
    return stack.back();
}

/*
 *  Name:      pop
 *  Purpose:   removes the top (or back) element from the datumstack
 *  Arguments: None
 *  Returns:   void
 */
void DatumStack::pop(){
    if(isEmpty()){
        throw runtime_error("empty_stack");
    }
    stack.pop_back();
}

/*
 *  Name:      push
 *  Purpose:   Adds another datum to the stack of datums
 *  Arguments: Takes in the desired datum element
 *  Returns:   void
 */
void DatumStack::push(Datum elem){
    stack.push_back(elem);
}

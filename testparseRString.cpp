/*
 * COMP15 Homework Proj1Phase0, Fall 2020
 * testparseRString.cpp
 * By: Bob Ranalli
 * Completed: October 12, 2020
 *
 * Purpose: The purpose of this file is to read in an input file that tests
 *          the parseRString function.
 */


#include "parser.cpp"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]){

    ifstream input;
    string output;

    if(argc == 2){
        input.open(argv[1]);
    }
    string user_input;
    while(not input.eof()){
        input >> user_input;
        if(user_input == "{"){
            output = parseRString(input);
        }
    }
    cout << output << endl;
}

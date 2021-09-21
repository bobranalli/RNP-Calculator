/*
 * COMP15 Homework Proj1Phase1, Fall 2020
 * parser.cpp
 * By: Bob Ranalli
 * Completed: October 12, 2020
 *
 * Purpose: The purpose od this file is to build out the parseRString function
 *          and to test that function through main.
 */

#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

string parseRString(istream &input);

int main(int argc, char *argv[]){
    if(argc == 1){
        throw runtime_error("Need input file");
    }
    ifstream input;
    input.open(argv[1]);

    string output;
    string user_input;

    while(not input.eof()){

        input >> user_input;

        if(user_input == "{"){
            cout << parseRString(input) << endl;
            break;
        }
    }

    input.close();
    return 0;
}

/*
 *  Name:      parseRString
 *  Purpose:   returns a full rstring which has been condensed/taken in from
               a file or from user input
 *  Arguments: address to the istream
 *  Returns:   a string formatted as an rstring
 */
string parseRString(istream &input){
    string rstring = "{";
    string temp = "";
    int counter = 1;

    while(counter != 0){
        input >> temp;
        if(temp == "{"){
            counter++;
        }
        else if(temp == "}"){
            counter--;
        }
        rstring.append(" " + temp);
    }
    return rstring;
}

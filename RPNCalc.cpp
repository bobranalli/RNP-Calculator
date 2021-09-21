/*
 * COMP15 Homework Proj1Phase2, Fall 2020
 * RNPCalc.cpp
 * By: Bob Ranalli
 * Completed: October 24, 2020
 *
 * Purpose: The main purpose of this file is to implement the functionality for
 *          for the clients calculator. If there client were to ever want to
 *          see how the calculator was build/how it operated, this would be the
 *          file to check.
 */

#include "RPNCalc.h"
using namespace std;

/*
 *  Name:      RPNCalc
 *  Purpose:   default constructor to create an instance of RNPcalc
 *  Arguments: None
 *  Returns:   None
 */
RPNCalc::RPNCalc(){}

/*
 *  Name:      ~RPNCalc
 *  Purpose:   the default constructor for the RPNCalc class
 *  Arguments: None
 *  Returns:   None
 */
RPNCalc::~RPNCalc(){}

/*
 *  Name:      run
 *  Purpose:   the main interface that runs the RPNCalc based off the user
               input
 *  Arguments: None
 *  Returns:   void
 */
void RPNCalc::run(){
    string command;
    cin >> command;

    bool running = true;
    while(not cin.eof()){
        running = checkCommand(command, cin);
        if (not running) break;
        cin >> command;
    }

    cerr << "Thank you for using CalcYouLater." << endl;
}

/*
 *  Name:      checkCommand
 *  Purpose:   calls the proper function based off what the user inputs
 *  Arguments: a string - command - which is the user of file input
 *  Returns:   None
 */
bool RPNCalc::checkCommand(string command, istream &input) {
    int place_holder;
    if (command == "quit") return false;
    else if(command == "print") print();
    else if(command == "clear") stack.clear();
    else if(command == "drop")  drop();
    else if(command == "dup")   dup();
    else if(command == "swap")  swap();
    else if(command == "not")   execNot();
    else if(command == "==")    equal();
    else if(isOperation(command)) execOperation(command);
    else if(command == "#t" or command == "#f") pushString(command);
    else if(got_int(command, &place_holder)) pushString(command);
    else if(command == "if")    execIf();
    else if(command == "file") {
        if (not file()) return false;
    }
    else if(command == "exec") {
        if (not exec()) return false;
    }
    else if(command == "{") pushString(parseRString(input));

    else cerr << command + ": unimplemented" << endl;

    return true;
}

/*
 *  Name:      parseRString
 *  Purpose:   returns a full rstring which has been condensed/taken in from
               a file or from user input
 *  Arguments: address to the istream
 *  Returns:   a string formatted as an rstring
 */
string RPNCalc::parseRString(istream &input){
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

/*
 *  Name:      print
 *  Purpose:   prints the top of the stack as a string
 *  Arguments: none
 *  Returns:   void
 */
void RPNCalc::print(){
    if(stack.isEmpty()){
        cerr << "Error: empty_stack" << endl;
    }
    else{
        cout << stack.top().toString() << endl;
    }
}

/*
 *  Name:      drop
 *  Purpose:   pops or gets rid of the top datum on the stack
 *  Arguments: none
 *  Returns:   void
 */
void RPNCalc::drop(){
    if(stack.isEmpty()){
        cerr << "Error: empty_stack" << endl;
    }
    else{
        stack.pop();
    }
}

/*
 *  Name:      dup
 *  Purpose:   makes a copy of the top of the stack and adds that copy to the
               top of the stack
 *  Arguments: none
 *  Returns:   void
 */
void RPNCalc::dup(){
    if(stack.isEmpty()){
        cerr << "Error: empty_stack" << endl;
    }
    else{
        Datum temp(stack.top());
        stack.push(temp);
    }
}

/*
 *  Name:      swap
 *  Purpose:   switches the order of the top two datums on the stack
 *  Arguments: none
 *  Returns:   void
 */
void RPNCalc::swap(){
    if(stack.size() <= 1){
        cerr << "Error: empty_stack" << endl;
        stack.clear();
    }
    else{
        Datum temp1(stack.top());
        stack.pop();
        Datum temp2(stack.top());
        stack.pop();
        stack.push(temp1);
        stack.push(temp2);
    }
}

/*
 *  Name:      execNot
 *  Purpose:   takes the top bool on the stack and switches its value
 *  Arguments: none
 *  Returns:   void
 */
void RPNCalc::execNot(){
    if(stack.isEmpty()){
        cerr << "Error: empty_stack" << endl;
    } else if(stack.top().toString() != "#t" or stack.top().toString() != "#f"){
        cerr << "Error: datum_not_bool" << endl;
        stack.pop();
    }
    else{

        if(stack.top().toString() == "#t"){
            stack.pop();
            Datum temp("#f");
            stack.push(temp);
        }
        else if (stack.top().toString() == "#f"){
            stack.pop();
            Datum temp("#t");
            stack.push(temp);
        }
    }
}

/*
 *  Name:      equal
 *  Purpose:   comparess the top two items on the stack to tell whether they
               are the same or not (true if same, false if not)
 *  Arguments: none
 *  Returns:   void
 */
void RPNCalc::equal(){
    if(stack.size() <= 1){
        cerr << "Error: empty_stack" << endl;
        stack.clear();
    }
    else{
        Datum temp1(stack.top());
        stack.pop();
        Datum temp2(stack.top());
        stack.pop();

        if(temp1.toString() == temp2.toString()){
            Datum temp3("#t");
            stack.push(temp3);
        } else{
            Datum temp3("#f");
            stack.push(temp3);
        }
    }
}

/*
 *  Name:      pushString
 *  Purpose:   adds a new inputted string to the stack
 *  Arguments: a string - input - inputted from the user or file
 *  Returns:   void
 */
void RPNCalc::pushString(string input){
    Datum temp(input);
    stack.push(temp);
}

/*
 * ------------ WRITTEN BY Aubrey Anderson ------------
 *  Name:      got_into
 *  Purpose:   to convert a string to an int and place that int in the
               proper address
 *  Arguments: a string, s and a pointer to an int, resultp
 *  Returns:   bool
 */
bool RPNCalc::got_int(string s, int *resultp){
        /* Holds the first non-whitespace character after the integer */
        char extra;

        return sscanf(s.c_str(), " %d %c", resultp, &extra) == 1;
}

/*
 *  Name:      isOperation
 *  Purpose:   determines if the inputted string is an valid operation
 *  Arguments: an inputted string, input
 *  Returns:   bool
 */
bool RPNCalc::isOperation(string input){
    string arr[] = {"+", "-", "*", "/", "mod", "<", ">", "<=", ">="};
    for (int i = 0; i < 9; i++) {
        if(input == arr[i]){
            return true;
        }
    }
    return false;
}

/*
 *  Name:      execOperation
 *  Purpose:   executes a math operation based off the input and adds the
               result to the top of the stack
 *  Arguments: an inpuuted string, input
 *  Returns:   void
 */
void RPNCalc::execOperation(string input){
    int temp1_int, temp2_int;

    /* Getting first (top) item in stack --> temp1 */
    if (stack.isEmpty()) {
        cerr << "Error: empty_stack" << endl;
        return;
    }

    Datum temp1(stack.top());
    stack.pop();

    if(not got_int(temp1.toString(), &temp1_int)){
        cerr << "Error: datum_not_int" << endl;
        return;
    }
    if((input == "/" or input == "mod") and temp1_int == 0) {
        cerr << "Error: division by 0." << endl;
        return;
    }

    /*Getting second item in stack --> temp2 */
    if (stack.isEmpty()) {
        cerr << "Error: empty_stack" << endl;
        return;
    }

    Datum temp2(stack.top());
    stack.pop();

    if(not got_int(temp2.toString(), &temp2_int)){
        cerr << "Error: datum_not_int" << endl;
        return;
    }

    int result_int = 0;
    bool result_bool = false;
    bool return_int = false;

    if(input == "+") {
        result_int = temp2_int + temp1_int;
        return_int = true;
    }
    else if(input == "-") {
        result_int = temp2_int - temp1_int;
        return_int = true;
    }
    else if(input == "*") {
        result_int = temp2_int * temp1_int;
        return_int = true;
    }
    else if(input == "/") {
        result_int = temp2_int / temp1_int;
        return_int = true;
    }
    else if(input == "mod") {
        result_int = temp2_int % temp1_int;
        return_int = true;
    }
    else if(input == "<") result_bool = temp2_int < temp1_int;
    else if(input == ">") result_bool = temp2_int > temp1_int;
    else if(input == "<=") result_bool = temp2_int <= temp1_int;
    else if(input == ">=") result_bool = temp2_int >= temp1_int;

    if (return_int) {
        Datum temp3(result_int);
        stack.push(temp3);
    } else {
        Datum temp3(result_bool);
        stack.push(temp3);
    }

}

/*
 *  Name:      execIf
 *  Purpose:   runs an if statement based off the top three elements on the
               stack
 *  Arguments: none
 *  Returns:   void
 */
void RPNCalc::execIf(){

    /*Getting first item  (false case) in stack --> temp1 */
    if (stack.isEmpty()) {
        cerr << "Error: empty_stack" << endl;
        return;
    }

    Datum temp1(stack.top());
    stack.pop();

    /*Getting second item (true case) in stack --> temp2 */
    if (stack.isEmpty()) {
        cerr << "Error: empty_stack" << endl;
        return;
    }
    Datum temp2(stack.top());
    stack.pop();

    /*Getting third item (condition) in stack --> temp3 */
    if (stack.isEmpty()) {
        cerr << "Error: empty_stack" << endl;
        return;
    }
    Datum temp3(stack.top());
    stack.pop();

    //checking if temp1 or temp2 is an r-string
    /* if (temp1.toString().substr(0,1) != "{") */
    if(not isRString(temp1.toString()) or not isRString(temp2.toString())) {
        cerr << "Error: expected rstring in if branch" << endl;
        return;
    }

    //checknig if temp3 is a bool
    if(temp3.toString() != "#t" and temp3.toString() != "#f") {
        cerr << "Error: expected boolean in if test" << endl;
        return;
    }

    if(temp3.toString() == "#t"){
        stack.push(temp2);
    }else{
        stack.push(temp1);
    }
    exec();

/*
if (condition) {
    do True case
} else {
    do False case
}
 ____________
| False case |
| True case  |
| condition  |
|____________|
*/

}

/*
 *  Name:      exec
 *  Purpose:   runs operations and executions based off an rstring on the stack
 *  Arguments: none
 *  Returns:   bool
 */
bool RPNCalc::exec(){
    //make sure stack isnt empty
    if (stack.isEmpty()) {
        cerr << "Error: empty_stack" << endl;
        return true; //retrn true to escape function without stopping program
    }

    Datum temp(stack.top());
    stack.pop();

    //make sure top of stack is rstring
    if(not isRString(temp.toString())) {
        cerr << "Error: cannot execute non rstring" << endl;
        return true;
    }

    //check for empty rstring (5 is minimum length for populated rstring)
    if (temp.toString().length() < 5) {
        return true;
    }

    //get string of commands from rstring (de-rstring top of stack)
    string command_str = temp.toString().substr(2,temp.toString().length() - 4);
    string command;

    //open string into a istringstream
    istringstream string_stream(command_str); //if error do thing below
    //string_stream.str(command_str);
    string_stream >> command;

    //running a loop
    bool running = true;
    while(not string_stream.fail()) {
        running = checkCommand(command, string_stream);
        if (not running) return false;

        string_stream >> command;
    }

    return true;

}

/*
 *  Name:      file
 *  Purpose:   reads in a file from the stack and runs the file through the RPN
               calc
 *  Arguments: None
 *  Returns:   bool
 */
bool RPNCalc::file(){
    //make sure stack isnt empty
    if (stack.isEmpty()) {
        cerr << "Error: empty_stack" << endl;
        return true; //retrn true to escape function without stopping program
    }

    Datum temp(stack.top());
    stack.pop();

    //make sure top of stack is rstring
    if(not isRString(temp.toString())) {
        cerr << "Error: file operand not rstring" << endl;
        return true;
    }

    //get file name from rstring (de-rstring top of stack)
    string filename = temp.toString().substr(2, temp.toString().length() - 4);
    string command;

    //open file into a ifstream
    ifstream file_stream(filename); //if error do thing below
    //file_stream.open(filename);

    //check if file is open
    if (not file_stream.is_open()) {
        cerr << "Unable to read " << filename << endl;
        return true;
    }

    file_stream >> command;

    //running a loop
    bool running = true;
    while(running and not file_stream.eof()) {
        running = checkCommand(command, file_stream);
        if (not running) return false;
        file_stream >> command;
    }

    return true;
}

bool RPNCalc::isRString(string input){
    if (input.substr(0,1) == "{" and input.substr(input.length()-1,1) == "}"){
        return true;
    }
    return false;
}

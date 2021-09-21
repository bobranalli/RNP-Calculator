 -----------
|Compile/run|
 -----------
    Main DatumStack testing file
        -Compile using
            make testDatumStack
        -Run executable with
            ./testDatumStack

    Main DatumStack testing file
        -Compile using
            make testParser
        -Run executable with
            ./testParser [filename]


 ---------------
|Program Purpose|
 ---------------

PHASE 1:
    The purpose of this program is to develop the basis for the CalcYouLater
    and to deliver a functioning stack and parser function which turns a string
    into an rstring. This assignment was also an exercise in time management
    by having a meeting with a TA to both plan the implementation and the
    timeline for the larger project at hand.

PHASE 2:
    The purpose of phase2 and the program in general was to create a
    calculator from scratch and to use the stack data structor achieve it. The
    outcome was successful as the RPNCalc class can handle any of the desired
    inputs that a potential client would want to use and can read in and
    operate on files or from direct input from the client.



 ----------------
|Acknowledgements|
 ----------------

    PHASE 1:
        Mark Sheldon's lectures on stacks

    PHASE 2:
        Mark Sheldon's lectures on stacks

        Aubrey Anderson's got_int function

 -----
|Files|
 -----

Phase 1:

    DatumStack.cpp
        The purpose of this is to implement and build the functionality for
        the DatumStack class. This would allow a client to manipulate, change,
        and organize a series of datums in a succinct way.

    testDatumStack.cpp
        The purpose of this is to test the DatumStack.cpp and show a client
        the potential functionality of the DatumStack

    parser.cpp
        The purpose of this is to turn a string or series of strings from an
        input file (or user input) into an rstring with the format { content }

    testparseRString.txt
        The purpose of this is to provide the content to test parser.cpp

    Makefile
        The purpose of this is to simplify the run commands and allow the
        client or user to run the program with simple commands like
        testDatumStack and testParser.


PHASE 2:

    RPNCalc.cpp
        The main implementation of the RPNCalc program which builds out the
        functionality for the calculator and allows the client to use a
        calculator with a wide variety of options

    RPNCalc.h
        The main purpose of this file is to contain all function declarations
        and the proper includes for the RPNCalc.cpp

    testRPNCalc.cpp
        The main purpose of this file is to test the RPNCalc class using both
        the created and given files

    test_if.cyl
        a file that tests both if and exec

    test_operations.cyl
        a file that tests each of the operations in sequence

    test_edgecases.cyl
        a file that tests the edge cases and expected error statements


 ---------------
|Data Structures|
 ---------------
    Stack
        The stack is my main basis for implementation for DatumStack and the
        beginings of the RPN calculator. The stack works on the basis of
        "first in last out" which differs from the queue from last week which
        is "first in first out." That concept of "FILO" makes the stack a
        great form for organization as every time something new gets added, it
        immediately becomes the new focus for operations and and tasks.
        For the RNP CalcYouLater, we need to operate on the most recent/newest
        input from the user, which is exactly how a stack prioritizes data.
        To give an example of how a stack would handle a new input, let's say
        a user inputs 4 6 6 / +. The first thing it would do is create a new
        instance of a stack storing |4|5|6|. Then take the result of the top 2
        integers (6 and 6) and divide them, then add those to another stance
        instance with the remaining integer (4): |4|1|. Then the + would be
        applied to the remaining stack, which would result in a stack of just
        |5|.

    Vector
        To create the stack above another structure or "tool" needed to be
        chosen. This could have been arrays, linked lists, vectors (what I
        chose) and probably many more. I chose vectors because of the well
        understood and broad functionality that lines up well with the
        desired functionality for DatumStack. Because of the similarities
        between built-in functionality for vectors and the desired
        functionality for Datumstack, this led to very short and simple
        functions in the DatumStack class which had less variance than trying
        to develop the stack using linked lists or a different structure
        with less ubiquitous support. Another important factor for
        choosing vectors over linked list was because of valgrind and memory
        issues. Given that there is no pre-allocated memory for a vector
        there is no need to manually clear memory and storage at the end like
        you would with a linked list which stores memory for every pointer
        used.


 -------
|Testing|
 -------
PHASE 1:

    My testing was done in two different phases since this assignment called
    for two functions/classes that didn't have much associated with one
    another. These two parts were DatumStack and parser.

    For Datumstack, I tested as I implemented each new function. First, it was
    a matter of testing the default constructor and making sure that everything
    was linking properly (answering the questions of "did I include the right
    file headers?" and "Do I have access to Datum.h even though it is only
    through Halligans server and not on Atom.") These questions were answered
    when the default constructor (although blank) was created without problems
    with access to any h files or other needed libraries. Once that was settled
    it was on to testing each function after creating it to make sure it
    worked on its own. Once each function (like top(), size(), isEmpty()) was
    built then tested on it's own, I created a testing file that broke the
    testing into two seperate sections - the default constructor and the
    constructor populated by a datum array. I then combined a series of tests
    for each constructor using an assortment of the functions from
    Datumstack.cpp.

    For parser.cpp, the testing was more difficult to start since I wanted to
    read in a file to make sure it was working properly. This required making
    a file read in function in main to then feed a file through to test the
    parser function. This process itself created some problems for me with
    remembering how to properly structor reading in a file. Once that was
    finished however, I created a test file called testparseRString.txt
    that was a mix of letters, numbers, operators, and opne/closed brackets.
    After running the file through and testing it with simplier files, my
    parser was printing an extra "}" at the end its rstring. I tried multiple
    different methods to get rid of this, setting a temp variable = "" for
    instance right before the parser finished to get rid of the bracket, but
    that then (as one might expect) printed an extra space at the end of the
    string. I then tried reducing the size of the entire string by 1, to chop
    off that extra "}" but that did not work very well either. I then figured
    out it was a logic error having to do with when I reduced my counter. Once
    I rearranged my if/else functions, the problem was solved and the bracket
    was no longer being printed at the end.

PHASE 2:
    The testing for RPNCalc was contingent on having a properly functioning
    file() function. I wanted to test all my functions through created files
    and needed to have file() running properly to do so. To execute this
    however, I needed to build out and test each of the functions used in file
    first. So, I first build out a simple run() function and used a simple set
    of input commands to make sure run was implemented. Then I created
    checkCommand() since file() needed checkCommand() to operate. Once that was
    all set up, it was a matter of creating testing files to then test each
    function directly after implementation. For instance, when wanting to test
    execOperation, I created a file which would run through a series of numbers
    and call each of the desired operations or evaluators, then I ran the
    file by calling "file" in the RPNCalc program and made sure each of the
    operations produced the expected output. Using file() for testing greatly
    shortened the testing process since it allowed for a testing file to be
    created then ran without having to type in commands every time I wanted to
    test a new function. Each function was tested directly after implementation
    and by using a testing file.

 -----
|Notes|
 -----
PHASE 1:
    My parser function needs a test file so when you run the make command and
    then try the executable, you'll need to input a file with it.

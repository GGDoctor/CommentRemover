// Ignore comments
// The objective of this project is to take the first step torwards building an interpreter, ignoring comments
// This project is developed by the following students:
// Haley Joerger
// Adam Lyday
// Jacob Franco
// Zach Gassner


#include <iostream>
#include <fstream> //Including fstream and string allow us to read in the input file
#include <string>
using namespace std;

//Create the suggested State
enum State {
    ANYTHING, 
    SLASH,
    ASTERICK,
    SINGLE_LINE_COMMENT, // A comment pertaining '//'
    MULTI_LINE_COMMENT, // A comment pertaining '/* bla */
    SINGLE_QUOTE,
    DOUBLE_QUOTE
};


int main(int argc, char *argv[]) {

    if (argc != 2 ) {
        cerr << "Error! There is not a correct number of command line arguments.\n";
        return 1;
    }
    string filename = argv[1];
    ifstream inputFile(filename.c_str());

    if (!inputFile) {
        std::cerr << "Error. Unable to open the file :( \n"; // Error out if we are unable to open up the file
        return 1;
    }

/*  ************************************************** */

            /* All code in this area needs work */

    State state = ANYTHING;
    string result = "";
    char currentChar;

    while (inputFile.get(currentChar)) {

        switch (state) {

            //Handle Anything 
            case ANYTHING:
                if (currentChar == '/') {
                    state = SLASH;
                    char nextChar = inputFile.peek();
                    result += (nextChar == '/' || nextChar == '*') ? ' ' : currentChar;
                } else if (currentChar == '"') {
                    state = DOUBLE_QUOTE;
                    result += currentChar;
                } else if (currentChar == '\'') {
                    state = SINGLE_QUOTE;
                    result += currentChar;
                } else {
                    result += currentChar;
                }
                break;
            
            //Handle Slash
            case SLASH:
                if (currentChar == '/') {
                    state = SINGLE_LINE_COMMENT;
                    result += ' ';
                } else if (currentChar == '*') {
                    state = MULTI_LINE_COMMENT;
                    result += ' ';
                } else {
                    state = ANYTHING;
                    result += currentChar;
                }
                break;

            //Handle Star - need to add code for this
            case ASTERICK:
                if (currentChar == '/') {
                    state = ANYTHING;
                } else if (currentChar != '*') {
                    state = MULTI_LINE_COMMENT;
                } 
                result += ' ';
                break;

            //Handle single line - need to add code for this
            case SINGLE_LINE_COMMENT:
                if (currentChar == '\n') {
                    state = ANYTHING;
                    result += currentChar;
                } else {
                    result += ' ';
                }
                break;

            //Handle Multiple Line - need to add code for this
            case MULTI_LINE_COMMENT:
                if (currentChar == '*') {
                    state = ASTERICK;
                    result += ' ';
                } else {
                    result += currentChar == '\n' ? '\n' : ' ';
                } 
                break;

            // needs code to handle escape characters
            case SINGLE_QUOTE: 
                if (currentChar == '\'') {
                    state = ANYTHING;
                }
                result += currentChar;
                break;

            // needs code to handle escape characters
            case DOUBLE_QUOTE:
                if (currentChar == '"') {
                    state = ANYTHING;
                } 
                result += currentChar;
                break;
        }
    }
        
    inputFile.close(); // Close the file when we are done working.
    std::cout << result;

    return 0;
}


//I downloaded the file and put them into the project
//then did a g++ -o IgnoreComments IgnoreComments.cpp
//then did ./IgnoreComments programming_assignment_1-test_file_2.c
//this worked.
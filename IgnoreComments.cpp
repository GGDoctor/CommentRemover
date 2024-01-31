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

    string line;


/*  ************************************************** */

            /* All code in this area needs work */

    State state = ANYTHING;

    //implement the while loop
    while (getline(inputFile, line)) {
        string result = "";

        for (char currentChar : line) { //iterate through each character is line string, one character at a time
            switch (state) {

            //Handle Anything 
            case ANYTHING:
                if (currentChar == '/') {
                    state = SLASH;
                } else {
                    result += currentChar;
                }
                break;
            
            //Handle Slash
            case SLASH:
                if (currentChar == '/') {
                    state = SINGLE_LINE_COMMENT;
                } else if (currentChar == '*') {
                    state = MULTI_LINE_COMMENT;
                } else {
                    
                    //need to add code for this

                }
                break;

            //Handle Star - need to add code for this




            //Handle single line - need to add code for this
            



            //Handle Multiple Line - need to add code for this



                
        }
  
    }

/*  ************************************************** */



    }
    inputFile.close(); // Close the file when we are done working.
    return 0;
}


//I downloaded the file and put them into the project
//then did a g++ -o IgnoreComments IgnoreComments.cpp
//then did ./IgnoreComments programming_assignment_1-test_file_2.c
//this worked.
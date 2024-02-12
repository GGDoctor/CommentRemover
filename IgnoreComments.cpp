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
    State state = ANYTHING;


    //implement the while loop
    while (getline(inputFile, line)) { //looping through each line of the input file
        string result = ""; //String storing the line without comments

        for (size_t i=0; i< line.length(); ++i) { //iterate through each character is line string, one character at a time
            char currentChar = line[i];
            switch (state) {

            //Handle Anything 
            case ANYTHING:
                if (currentChar == '/') { //Checking for the beginning of a comment
                    state = SLASH; //transition to the slash state
                } else {
                    result += currentChar; //Append character to the result
                }
                break;
            
            //Handle Slash
            case SLASH:
                if (currentChar == '/') { //check for a single line comment
                    state = SINGLE_LINE_COMMENT; //transition to a single line comment state
                } else if (currentChar == '*') { //check for a multiple line comment
                    state = MULTI_LINE_COMMENT; //transition to a multi line comment state
                } else {
                    
                    //need to add code for this
                    result += '/'; //continue onto the next '/'
                    result += currentChar; //append the current character

                    state = ANYTHING;
                }
                break;

            //Handle asterick 
            case ASTERICK:
                if (currentChar == '/') {
                    state = SINGLE_LINE_COMMENT; //this is probably not right
                } else if (currentChar != '*') {
                    state = MULTI_LINE_COMMENT;
                } 
                break;


            //Handle single line 
            case SINGLE_LINE_COMMENT:
                if (currentChar == '/') {
                    state = SINGLE_LINE_COMMENT;
                }
                break;


            //Handle Multiple Line 
            case MULTI_LINE_COMMENT:
                if (currentChar == '*') {
                    state = ASTERICK;
                }
                break;                
            }
        }
        cout << result << endl;
    }
    inputFile.close(); // Close the file when we are done working.
    return 0;
}


//I downloaded the file and put them into the project
//then did a g++ -o IgnoreComments IgnoreComments.cpp
//then did ./IgnoreComments programming_assignment_1-test_file_2.c
//this worked.
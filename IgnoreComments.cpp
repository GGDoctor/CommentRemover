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
    SINGLE_LINE, // A comment pertaining '//'
    MULTIPLE_LINE // A comment pertaining '/* bla */
};



int main(int argc, char *argv[]) {
    string filename = argv[1];
    ifstream inputFile(filename.c_str());

    if (!inputFile) {
        std::cerr << "Error. Unable to open the file :( \n"; // Error out if we are unable to open up the file
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        cout << line << endl; // Outputting the file for us to read 
    }

    inputFile.close(); // Close the file when we are done working.
    return 0;
}


//I downloaded the file and put them into the project
//then did a g++ -o IgnoreComments IgnoreComments.cpp
//then did ./IgnoreComments programming_assignment_1-test_file_2.c
//this worked.
/*
Author: Michael Han
Header file for Shakespearean Insult Generator
*/

#include <string>
#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdlib>
using namespace std;

// Exception class for when the file cannot be read
class FileException {

public:
    FileException(const string&);
    string what() const;
private:
    string message;
};

// Exception class for when the number of insults requested is out of bounds
class NumInsultsOutOfBounds {

public:
    NumInsultsOutOfBounds(const string&);
    string what() const;
private:
    string message;
};


// InsultGenerator class
class InsultGenerator {

public:
    InsultGenerator();
    void initialize();
    string talkToMe();
    vector<string> generate(const int numInsults);
    vector<string> generateAndSave(const string filename, const int numInsults);
private:
    vector<string> col1, col2, col3;
    //set<string> insultGroup;
    int generateRandomNumber(const int max);
};
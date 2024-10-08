/*
Author: Michael Han
C++ logic to create Shakespearean Insult Generator 
*/

// stdafx.h
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <exception>
#include <cstdlib>
#include <ctime>

#include "insultgenerator_21mh124.h"
using namespace std;

// null constructor
InsultGenerator::InsultGenerator() {
    // Seed the random number generator every time the program is run
    srand(time(0));
}

//Generates a random number
int InsultGenerator::generateRandomNumber(const int max) {
    // Generate a random number between 1 and max
    int n = 1 + rand() % max;
    return n; 
}

//Combines vectors to generate insult
string InsultGenerator::talkToMe(){
    int num1, num2, num3;
    if (col1.size() == 0 || col2.size() == 0 || col3.size() == 0){
        throw FileException("File could not be read");
    }
    // Generate random numbers to select a word from each column
    num1 = generateRandomNumber(col1.size());
    num2 = generateRandomNumber(col2.size());
    num3 = generateRandomNumber(col3.size());
    return "Thou " + col1[num1] + " " + col2[num2] + " " + col3[num3] + "!";
}

//Reads the file line by line and splits into 3 column vectors
void InsultGenerator::initialize(){
    ifstream file("InsultsSource.txt");
    if (!file){
        throw FileException("File could not be read");
    }
    string line;
    while (getline(file, line)){
        stringstream ss(line);
        string word;
        vector<string> words;
        while (ss >> word){
            words.push_back(word);
        }
        col1.push_back(words[0]);
        col2.push_back(words[1]);
        col3.push_back(words[2]);      
    }


    file.close();
}

//Generates and saves the insults to a file
vector<string> InsultGenerator::generate(const int numInsults){
    if (numInsults < 1 || numInsults > 10000){
        throw NumInsultsOutOfBounds("Number of insults requested is out of bounds 0 < insults <= 10000");
    }

    vector<string> insults;
    while (insults.size() < numInsults) {
        string newInsult = talkToMe();
        
        // Only add the insult if it's not already in the vector
        if (find(insults.begin(), insults.end(), newInsult) == insults.end()) {
            insults.push_back(newInsult);
        }
    }
    //sort the insults into alphabetical order
    sort(insults.begin(), insults.end());

    return insults;
}

//Generates and saves the insults to a file
vector<string> InsultGenerator::generateAndSave(const string filename, const int numInsults){
    ofstream file(filename);
    if (numInsults < 1 || numInsults > 10000){
        throw NumInsultsOutOfBounds("Number of insults requested is out of bounds 0 <= insults <= 10000");
    }
    else{
        vector<string> insults = generate(numInsults);
        for (int i = 0; i<insults.size(); i++){
            file << insults[i] << endl;
        }
        file.close();
        return insults;
    }
}

//FileException implementation
FileException::FileException(const string& message) : message(message) {}

string FileException::what() const { 
    return message; 
}

//NumInsultsOutOfBounds implementation
NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& message) : message(message) {}

string NumInsultsOutOfBounds::what() const {
	return message;
}
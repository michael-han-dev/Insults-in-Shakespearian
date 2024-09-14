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

#include <insultgenerator_20347013.h>
using namespace std;


//Generates a random number
int InsultGenerator::generateRandomNumber(int max) {
    return rand() % max;
}

string InsultGenerator::talkToMe(){
    int num1, num2, num3;
    num1 = generateRandomNumber(col1.size()-1);
    num2 = generateRandomNumber(col2.size()-1);
    num3 = generateRandomNumber(col3.size()-1);
    return "Thou " + col1[num1] + " " + col2[num2] + " " + col3[num3] + "!";
}

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



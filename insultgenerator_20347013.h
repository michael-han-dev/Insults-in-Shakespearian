/*
Author: Michael Han
Header file for Shakespearean Insult Generator
*/

#include <string>
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


class InsultGenerator{

public:
    void initialize();
    string talkToMe();
    vector<string> generate(int numInsults);
    void generateAndSave(string filename, int numInsults);
    InsultGenerator();
    ~InsultGenerator();

};
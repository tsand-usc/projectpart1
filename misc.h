
#ifndef MISC_H
#define MISC_H

#include <iostream>
#include <string>
#include <algorithm>
#include "person.h"

using namespace std;

void printMe(string type);



// Part 1 TODO.
string IDName(string str1, string str2);  // concat str1 and str2, remove spaces, make all letters lower case.

bool check_idname(string query_id, Person* p);

string get_idname(Person* p);

void print_friends(Person* p);

#endif

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <sstream>
#include "string.h"
#include <stdio.h>
// TODO: You may need to add other libraries here!
#include <algorithm> // We need this for the erase and remove functions.
using namespace std;


class Contact {
    // TODO: private or protected? Look at its children!	
protected:  
    /*  We use protected since we want the Contact class as well 
        as any children classes that inherit from Contact to have the
        'type' variable (e.g., type = "Work" can be for email or phone).
        private access specifier would restrict type to just Contact
        preventing children classes from accessing the variable. 
    */ 
    string type;
public:
    // the following functions are pure virtual functions
	virtual void print() = 0;
    virtual string get_contact(string style="full") = 0;
	virtual void set_contact() = 0;
};


class Email: public Contact{
private:
	string email_addr;
public:
    Email(string type, string email_addr);
    // TODO: Complete me!
    void print();
    string get_contact(string style);
    void set_contact();

};


class Phone: public Contact{
private:
    // TODO: modify dataType! Can int store 10 digit phone-number? 
	long long phone_num; 
public:
    Phone(string type, string phone_number);
    // TODO: Complete me!
    void print();
    string get_contact(string style);
    void set_contact();
};

#endif


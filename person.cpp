#include "person.h"

Person::Person(){ //DONE 
    // I'm already done! 
    set_person();
}


Person::~Person(){ //DONE
    delete birthdate;
	delete email;
	delete phone; 
    // TODO: complete the method!
}


Person::Person(string fname, string lname, string bdate, string email, string phone){ //DONE 
    // TODO: Complete this method!													
    // phone and email strings are in full version
	
	f_name = fname; 
	l_name = lname; 
	birthdate = new Date(bdate);
	this->email = new Email("full", email); // may need to change "full" later, since these constructors aren't written yet 
	this->phone = new Phone("full", phone); 

	prev = NULL;
	next = NULL;

}


Person::Person(string filename){ //DONE
    set_person(filename);
}


void Person::set_person(){ // DONE
    // prompts for the information of the user from the terminal
    // first/last name can have spaces!
    // date format must be "M/D/YYYY"
    // We are sure user enters info in correct format.
    // TODO: complete this method!
    
    string temp;
    string type;

    cout << "First Name: ";
    // pay attention to how we read first name, as it can have spaces!
    std::getline(std::cin, f_name);

	cout << "Last Name: ";
    std::getline(std::cin,l_name);

    cout << "Birthdate (M/D/YYYY): ";
    std::getline(std::cin,temp);
    // pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    birthdate = new Date(temp); 

    cout << "Type of email address: ";
	std::getline(std::cin, type);
    cout << "Email address: ";
	std::getline(std::cin, temp);
	email = new Email(type, temp); 

    cout << "Type of phone number: ";
	std::getline(std::cin, type);
    cout << "Phone number: ";
	std::getline(std::cin, temp);
	phone = new Phone(type, temp); 

	prev = NULL;
	next = NULL; 
}


void Person::set_person(string filename) { //BROKEN
										   // reads a Person from a file
										   // Look at person_template files as examples.     
										   // Phone number in files can have '-' or not.
										   // TODO: Complete this method!
	string temp, type, data;

	std::fstream infile;
	infile.open(filename.c_str()); // open the file

	getline(infile, f_name);	//get first name

	getline(infile, l_name);	// get last name

	getline(infile, temp);		// get birthdate line
	birthdate = new Date(temp); // make birthdate

	getline(infile, temp);
	if (strstr(temp.c_str(), "(")) { temp.erase(remove(temp.begin(), temp.end(), '(')); }
	if (strstr(temp.c_str(), ")")) { temp.erase(remove(temp.begin(), temp.end(), ')')); }
	std::stringstream sin(temp);
	sin >> type;
	sin >> data;
	phone = new Phone(type, data);

	temp.clear(); 
	getline(infile, temp);
	if (strstr(temp.c_str(), "(")) { temp.erase(remove(temp.begin(), temp.end(), '(')); }
	if (strstr(temp.c_str(), ")")) { temp.erase(remove(temp.begin(), temp.end(), ')')); }
	std::stringstream sin2(temp);
	sin2 >> type;
	sin2 >> data;
	email = new Email(type, data);

	infile.close();				   // close the file 

	prev = NULL;
	next = NULL;
}


bool Person::operator==(const Person& rhs){ //DONE
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)
	if ((this->f_name == rhs.f_name) && (this->l_name == rhs.l_name) && (*(this->birthdate) == *(rhs.birthdate))) {
		return 1;
	} else {
		return 0; 
	}
}

bool Person::operator!=(const Person& rhs){  // DONE 
    // TODO: Complete this method!
	if ((this->f_name == rhs.f_name) && (this->l_name == rhs.l_name) && (*(this->birthdate) == *(rhs.birthdate))) {
		return 0;
	} else {
		return 1;
	}
}


void Person::print_person(){ // DONE 
    // Already implemented for you! Do not change!
	cout << l_name << ", " << f_name << endl;
	//cout << "l_name: " << &l_name << endl;
	//cout << "f_name: " << &f_name << endl;
	birthdate->print_date("Month D, YYYY");
	//cout << "BD: " << birthdate << endl;
	email->print();
	//cout << "email: " << email << endl;
	phone->print();
	//cout << "phone: " << phone << endl;
	//cout << "SELF PTR: " << this << endl;
	//cout << "NEXT: " << this->next << endl;
	//cout << "PREV: " << this->prev << endl;
}



#include "contact.h" 
#include "string.h"
// TODO: Add needed libraries! 

using namespace std;

Email::Email(string type, string email_addr){
    // TODO: Complete me!
    this->type = type;
    this->email_addr = email_addr;
}


void Email::set_contact(){
    // TODO: Do not change the prompts!
	
    cout << "Enter the type of email address: ";
    // some code here
    cin >> this->type;
    cout << "Enter email address: ";
    // some code here
    cin >> this->email_addr;
}


string Email::get_contact(string style){
    // Note: We have default argument in declaration and not in definition!
    // emaple: Email (USC): tommytrojan@usc.edu
	if (style == "full") {
		return "Email (" + type + "): " + email_addr;
	}else{
		return email_addr;
	}
}


void Email::print(){
    // Note: get_contact is called with default argument
	/*  cout << get_contact() << endl; // Original. */
    cout << get_contact("full") << endl;
	
}


Phone::Phone(string type, string num){
    // TODO: It is possible that num includes "-" or not, manage it! 222-444-7898
    // TODO: Complete this method!
    string character_to_check = "-";
    this->type = type;

	string temp = ""; 
	for (int i = 0; i < num.length(); i++) {
		switch (num.at(i)) {
			case '0':
				temp += "0";
			break;

			case '1':
				temp += "1";
			break;

			case '2':
				temp += "2";
			break;

			case '3':
				temp += "3";
			break;

			case '4':
				temp += "4";
			break;

			case '5':
				temp += "5";
			break;

			case '6':
				temp += "6";
			break;

			case '7':
				temp += "7";
			break;

			case '8':
				temp += "8";
			break;

			case '9':
				temp += "9";
			break;
		}
	}
    // Note: erase and remove are defined in C++98.
    //if(strstr(num.c_str(), "-")){ num.erase(remove(num.begin(), num.end(), '-')); }
    //if(strstr(num.c_str(), "(")){ num.erase(remove(num.begin(), num.end(), '(')); }
    //if(strstr(num.c_str(), ")")){ num.erase(remove(num.begin(), num.end(), ')')); }
    //if(strstr(num.c_str(), " ")){ num.erase(remove(num.begin(), num.end(), ' ')); }
    this->phone_num = atoll(temp.c_str());
    /* Note: Modify the following code can help you implementing this function
     * This code has a bug, can you understand why?
    long int area_code = atoi(num.substr(0, 3).c_str());
    long int  number = atoi(num.substr(3).c_str()); 
    this->phone_num = area_code*10000000 + number; 
    */
    // TODO? Add Is a number checking?
}


void Phone::set_contact(){
    // TODO: Complete this method
    // Use the same prompts as given!
    string num;
	cout <<"Enter the type of phone number: ";
    cin >> this->type;
	cout << "Enter the phone number: ";
    // TODO: Parse the phone number like Phone::Phone(). There may be "-" in the number.
    cin >> num;
    if(strstr(num.c_str(), "-")){ num.erase(remove(num.begin(), num.end(), '-')); }
    if(strstr(num.c_str(), "(")){ num.erase(remove(num.begin(), num.end(), '(')); }
    if(strstr(num.c_str(), ")")){ num.erase(remove(num.begin(), num.end(), ')')); }
    if(strstr(num.c_str(), " ")){ num.erase(remove(num.begin(), num.end(), ' ')); }
    this->phone_num = atoll(num.c_str());
}


string Phone::get_contact(string style){
    // TODO: Complete this method, get hint from Email 
    // follow the format of this example: Phone (Office): 310-192-2847

    /* Note: Modify the following code can help you implementing this function
     * This code has a bug, can you understand it？
    int x1 = (phone_num/10000000);
	int x2 = ((phone_num)/10000)%1000;
	int x3 = phone_num%10000;
    */ 
    stringstream stream;            // Create a stream to put our number into.
    stream << this->phone_num;      // Input our number into our stream.
    string phone_num_str = stream.str();
    // Below: perform operations on string of number to get appropriate formatting.
    // 10-digit Phone Number: 1 2 3             4 5 6           7 8 9 0
    // Array indices        : 0 1 2             3 4 5           6 7 8 9
    // Contact String Format:substr(0,2) + "-"+substr(3,5)+"-"+substr(6-9)

    /*  Need to add error checking / safe default for numbers that are
        less than 10 digits in Phone constructor
        otherwise the below will overflow if len(number) < 10 
        since substr(6,9) accesses 10th element... */

    if (style=="full" && strlen(phone_num_str.c_str()) == 10)
    {
		return "Phone (" + type + "): ("
			+ phone_num_str.substr(0, 3) + ")"
			+ phone_num_str.substr(3, 3) + "-"
			+ phone_num_str.substr(6, 4);
    }        
    else 
    {
		return "Phone: " + phone_num_str; // Just return the phone number with no formatting.
    }
}


void Phone::print(){
    // Note: get_contact is called with default argument
	cout << get_contact("full") << endl;
}



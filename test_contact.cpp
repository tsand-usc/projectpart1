#include "contact.h"

/*Quest Jelinek, Thomas Sand. Program for testing contact.cpp. */
int main()
{
    // Test Email.
    Email temail1("Home", "temail1@usc.edu");
    cout << "==temail.print====" << endl;
    temail1.print();
    cout << "==temail.print====" << endl;
    cout << "==get contact full====" << endl;
    cout << "\n\n" << temail1.get_contact("full");
    cout << "==get contact full====" << endl;
    cout << "==get contact not full====" << endl;
    cout << "\n\n" << temail1.get_contact("not_full");
    cout << "==get contact not full====" << endl;
    cout << "\nTesting set contact." << endl;
    temail1.set_contact();
    cout << "===end of set contact===" << endl;
    cout << "==temail.print====" << endl;
    temail1.print();
    cout << "==temail.print====" << endl;
    cout << "===temail get contact full===" << endl;
    cout << "\n\n" << temail1.get_contact("full");
    cout << "===temail get contact full===" << endl;
    cout << "===temail get contact not full===" << endl;
    cout << "\n\n" << temail1.get_contact("not_full");
    cout << "===temail get contact not full===" << endl;
    //END // Test Email.
    
    // Test Phone.
    Phone tphone1("Home", "()- 0123456789");
    cout << "===tphone print===" << endl;
    tphone1.print();
    cout << "===tphone print===" << endl;
    cout << "===tphone get contact full===" << endl;
    cout << "\n\n" << tphone1.get_contact("full");
    cout << "===tphone get contact full===" << endl;
    cout << "===tphone get contact not full===" << endl;
    cout << "\n\n" << tphone1.get_contact("not_full");
    cout << "===tphone get contact not full===" << endl;
    cout << "\nTesting set contact." << endl;
    tphone1.set_contact();
    cout << "===tphone end set contact===" << endl;
    cout << "===tphone print===" << endl;
    tphone1.print();
    cout << "===tphone print===" << endl;
    cout << "===tphone get contact full===" << endl;
    cout << "\n\n" << tphone1.get_contact("full");
    cout << "===tphone get contact full===" << endl;
    cout << "===tphone get contact not full===" << endl;
    cout << "\n\n" << tphone1.get_contact("not_full");
    cout << "===tphone get contact not full===" << endl;
    // END // Test Phone.

    return 0;
}

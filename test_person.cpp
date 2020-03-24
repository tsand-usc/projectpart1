
#include <iostream>
#include "person.h"

int main(){

    Person c1;
    //cout << "===Print Person 1===" << endl;
    c1.print_person();
    //cout << "===Print Person 1 end===" << endl;
    cout << "----------------\n";

    Person c2("person_template.txt");
    //cout << "===Print Person 2===" << endl;
    c2.print_person();
    //cout << "===Print Person 2 end===" << endl;
    cout << "----------------\n";

    cout << "Is c1 equal to c2: " << (c1==c2) << endl;
    cout << "Is c1 not equal to c2: " << (c1!=c2) << endl;

    return 0;
}


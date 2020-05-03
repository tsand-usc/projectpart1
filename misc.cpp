
#include "misc.h"


void printMe(string type){
    if (type == "banner"){
        char banner[] = \
"   ######## ########   #######        ##    ###    ##    ##         ########   #######   #######  ##    ## \n \
     ##    ##     ## ##     ##       ##   ## ##   ###   ##         ##     ## ##     ## ##     ## ##   ## \n \
     ##    ##     ## ##     ##       ##  ##   ##  ####  ##         ##     ## ##     ## ##     ## ##  ## \n \
     ##    ########  ##     ##       ## ##     ## ## ## ## ####### ########  ##     ## ##     ## ##### \n \
     ##    ##   ##   ##     ## ##    ## ######### ##  ####         ##     ## ##     ## ##     ## ##  ## \n \
     ##    ##    ##  ##     ## ##    ## ##     ## ##   ###         ##     ## ##     ## ##     ## ##   ## \n \
     ##    ##     ##  #######   ######  ##     ## ##    ##         ########   #######   #######  ##    ##\n";
        cout << endl << banner << endl << endl;
    }

}

// Part 1 TODO.    
string IDName(string str1, string str2)
{
    string ret;
    ret = str1 + str2;
    ret.erase(remove(ret.begin(), ret.end(), ' '), ret.end()); 
    transform(ret.begin(), ret.end(), ret.begin(), ::tolower);
    return ret;
}

string get_idname(Person* p)
{
    return IDName(p->get_last_name(), p->get_first_name());
}

// Return true if desired_id equals given person's ID.
bool check_idname(string query_id, Person* p)
{    
    //string p_id = IDName(p->get_last_name(), p->get_first_name());
    string p_id = get_idname(p);
    if(p_id == query_id)
        return true; 
    return false;
}

void print_friends(Person* p)
{
    vector<Person*>	friends = p->friends;
    for(vector<Person*>::iterator it = friends.begin(); it != friends.end(); it++)
    {
        (*it)->print_person();
    }
}

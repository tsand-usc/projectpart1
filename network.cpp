#include "network.h"
#include <limits>
#include "misc.h"
#include <fstream>

Network::Network() {
	head = NULL;
	tail = NULL;
	count = 0;
}


Network::Network(string fileName) { // done 
									// TODO: complete this method!
									// Implement it in one single line!
									// You may need to implement the load method before this!
	loadDB(fileName);
}

Network::~Network() { // Double Check this
					  // TODO: Complete this method
					  // Destructure delete all the Person

	Person* ptr = head;
	while (head != NULL) {
		ptr = head->next;
		delete head;
		head = ptr;
	}

}


void Network::push_front(Person* newEntry) { //DONE
											 // Adds a new Person (newEntry) to the front of LL
	newEntry->prev = NULL;
	newEntry->next = head;

	if (head != NULL)
		head->prev = newEntry;
	else
		tail = newEntry;

	head = newEntry;
	//std::cout << "NEW HEAD: " << head << endl;
	//std::cout << "NEW TAIL: " << tail << endl;
	count++;
	
}


void Network::push_back(Person* newEntry) { //DONE
											// TODO: Complete this method!
											// Adds a new Person (newEntry) to the back of LL
	newEntry->prev = tail;
	newEntry->next = NULL;

	if (tail != NULL)
		tail->prev = newEntry;
	else
		head = newEntry;

	tail = newEntry;
	count++;
}


void Network::printDB() { //DONE 
						  // Don't change this method
						  // Note: Notice that we don't need to update this even after adding to Person attributes
						  // This is a feature of OOP, classes are supposed to take care of themselves!
	cout << "Number of persons: " << count << endl;
	cout << "------------------------------" << endl;
	Person* ptr = head;
	while(ptr != NULL) {
		std::cout << "Printing A Person" << std::endl;
		ptr->print_person();
		cout << "------------------------------" << endl;
		ptr = ptr->next;
	}
}


void Network::saveDB(string filename) { 
   
   
   std::ofstream outfile;                                             
	outfile.open(filename.c_str());                   // open the file 
	Person* ptr = head;                               // go to start of list
	while(ptr != NULL) {                              // iterate through list
		ptr->save_person(outfile);                     // save person to file
		ptr = ptr->next;
	}
	outfile.close();				                       // close the file 
   
   /* // moved this inside of save_person
	std::ofstream outfile;                            // written based on https://www.geeksforgeeks.org/io-redirection-c/
	outfile.open(filename.c_str());                   // open the file 
	streambuf* stream_buffer_cout = cout.rdbuf();     // space for cout output
	streambuf* stream_buffer_file = outfile.rdbuf();  // space for output to file
	cout.rdbuf(stream_buffer_file);                   // send cout to the file stream
	printDB();					                          // Will send to cout, so redirect to file 
	outfile.close();				                       // close the file 
	cout.rdbuf(stream_buffer_cout);                   // send cout back to cout, just in case
	*/
}


void Network::loadDB(string filename) { // DO THIS
										// TODO: Complete this method!
										// Loads the netwrok from file <filename>
										// The format of the input file is similar to saveDB
										// Look at network studentDB.txt as a template
										// Phone number can be with dashes or without them
										// You need to use the following constructor of the Person class, Person::Person(fname, lname, bdate, email, phone)

	Person* ptr = head;
	while (head != NULL) {
		ptr = head->next;
		delete head;
		head = ptr;
		count--;
	}
	head = NULL;
	tail = NULL;
	ifstream infile;
	infile.open(filename.c_str());
	string buff, fname, lname, bdate;
	string phone, email; 
   Person * newEntry = NULL; 
   deque< deque<string> > idList; 
   
	// TODO: Declare other variables if needed
   
	while (getline(infile, buff)) {
	 
	   idList.push_front(deque<string>()); 
	   
		lname = buff.substr(0, buff.find(',')); // read last name
		fname = buff.substr(buff.find(',') + 2);// read first name
		
		buff.clear();
		getline(infile, bdate);                 // read birthdate
		// TODO: read email and phone
      getline(infile, buff);                  // read email info
      email = buff.substr(buff.find(')') + 2);// read email
      
      buff.clear(); 
      getline(infile, buff);                  // read phone info
      for (int i = 0; i < buff.length(); i++) {
		   switch (buff.at(i)) {
			   case '0':
				   phone += "0";
			   break;

			   case '1':
				   phone += "1";
			   break;

			   case '2':
				   phone += "2";
			   break;

			   case '3':
				   phone += "3";
			   break;

			   case '4':
				   phone += "4";
			   break;

			   case '5':
				   phone += "5";
			   break;

			   case '6':
				   phone += "6";
			   break;

			   case '7':
				   phone += "7";
			   break;

			   case '8':
				   phone += "8";
			   break;

			   case '9':
				   phone += "9";
			   break;
		   }
	   }
       
		// TODO: use the constructor Person::Person(fname, lname, bdate, email, phone) to modify the following line
		
		newEntry = new Person(fname, lname, bdate, email, phone);

		this->push_front(newEntry);
		
		phone.clear();
		email.clear(); 
      buff.clear(); 
      
      getline(infile, buff); 
      while(buff.at(0) != '-'){ // make new list for each entry 
         idList.front().push_back(buff);          // add friend ids ot the list
         buff.clear(); 
         getline(infile, buff);
         if(buff == ""){
            break; 
         }
         //cout << "BUFF:" << buff << endl;                        
      }
      //newEntry->print_person();
	}
	
	for(Person * entry = head; entry != NULL; entry = entry->next){ // look through each person in the list
	   while(!idList.front().empty()){                                    // while their list of friends is not empty
	      entry->addFriend(search(idList.front().front()));               // add the friend
	      idList.front().pop_front();                                     // remove added person
	   } 
	   idList.pop_front();                                                // when list is empty remove it
	}
	infile.close(); 
}

Person* Network::search(string fname, string lname, string bdate) { 
																	// TODO: Complete this method!
																	// Search the Network for the given fname, lname, bdate
																	// You may create a new person, say searchEntry, with fname, lname and bdate. Think about what Person constructor will be helpful with these arguments.
																	// And use == overloaded operator between two persons
																	// if found, returns a pointer to it, else returns NULL
																	// Don't forget to delete allocated memory.
	bool exit = false;
	Person * searchEntry = new Person(fname, lname, bdate, "blank@blank.com", "(000)000-0000");

	Person *ptr = head;

	while (!exit) {
		if ((*searchEntry) == (*ptr)) {
			return ptr;
		}
		else {
			if ((ptr->next != NULL) && (ptr != ptr->next)) {
				ptr = ptr->next;
			}
			else {
				exit = true;
			}
		}
	}
	delete searchEntry; 
	return NULL;
}

Person* Network::search(string queryid) 
{ 																	
	bool exit = false;	
	Person *ptr = head;

	while (!exit) {
		if (check_idname(queryid, ptr)) {
			return ptr;
		}
		else {
			if ((ptr->next != NULL) && (ptr != ptr->next)) {
				ptr = ptr->next;
			}
			else {
				exit = true;
			}
		}
	}
	return NULL;
}

void Network::friends_recommendations(int k){

	deque<Person *> list; 
	deque<Person *> nextLevel; 
	vector<Person *> visited;
	vector<Person *> recom;
	
	if(head == NULL){ // no one is in the database
	   cout << "No one in the database" << endl; 
		return; 
	}
	
	for(Person * entry0 = head; entry0 != NULL; entry0 = entry0->next){ // iterate over each person
		
 		visited.push_back(entry0); 						 // Adds person to visited so they dont see themselves
		for(int i = 0; i < entry0->friends.size(); i++){ // fills visited list with people who are already friends
			visited.push_back(entry0->friends[i]); 
		}
		
		
		// generate recommendations
		list.clear(); 
		list.push_back(entry0);								   // add checking person to list
		for(int level = 0; level <= k; level++){ 			// iterate over the levels
		   
			for(int i = 0; i < list.size(); i++){
			   for(int j = 0; j < visited.size(); j++){
			      if(list[i] == visited[j]){
			         break;  
			      }else if(j == (visited.size()-1)){ 
			         recom.push_back(list[i]);
			         visited.push_back(list[i]);
			      } 
			   }
			}
			
			while(!list.empty()){										// look through every person in the list
            
				for(int l = 0; l < list.front()->friends.size(); l++){  // take the first person and look through their friends
					nextLevel.push_back(list.front()->friends[l]);      // add the friends to the list of people at the next level
				}
				list.pop_front();										// remove the person from the list  
			}  
			list = nextLevel; 											// set the new friends to the new list of people to check
			nextLevel.clear(); 											// reset to be filled next loop
		}
		
		// print and reset for next loop
		string idname;
		cout << "----------------------------------" << endl;
		cout << "For " << entry0->get_last_name() << ", " << entry0->get_first_name() << endl;  
		for(int h = 0; h < recom.size(); h++){
		   idname = recom[h]->get_last_name() + recom[h]->get_first_name();
		   //idname.erase(remove(idname.begin(), idname.end(), ' '), idname.end()); 
		   transform(idname.begin(), idname.end(), idname.begin(), ::tolower);		
		   cout << idname << endl; 	
		}
		cout << "----------------------------------" << endl;
		
		visited.clear();	   // reset visited list
		recom.clear(); 		   // reset recommendations	
	}
} 

bool Network::remove(string fname, string lname, string bdate) { // DO THIS
																 // TODO: Complete this method! Follow these steps:
																 // Create a new person with the the give arguments as you do in search
																 // Search if this person exists using search method. If it does not exist just return false! Else, remove the person from LL, make the other connections connected
																 // Don't forget to delete allocated memory, change count and returning values!

	Person *removeEntry = search(fname, lname, bdate);
	if (removeEntry != NULL) {
		if (removeEntry == head) { // if removing first in the list
			if (removeEntry->next != NULL) {
				(removeEntry->next)->prev = removeEntry->prev;
			}
			head = removeEntry->next;
		} else if (removeEntry == tail) { // if removing last in the list
			(removeEntry->prev)->next = removeEntry->next;
			tail = removeEntry->prev;

		} else { // if removing middle of list
			(removeEntry->prev)->next = removeEntry->next;
			(removeEntry->next)->prev = removeEntry->prev;
		}
		delete removeEntry;
		count--; 
		return 1;
	} else {
		return 0;
	}
}

void Network::showMenu() {
	// TODO: Complete this method!
	// All the prompts are given to you, 
	// You should add code before, between and after prompts!

	int opt;
	while (1) {
		cout << "\033[2J\033[1;1H";
		printMe("banner"); // from misc library

		cout << "Select from below: \n";
		cout << "1. Load network database \n";
		cout << "2. Save network database \n";
		cout << "3. Add a new person \n";
		cout << "4. Search \n";
		cout << "5. Remove a person \n";
		cout << "6. Print database \n";
		cout << "7. Add friends\n";
		cout << "8. Find New Friends\n"; 
		cout << "\nSelect an option ... ";

		if (cin >> opt) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Wrong option! " << endl;
			return;
		}

		// You may need these variables! Add more if you want!
		string fname, lname, fileName, bdate;
		string phoneNumber, email;
		vector<string> dbFiles; 
		bool found = false; 
		
		cout << "\033[2J\033[1;1H";

		if (opt == 1) { //FIX THIS
						// TODO: Complete me!
			cout << "Loading network database \n";
			// TODO: print all the files in this same directory that have ".db" format
			// Take a look into sample_files.cpp 
			
			DIR *dir;
			struct dirent *ent;
			char targetFolderAddr[] = "./";
			string file;
			int start = 0;
			if ((dir = opendir("./")) != NULL) {
				while ((ent = readdir(dir)) != NULL) {
					file = ent->d_name;
					std::size_t found = file.find(".db");
					if (found != std::string::npos) {
						cout << file << endl;
						dbFiles.push_back(file); 
					}
				}
				closedir(dir);
			}
			else {
				// could not open directory 
				perror("No directory!");
				//return 1;
			}
			
			cout << "Enter the name of the load file: ";
			cin >> fileName;
			 
			for(int i = 0; i < dbFiles.size(); i++){
			   if(fileName == dbFiles[i]){
			      found = true; 
			      break; 
			   }
			} 
			
			if(!found){
			   cout << "File " << fileName << " does not exist!" << endl;
			}else{
			   loadDB(fileName); 
			   cout << "Network loaded from " << fileName << " with " << count << " persons \n";
			}
			found = false; 
			dbFiles.clear(); 
			
		}
		else if (opt == 2) { //DONE
							 // TODO: Complete me!
			cout << "Saving network database \n";
			cout << "Enter the name of the save file: ";
			cin >> fileName;
			saveDB(fileName);
			cout << "Network saved in " << fileName << endl;
		}
		else if (opt == 3) { //DONE
							 // TODO: Complete me!
							 // TODO: use push_front, and not push_back 
							 // Add a new person ONLY if it does not exists!
			
			Person * possibleEntry = NULL;

			if (head == NULL) {
				cout << "Adding a new person \n";
				possibleEntry = new Person();
				push_front(possibleEntry);
				
			}else {
				cout << "First Name: ";
				cin >> fname;
				cout << "Last Name: ";
				cin >> lname;
				cout << "Birthdate (M/D/YYYY): ";
				cin >> bdate;
				cout << "Phone: ";
				cin >> phoneNumber;
				cout << "Email: ";
				cin >> email;

				possibleEntry = new Person(fname, lname, bdate, email, phoneNumber);
				if (search(fname, lname, bdate) == NULL) {
					cout << "Adding a new person \n";
					push_front(possibleEntry);
				
				}else{
					cout << "Person is already in the Database" << endl; 
					delete possibleEntry;
				}
			}
		}
		else if (opt == 4) { //DONE
							 // TODO: Complete me!
			cout << "Searching: \n";
			cout << "First Name: ";
			cin >> fname;
			cout << "Last Name: ";
			cin >> lname;
			cout << "Birthdate (M/D/YYYY): ";
			cin >> bdate;

			Person * individual = search(fname, lname, bdate);
			if (individual != NULL) {
				individual->print_person();
			}
			else {
				cout << "Not found! \n";
			}
			// if found: print person's firstname, lastname, bdate, email, phone using print_person()
			// if not, cout << "Not found! \n";
		}
		else if (opt == 5) { // DONE
							 // TODO: Complete me!
			cout << "Removing a person \n";
			cout << "First name: ";
			cin >> fname;
			cout << "Last name: ";
			cin >> lname;
			cout << "Birthdate (M/D/YYYY): ";
			cin >> bdate;
			if (remove(fname, lname, bdate) == 1) {
				cout << "Remove Successful! \n";
			}
			else {
				cout << "Person not found! \n";
			}
		}
		else if (opt == 6) { //DONE
							 // TODO: Complete me!
			cout << "Network Database: \n";
			printDB();
		}
		else if (opt == 7)
		{
			string person_1_id, person_2_id;
			cout << "Person 1 ID:";			
			cin >> person_1_id;
			cout << endl;
			Person* p1 = search(person_1_id);
			if(p1 == NULL)
			{
				cout << "Person is not found!\n";
			}
			else
			{
				cout << "Person 2 ID:";			
				cin >> person_2_id;
				cout << endl;
				Person* p2 = search(person_2_id);
				if(p2 == NULL)
				{
					cout << "Person is not found!\n";				
				}
				/* If both persons exist, call addFriend to add 
					the other person to its friends vector. 
					You should do so for person 1 and person 2. */
				else
				{
					p1->addFriend(p2);
					p2->addFriend(p1);

					p1->print_person();
					p2->print_person();
					// Testing search and addFriend. This could be made into a helper function in misc.cpp...
					// To implement in misc.cpp, must remove circular dependency with person.h.
					// vector<Person*> friends = p1->friends;
					// for(vector<Person*>::iterator it = friends.begin(); it != friends.end(); it++)
					// {
					// 	(*it)->print_person();
					// }

					// friends = p2->friends;
					// for(vector<Person*>::iterator it = friends.begin(); it != friends.end(); it++)
					// {
					// 	(*it)->print_person();
					// }
				}
			}				
			
		}else if(opt == 8){
		
		   int k; 
		   cout << "Friend Recommendations" << endl;
		   cout << "Search Level: ";
		   cin >> k; 
		   friends_recommendations(k); 
		
		}else {
			cout << "Nothing matched!\n";
		}

		cin.clear();
		cout << "Cleared" << endl;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\n\nPress Enter key to go back to main menu ... ";
		string temp;
		std::getline(std::cin, temp);
		cout << "\033[2J\033[1;1H";
	}
}

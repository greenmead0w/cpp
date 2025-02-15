
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream> //used for cin, cout
#include <string> //used for string class
#include <iomanip> //used for setw
#include <sstream> //used for isstringstream class

class Phonebook {
    Contact contact_arr[8];
 public:
    int oldest; //oldest contact index, to be replaced if pb_size == 8
    int pb_size; //counter for amount of contacts in phonebook
    int get_phonebook_length();
   !!!!!!!!!!!!!!Phonebook(); //constructor
    void get_phonebook_list();
    void print_contact(int index);
    void add_contact_to_phonebook(Contact &contact);
};

#endif
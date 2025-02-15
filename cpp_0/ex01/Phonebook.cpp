#include "Phonebook.hpp"

int Phonebook::get_phonebook_length()
{
    return sizeof(contact_arr) / sizeof(contact_arr[0]);
}

Phonebook(){pb_size = 0; oldest = 0;}
//Alternative syntax using a member initializer list:
 //Phonebook() : pb_size(0), oldest(0) {}

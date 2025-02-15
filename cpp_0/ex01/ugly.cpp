#include <iostream> //used for cin, cout
#include <string> //used for string class
#include <iomanip> //used for setw
#include <sstream> //used for isstringstream class

class Contact {
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
 public:
    Contact () {}; //providing a default constructor to not have issues when declaring an unitialized object
    Contact(std::string fn, std::string ln, std::string nick,
        std::string pn, std::string ds, int valid) 
        {
            first_name = fn;
            last_name = ln;
            nickname = nick;
            phone_number = pn;
            darkest_secret = ds;
            this->valid = valid; //using "this->" here to diff member from param
        }
    int valid; //if no member is empty
    std::string get_first_name() {return first_name;};
    std::string get_last_name() {return last_name;};
    std::string get_nickname() {return nickname;};
    std::string get_phone_number() {return phone_number;};
    std::string get_darkest_secret() {return darkest_secret;};

};

class Phonebook {
    Contact contact_arr[3];
 public:
    int oldest; //oldest contact index, to be replaced if pb_size == 8
    int pb_size; //counter for amount of contacts in phonebook
    int get_phonebook_length(){
        return sizeof(contact_arr) / sizeof(contact_arr[0]);
        };
    Phonebook(){pb_size = 0; oldest = 0;}; //constructor inits pb_size to 0
    void get_phonebook_list();
    void print_contact(int index);
    void add_contact_to_phonebook(Contact &contact);
};


bool ft_isValidPN(std::string pn)
{
    int i(0);
    int len;

    len = pn.length();
    if (len != 9)
        return false;
    while (i < pn.length())
    {
        if (!isdigit(pn[i]))
            return false;
        i++;
    }
    return true;
}

Contact create_contact()
{
    std::string fn, ln, nick, pn, ds;
    int valid;

    std::cout << "Enter first name:\n -> ";
    getline(std::cin, fn);
    std::cout << "Last name:\n -> ";
    getline(std::cin, ln);
    std::cout << "Nickname:\n -> ";
    getline(std::cin, nick);
    std::cout << "Phone number:\n -> ";
    getline(std::cin, pn);
    if (!ft_isValidPN(pn))
    {
        valid = 0;
        ds = "";
        std::cout << "Phone number is either not numeric or not 9 digits. Discarding.\n";
        return Contact(fn, ln, nick, pn, ds, valid);
    }
    std::cout << "Darkest secret:\n -> ";
    getline(std::cin, ds);
    if (fn == "" || ln == "" || nick == "" || pn == "" || ds == "")
    {
        std::cout << "Contact includes an empty field. Discarding.\n";
        valid = 0;
    }
    else
        valid = 1;
    return Contact(fn, ln, nick, pn, ds, valid);

}

//realized after coding that "this->" can be ommited in this case
void Phonebook::add_contact_to_phonebook(Contact &contact)
{
    if (this->pb_size < this->get_phonebook_length())
    {
        this->contact_arr[this->pb_size] = contact;
        this->pb_size++;
    }
    else
        this->contact_arr[this->oldest] = contact;
    this->oldest = (this->oldest + 1) % this->get_phonebook_length();

}

void add_contact(Phonebook &phonebook)
{
    Contact contact;

    std::cout << "You're about to add a new contact.\n"
              << "All fields are required, no empty value will be accepted.\n";
    contact = create_contact();
    if (contact.valid == 0)
        return ;
    else
        phonebook.add_contact_to_phonebook(contact);
    std::cout << "pb_size is: " << phonebook.pb_size << "\n";
    std::cout << "oldest is: " << phonebook.oldest << "\n";
}

std::string ft_truncate(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;

}

void Phonebook::get_phonebook_list()
{
    int i(0);

    while (i < pb_size)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << ft_truncate(contact_arr[i].get_first_name()) << "|";
        std::cout << std::setw(10) << ft_truncate(contact_arr[i].get_last_name()) << "|";
        std::cout << std::setw(10) << ft_truncate(contact_arr[i].get_nickname());
        std::cout << std::endl;
        i++;
    } 
}

void Phonebook:: print_contact(int index)
{
    std::cout << "First name: " << contact_arr[index].get_first_name() << std::endl;
    std::cout << "Last name: " << contact_arr[index].get_last_name() << std::endl;
    std::cout << "Nickname: " << contact_arr[index].get_nickname() << std::endl;
    std::cout << "Phone number: " << contact_arr[index].get_phone_number() << std::endl;
    std::cout << "Darkest secret: " << contact_arr[index].get_darkest_secret() << std::endl;
}

void display(Phonebook &phonebook)
{
    std::string index_str;
    std::istringstream iss;
    int index;

    if (phonebook.pb_size == 0)
    {
        std::cout << "Phonebook is empty, use ADD keyword to populate\n";
        return;
    }

    std::cout << std::setw(10) << ft_truncate("index") << "|";
    std::cout << std::setw(10) << ft_truncate("first name") << "|";
    std::cout << std::setw(10) << ft_truncate("last name") << "|";
    std::cout << std::setw(10) << ft_truncate("nickname\n");

    phonebook.get_phonebook_list();

    std::cout << "Enter valid index to display contact information\n ->";
    std::getline(std::cin, index_str);
    iss.str(index_str);
    if (!(iss >> index))
    {
        std::cout << "Invalid input - not a number\n";
        return;
    }
    else
    {
        if (index >= 0 && index < phonebook.pb_size)
            phonebook.print_contact(index);
        else
        {
            std::cout << "Please enter a valid index between 0 and ";
            std::cout << phonebook.pb_size - 1 << std::endl;
        }
    }

}

int main()
{
    std::string input;
    Phonebook phonebook;

    input ="";
    std::cout << "Hi! This is your phonebook: I only know how to ADD, SEARCH or EXIT\n---------------------------------------------------\n";
    int i(0);
    while(input != "EXIT")
    {
        std::cout<< "Instruction[" << i << "]: ";
        std::getline(std::cin, input);
        if (input == "ADD")
            add_contact(phonebook);
        else if (input == "SEARCH")
            display(phonebook);
        i++;
    }
    return (0);
}


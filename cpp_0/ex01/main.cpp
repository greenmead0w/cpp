

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

void display(Phonebook &phonebook)
{
    std::string index_str;

    if (phonebook.pb_size == 0)
    {
        std::cout << "Phonebook is empty, use ADD keyword to populate\n";
        return;
    }
    ft_print_search_headers();
    phonebook.get_phonebook_list();
    std::cout << "Enter valid index to display contact information\n ->";
    std::getline(std::cin, index_str);
    ft_print_according_to_index(index_str, phonebook);

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
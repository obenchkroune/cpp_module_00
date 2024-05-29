#include "../inc/Phonebook.hpp"

int main(void)
{
    std::string input;
    Phonebook phonebook;

    while (true)
    {
        input.clear();
        std::cout << "$> ";
        std::getline(std::cin, input);
        if (input == "EXIT" || std::cin.eof())
            break ;
        else if (input == "ADD")
            phonebook.addContact();
        else if (input == "SEARCH")
            phonebook.searchContact();
        else
            std::cout << input << ": invalid command\n";
    }
    std::cout << "Goodbye.\n";
    return 0;
}

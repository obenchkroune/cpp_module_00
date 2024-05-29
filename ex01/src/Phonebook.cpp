#include "../inc/Phonebook.hpp"

Phonebook::Phonebook(void)
{
    this->_current = 0;
    this->_size = 0;
}

void Phonebook::addContact(void)
{
    this->_contact[this->_current].setContact();
    this->_current == 7 ? this->_current = 0 : this->_current++;
    if (this->_size < 8) this->_size++;
}

void Phonebook::searchContact(void) const
{
    int idx;

    if (this->_size == 0)
    {
        std::cout << "No contacts found.\n";
        return ;
    }
    std::cout << std::string(45, '-') << std::endl;
    for (int i = 0; i < this->_size; i++)
        this->_contact[i].printRow();
    std::cout << std::string(45, '-') << std::endl;
    std::cout << "Enter index: ";
    std::cin >> idx;
    if (!std::cin.eof())
    {
        std::cin.ignore();
        this->printContact(idx);
    }
}

void Phonebook::printContact(int idx) const
{
    if (idx < 0)
        std::cout << "index cannot be negative.\n";
    if (idx >= _size)
        std::cout << "contact with index " << idx << " not found.\n";
    else
        this->_contact[idx].printInfo();
}

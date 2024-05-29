#pragma once

#include "../inc/Contact.hpp"
#include <iostream>

class Phonebook {
    Contact _contact[8];
    int     _current;
    int     _size;
    
    public:
        Phonebook(void);
        void addContact(void);
        void searchContact(void) const;
        void printContact(int idx) const;
};


#pragma once

#include <iostream>
#include <iomanip>

class Contact {

public:
    void setContact(void);
    void printColumn(std::string field) const;
    void printRow(void) const;
    void printInfo(void) const;

private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _secret;

    void promptField(std::string& field, std::string prompt);

};

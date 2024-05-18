#include <Contact.hpp>

void Contact::promptField(std::string& field, std::string field_name)
{
    field.clear();
    while (field.empty())
    {
        std::cout << field_name << ": ";
        std::getline(std::cin, field);
        if (std::cin.eof())
            break ;
        if (field.empty())
        {
            std::cout
                << "The field "
                << field_name 
                << " cannot be empty.\n";
        }
    }
}

void Contact::setContact(void)
{
    this->promptField(this->_firstName, "First Name");
    this->promptField(this->_lastName, "Last Name");
    this->promptField(this->_nickname, "Nickname");
    this->promptField(this->_phoneNumber, "Phone Number");
    this->promptField(this->_secret, "Dark Secret");
}

void Contact::printRow(void) const
{
    std::cout << "|";
    this->printColumn(this->_firstName);
    std::cout << "|";
    this->printColumn(this->_lastName);
    std::cout << "|";
    this->printColumn(this->_nickname);
    std::cout << "|";
    this->printColumn(this->_phoneNumber);
    std::cout << "|\n";
}


void Contact::printColumn(std::string field) const
{
    if (field.length() > 10)
        field = field.substr(0, 9).append(".");
    std::cout
        << std::setw(10)
        << std::left
        << field;
}

void Contact::printInfo(void) const
{
    std::cout
        << std::string(45, '-') << std::endl
        << "First Name: " << this->_firstName << std::endl
        << "Last Name: " << this->_lastName << std::endl
        << "Nickname: " << this->_nickname << std::endl
        << "Phone Number: " << this->_phoneNumber << std::endl
        << "Dark Secret: " << this->_secret << std::endl
        << std::string(45, '-') << std::endl;
}

#include "Contact.class.hpp"

//
// ::::::::::::::::::::::::::::Canonical form::::::::::::::::::::::::::::::::
//
Contact::Contact( void ) //constructor by default
{
	std::cout << "Default constructor called for Contact " << std::endl;
	std::cout << COLORContact << "Contact default constructor called." << RESETContact << std::endl;
	return ;
}

Contact::Contact(const Contact& other) //constructor by copy
{
	std::cout << COLORContact << "Contact copy constructor called." << RESETContact << std::endl;
	*this = other;
	return;
}

Contact &  Contact::operator=(const Contact & other)
{
	std::cout << COLORContact << "Contact copy assignment operator called." << RESETContact <<std::endl;
	if (this != &other)
	{
		*this = other;
	}
	return *this; 
}

Contact::~Contact( void ) // destructor
{
	std::cout << COLORContact << "Contact destructor called." << RESETContact << std::endl;
	return ;
}

// Constructor(s)
//Contact::Contact(${ARGS_LIST});

// Getters

// Setters

// Comparison operators

// public member functions
// protected  member functions

// private member funcions

// Helper functions for canonicalization
std::string Contact::canonizeme( void ) const {
	std::string _str_ = "No implemented yet";
	return (_str_);
}


std::ostream& operator<<(std::ostream& os, const Contact& obj)
{
	os << COLORContact << "Contact " << obj.canonizeme()  << RESETContact << std::endl;
	return os;
};


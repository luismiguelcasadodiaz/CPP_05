#include "PhoneBook.class.hpp"

//
// ::::::::::::::::::::::::::::Canonical form::::::::::::::::::::::::::::::::
//
PhoneBook::PhoneBook( void ) //constructor by default
{
	std::cout << "Default constructor called for PhoneBook " << std::endl;
	std::cout << COLORPhoneBook << "PhoneBook default constructor called." << RESETPhoneBook << std::endl;
	return ;
}

PhoneBook::PhoneBook(const PhoneBook& other) //constructor by copy
{
	std::cout << COLORPhoneBook << "PhoneBook copy constructor called." << RESETPhoneBook << std::endl;
	*this = other;
	return;
}

PhoneBook &  PhoneBook::operator=(const PhoneBook & other)
{
	std::cout << COLORPhoneBook << "PhoneBook copy assignment operator called." << RESETPhoneBook <<std::endl;
	if (this != &other)
	{
		*this = other;
	}
	return *this; 
}

PhoneBook::~PhoneBook( void ) // destructor
{
	std::cout << COLORPhoneBook << "PhoneBook destructor called." << RESETPhoneBook << std::endl;
	return ;
}

// Constructor(s)
//PhoneBook::PhoneBook(${ARGS_LIST});

// Getters

// Setters

// Comparison operators

// public member functions
// protected  member functions

// private member funcions

// Helper functions for canonicalization
std::string PhoneBook::canonizeme( void ) const {
	std::string _str_ = "No implemented yet";
	return (_str_);
}


std::ostream& operator<<(std::ostream& os, const PhoneBook& obj)
{
	os << COLORPhoneBook << "PhoneBook " << obj.canonizeme()  << RESETPhoneBook << std::endl;
	return os;
};


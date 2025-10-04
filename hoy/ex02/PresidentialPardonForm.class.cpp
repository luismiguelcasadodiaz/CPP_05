#include "PresidentialPardonForm.class.hpp"

//
// ::::::::::::::::::::::::::::Canonical form::::::::::::::::::::::::::::::::
//
PresidentialPardonForm::PresidentialPardonForm( void ) //constructor by default
{
	std::cout << "Default constructor called for PresidentialPardonForm " << std::endl;
	std::cout << COLORPresidentialPardonForm << "PresidentialPardonForm default constructor called." << RESETPresidentialPardonForm << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) //constructor by copy
{
	std::cout << COLORPresidentialPardonForm << "PresidentialPardonForm copy constructor called." << RESETPresidentialPardonForm << std::endl;
	*this = other;
	return;
}

PresidentialPardonForm &  PresidentialPardonForm::operator=(const PresidentialPardonForm & other)
{
	std::cout << COLORPresidentialPardonForm << "PresidentialPardonForm copy assignment operator called." << RESETPresidentialPardonForm <<std::endl;
	if (this != &other)
	{
		*this = other;
	}
	return *this; 
}

PresidentialPardonForm::~PresidentialPardonForm( void ) // destructor
{
	std::cout << COLORPresidentialPardonForm << "PresidentialPardonForm destructor called." << RESETPresidentialPardonForm << std::endl;
	return ;
}

// Constructor(s)
//PresidentialPardonForm::PresidentialPardonForm(${ARGS_LIST});

// Getters

// Setters

// Comparison operators

// public member functions
// protected  member functions

// private member funcions

// Helper functions for canonicalization
std::string PresidentialPardonForm::canonizeme( void ) const {
	std::string _str_ = "No implemented yet";
	return (_str_);
}


std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& obj)
{
	os << COLORPresidentialPardonForm << "PresidentialPardonForm " << obj.canonizeme()  << RESETPresidentialPardonForm << std::endl;
	return os;
};


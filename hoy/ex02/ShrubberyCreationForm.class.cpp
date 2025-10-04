#include "ShrubberyCreationForm.class.hpp"

//
// ::::::::::::::::::::::::::::Canonical form::::::::::::::::::::::::::::::::
//
ShrubberyCreationForm::ShrubberyCreationForm( void ) //constructor by default
{
	std::cout << "Default constructor called for ShrubberyCreationForm " << std::endl;
	std::cout << COLORShrubberyCreationForm << "ShrubberyCreationForm default constructor called." << RESETShrubberyCreationForm << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) //constructor by copy
{
	std::cout << COLORShrubberyCreationForm << "ShrubberyCreationForm copy constructor called." << RESETShrubberyCreationForm << std::endl;
	*this = other;
	return;
}

ShrubberyCreationForm &  ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other)
{
	std::cout << COLORShrubberyCreationForm << "ShrubberyCreationForm copy assignment operator called." << RESETShrubberyCreationForm <<std::endl;
	if (this != &other)
	{
		*this = other;
	}
	return *this; 
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) // destructor
{
	std::cout << COLORShrubberyCreationForm << "ShrubberyCreationForm destructor called." << RESETShrubberyCreationForm << std::endl;
	return ;
}

// Constructor(s)
//ShrubberyCreationForm::ShrubberyCreationForm(${ARGS_LIST});

// Getters

// Setters

// Comparison operators

// public member functions
// protected  member functions

// private member funcions

// Helper functions for canonicalization
std::string ShrubberyCreationForm::canonizeme( void ) const {
	std::string _str_ = "No implemented yet";
	return (_str_);
}


std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& obj)
{
	os << COLORShrubberyCreationForm << "ShrubberyCreationForm " << obj.canonizeme()  << RESETShrubberyCreationForm << std::endl;
	return os;
};


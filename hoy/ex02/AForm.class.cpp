#include "AForm.class.hpp"

//
// ::::::::::::::::::::::::::::Canonical form::::::::::::::::::::::::::::::::
//
AForm::AForm( void ) //constructor by default
{
	std::cout << "Default constructor called for AForm " << std::endl;
	std::cout << COLORAForm << "AForm default constructor called." << RESETAForm << std::endl;
	return ;
}

AForm::AForm(const AForm& other) //constructor by copy
{
	std::cout << COLORAForm << "AForm copy constructor called." << RESETAForm << std::endl;
	*this = other;
	return;
}

AForm &  AForm::operator=(const AForm & other)
{
	std::cout << COLORAForm << "AForm copy assignment operator called." << RESETAForm <<std::endl;
	if (this != &other)
	{
		*this = other;
	}
	return *this; 
}

AForm::~AForm( void ) // destructor
{
	std::cout << COLORAForm << "AForm destructor called." << RESETAForm << std::endl;
	return ;
}

// Constructor(s)
//AForm::AForm(${ARGS_LIST});

// Getters

// Setters

// Comparison operators

// public member functions
// protected  member functions

// private member funcions

// Helper functions for canonicalization
std::string AForm::canonizeme( void ) const {
	std::string _str_ = "No implemented yet";
	return (_str_);
}


std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	os << COLORAForm << "AForm " << obj.canonizeme()  << RESETAForm << std::endl;
	return os;
};


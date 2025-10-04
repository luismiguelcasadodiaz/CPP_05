#include "Form.class.hpp"

//
// ::::::::::::::::::::::::::::Canonical form::::::::::::::::::::::::::::::::
//
Form::Form( void ) //constructor by default
{
	std::cout << "Default constructor called for Form " << std::endl;
	std::cout << COLORForm << "Form default constructor called." << RESETForm << std::endl;
	return ;
}

Form::Form(const Form& other) //constructor by copy
{
	std::cout << COLORForm << "Form copy constructor called." << RESETForm << std::endl;
	*this = other;
	return;
}

Form &  Form::operator=(const Form & other)
{
	std::cout << COLORForm << "Form copy assignment operator called." << RESETForm <<std::endl;
	if (this != &other)
	{
		*this = other;
	}
	return *this; 
}

Form::~Form( void ) // destructor
{
	std::cout << COLORForm << "Form destructor called." << RESETForm << std::endl;
	return ;
}

// Constructor(s)
//Form::Form(${ARGS_LIST});

// Getters

// Setters

// Comparison operators

// public member functions
// protected  member functions

// private member funcions

// Helper functions for canonicalization
std::string Form::canonizeme( void ) const {
	std::string _str_ = "No implemented yet";
	return (_str_);
}


std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << COLORForm << "Form " << obj.canonizeme()  << RESETForm << std::endl;
	return os;
};


#include "Intern.class.hpp"

//
// ::::::::::::::::::::::::::::Canonical form::::::::::::::::::::::::::::::::
//
Intern::Intern( void ) //constructor by default
{
	std::cout << "Default constructor called for Intern " << std::endl;
	std::cout << COLORIntern << "Intern default constructor called." << RESETIntern << std::endl;
	return ;
}

Intern::Intern(const Intern& other) //constructor by copy
{
	std::cout << COLORIntern << "Intern copy constructor called." << RESETIntern << std::endl;
	*this = other;
	return;
}

Intern &  Intern::operator=(const Intern & other)
{
	std::cout << COLORIntern << "Intern copy assignment operator called." << RESETIntern <<std::endl;
	if (this != &other)
	{
		*this = other;
	}
	return *this; 
}

Intern::~Intern( void ) // destructor
{
	std::cout << COLORIntern << "Intern destructor called." << RESETIntern << std::endl;
	return ;
}

// Constructor(s)
//Intern::Intern(${ARGS_LIST});

// Getters

// Setters

// Comparison operators

// public member functions
// protected  member functions

// private member funcions

// Helper functions for canonicalization
std::string Intern::canonizeme( void ) const {
	std::string _str_ = "No implemented yet";
	return (_str_);
}


std::ostream& operator<<(std::ostream& os, const Intern& obj)
{
	os << COLORIntern << "Intern " << obj.canonizeme()  << RESETIntern << std::endl;
	return os;
};


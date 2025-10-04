#include "RobotomyRequestForm.class.hpp"

//
// ::::::::::::::::::::::::::::Canonical form::::::::::::::::::::::::::::::::
//
RobotomyRequestForm::RobotomyRequestForm( void ) //constructor by default
{
	std::cout << "Default constructor called for RobotomyRequestForm " << std::endl;
	std::cout << COLORRobotomyRequestForm << "RobotomyRequestForm default constructor called." << RESETRobotomyRequestForm << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) //constructor by copy
{
	std::cout << COLORRobotomyRequestForm << "RobotomyRequestForm copy constructor called." << RESETRobotomyRequestForm << std::endl;
	*this = other;
	return;
}

RobotomyRequestForm &  RobotomyRequestForm::operator=(const RobotomyRequestForm & other)
{
	std::cout << COLORRobotomyRequestForm << "RobotomyRequestForm copy assignment operator called." << RESETRobotomyRequestForm <<std::endl;
	if (this != &other)
	{
		*this = other;
	}
	return *this; 
}

RobotomyRequestForm::~RobotomyRequestForm( void ) // destructor
{
	std::cout << COLORRobotomyRequestForm << "RobotomyRequestForm destructor called." << RESETRobotomyRequestForm << std::endl;
	return ;
}

// Constructor(s)
//RobotomyRequestForm::RobotomyRequestForm(${ARGS_LIST});

// Getters

// Setters

// Comparison operators

// public member functions
// protected  member functions

// private member funcions

// Helper functions for canonicalization
std::string RobotomyRequestForm::canonizeme( void ) const {
	std::string _str_ = "No implemented yet";
	return (_str_);
}


std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& obj)
{
	os << COLORRobotomyRequestForm << "RobotomyRequestForm " << obj.canonizeme()  << RESETRobotomyRequestForm << std::endl;
	return os;
};


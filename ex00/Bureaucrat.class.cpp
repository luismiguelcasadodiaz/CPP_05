#include "Bureaucrat.class.hpp"

//
// ::::::::::::::::::::::::::::Canonical form::::::::::::::::::::::::::::::::
//
Bureaucrat::Bureaucrat( void ) //constructor by default
{
	std::cout << "Default constructor called for Bureaucrat " << std::endl;
	std::cout << COLORBureaucrat << "Bureaucrat default constructor called." << RESETBureaucrat << std::endl;
	thisreturn ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) //constructor by copy
{
	std::cout << COLORBureaucrat << "Bureaucrat copy constructor called." << RESETBureaucrat << std::endl;
	*this = other;
	return;
}

Bureaucrat &  Bureaucrat::operator=(const Bureaucrat & other)
{
	std::cout << COLORBureaucrat << "Bureaucrat copy assignment operator called." << RESETBureaucrat <<std::endl;
	if (this != &other)
	{
		*this = other;
	}
	return *this; 
}

Bureaucrat::~Bureaucrat( void ) // destructor
{
	std::cout << COLORBureaucrat << "Bureaucrat destructor called." << RESETBureaucrat << std::endl;
	return ;
}

// Constructor(s)
//Bureaucrat::Bureaucrat(${ARGS_LIST});

// Getters
const std::string Bureaucrat::getName() const {
	return this->_name ;
}

std::size_t Bureaucrat::getGrade() const {
	return this->_grade ;
}

// Setters

void Bureaucrat::setName(const std::string & thename) {
	this->_name = thename ;
}

void Bureaucrat::setGrade(const std::size_t & thegrade) {
	if ( (_highest <= thegrade) && (thegrade <=  _highest) )
	{
		this->_grade = thegrade ;
	}
	else 
}
// Comparison operators

// public member functions

void upGrade() {
	
}

// protected  member functions

// private member funcions

// Helper functions for canonicalization
std::string Bureaucrat::canonizeme( void ) const {
	std::string _str_ = 
	return (_str_);
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << COLORBureaucrat << "Bureaucrat " << obj.canonizeme()  << RESETBureaucrat << std::endl;
	return os;
};


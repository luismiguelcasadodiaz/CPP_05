#include "Bureaucrat.class.hpp"

//
// ::::::::::::::::::::::::::::Canonical form::::::::::::::::::::::::::::::::
//
Bureaucrat::Bureaucrat( void ): _name( "noname" ), _grade( 150 ) //constructor by default
{
	std::cout << COLORBureaucrat << "Bureaucrat default constructor called." << RESETBureaucrat << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)://constructor by copy
	_name(other._name) , _grade(other._grade)
{
	std::cout << COLORBureaucrat << "Bureaucrat copy constructor called." << RESETBureaucrat << std::endl;
}

Bureaucrat &  Bureaucrat::operator=(const Bureaucrat & other)
{
	std::cout << COLORBureaucrat << "Bureaucrat copy assignment operator called." << RESETBureaucrat <<std::endl;
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this; 
}

Bureaucrat::~Bureaucrat( void ) // destructor
{
	std::cout << COLORBureaucrat << "Bureaucrat destructor called." << RESETBureaucrat << std::endl;
	return ;
}

// Constructor(s)
Bureaucrat::Bureaucrat( const std::string & thename, int thegrade ): 
	_name(thename), _grade(thegrade) //constructor by default
{
	std::cout << COLORBureaucrat << "Bureaucrat list constructor called." << RESETBureaucrat << std::endl;
	if ( _grade < Bureaucrat::_highest ) {throw Bureaucrat::GradeTooHighException() ; }
	else if ( Bureaucrat::_lowest < _grade ){ throw Bureaucrat::GradeTooLowException() ; }
}

// Getters
const std::string Bureaucrat::getName() const {
	return this->_name ;
}

int Bureaucrat::getGrade() const {
	return this->_grade ;
}

// Setters


void Bureaucrat::setGrade(const int & thegrade) {
	if ( (_highest <= thegrade) && (thegrade <=  _lowest) )
	{
		this->_grade = thegrade ;
		return ;
	}
	if (thegrade < _highest) {throw GradeTooHighException() ; }
	else { throw GradeTooLowException() ; }
}
// Comparison operators

// public member functions

void Bureaucrat::upGrade() {
	if (Bureaucrat::_highest < _grade )
	{ _grade -= 1 ; }
	else { throw GradeTooHighException() ;}	
}

void Bureaucrat::downGrade(){
	if ( _grade < Bureaucrat::_lowest )
	{ _grade += 1 ; }
	else { throw GradeTooLowException() ;}	
}

// protected  member functions

// private member funcions

// Helper functions for canonicalization
std::string Bureaucrat::canonizeme( void ) const {
	std::stringstream  _str_ ;
	_str_ << _name << ", Bureaucrat with grade " << _grade << "." ;
	return _str_.str();
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << COLORBureaucrat << "Bureaucrat " << obj.canonizeme()  << RESETBureaucrat << std::endl;
	return os;
};


#include "Contact.class.hpp"

//
// ::::::::::::::::::::::::::::Canonical form::::::::::::::::::::::::::::::::
//
Contact::Contact( void ) //constructor by default
{
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
std::string Contact::get_first( void ) const
{
	return this->first;
} 
std::string Contact::get_last( void ) const
{
	return this->last;
} 
std::string Contact::get_nick( void ) const
{
	return this->nick;
} 
std::string Contact::get_number( void ) const
{
	return this->number;
} 
std::string Contact::get_secret( void ) const
{
	return this->secret;
} 
// Setters
void Contact::set_first ( std::string the_first)
{
	this->first = the_first;
}
void Contact::set_last ( std::string the_last)
{
	this->last = the_last;
}
void Contact::set_nick ( std::string the_nick)
{
	this->nick = the_nick;
}
void Contact::set_number ( std::string the_number)
{
	this->number = the_number;
}
void Contact::set_secret ( std::string the_secret)
{
	this->secret = the_secret;
}


// Comparison operators

// public member functions
// protected  member functions

// private member funcions

// Helper functions for canonicalization
std::string Contact::canonizeme( void ) const {
	std::string _str_ = this->get_last() + ", " + this->get_first();
	_str_ = _str_ + " alias " + this->get_nick() + " has the number " +this->get_number() ;
	return (_str_);
}


std::ostream& operator<<(std::ostream& os, const Contact& obj)
{
	os << COLORContact << "Contact " << obj.canonizeme()  << RESETContact << std::endl;
	return os;
};


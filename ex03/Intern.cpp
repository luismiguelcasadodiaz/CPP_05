#include "Intern.hpp"

Intern::form  Intern::forms[] = { 
	{"Shrubbery creation", &Intern::ShrubberyFormCreator },
	{"Robotomy request", &Intern::RobotomyyFormCreator },
	{"Presidential pardon", &Intern::PresidentFormCreator}
};
const size_t Intern::num_forms = sizeof(Intern::forms) / sizeof(Intern::form) ;

AForm * Intern::ShrubberyFormCreator(const std::string & target)
{
	return new ShrubberyCreationForm( target ) ;
}

AForm * Intern::RobotomyyFormCreator(const std::string & target)
{
	return new RobotomyRequestForm( target ) ;
}

AForm * Intern::PresidentFormCreator(const std::string & target)
{
	return new PresidentialPardonForm( target ) ;
}

Intern::Intern ( void )
{
	std::cout << COLORIntern << "Intern default constructor called." << RESETForm << std::endl;
}
Intern::~Intern ( void )
{
	std::cout << COLORIntern << "Intern default destructor called." << RESETForm << std::endl;
}
Intern::Intern ( const Intern & other )
{
	std::cout << COLORIntern << "Intern copy constructor called." << RESETForm << std::endl;
	(void)other;
}
Intern &Intern::operator=( const Intern & other )
{
	std::cout << COLORIntern << "Intern assignation constructor called." << RESETForm << std::endl;
	(void)other;
	return *this ;
}
AForm * Intern::makeForm(const std::string & formName, const std::string & _target)
{
	if ( formName == "" ) { return NULL;}
	size_t i = 0 ;
	bool found = false ;
	while ( ( !found ) && ( i < Intern::num_forms ) )
	{
		if ( forms[i].formName == formName )
		{
			std::cout << COLORIntern << "Intern creates >" << forms[i].formName ;
			std::cout << "<form ." << RESETForm << std::endl;
			return  forms[i].formCreator( _target ) ;
		}
		i++ ;
	}
	return NULL ;
}


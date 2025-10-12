#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm ( void ) : 
	AForm("PresidentialPardonForm", 5, 25), _target("no target")
{
	std::cout << COLORPardon << "PresidentialPardonForm default constructor called." << RESETForm << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm ( std::string thetarget ) : 
	AForm("PresidentialPardonForm", 5, 25), _target( thetarget )
{
	std::cout << COLORPardon << "PresidentialPardonForm list constructor called." << RESETForm << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & other) :
	AForm(other.getName(), other.getExecGrade(), other.getSignGrade()),
	_target(other._target)
{
	std::cout << COLORPardon << "PresidentialPardonForm copy constructor called." << RESETForm << std::endl;
	AForm::setSigned( other.isSigned() );
}
PresidentialPardonForm & PresidentialPardonForm::operator=( const PresidentialPardonForm & other)
{
	std::cout << COLORPardon << "PresidentialPardonForm assination constructor called." << RESETForm << std::endl;
	if (this != &other)
	{
		AForm::operator=(other) ;
		this->_target = other._target ;
	}
	return *this ;
}
void PresidentialPardonForm::execute( const Bureaucrat & b) const
{
	int b_grade = b.getGrade() ;
	int f_grade = this->getExecGrade() ;
	if (!this->isSigned())
	{ 
		std::cout << COLORPardon << this->getName()<< " for " << this->_target ;
		std::cout << " unsigned. Sign it before execution." << RESETForm << std::endl;
		return ; 
	}
	if ( f_grade < b_grade )
	{
		throw( AForm::execGradeTooLowException(	this->getName(),
												this->_target,
												f_grade,
												b_grade) );
	}
	std::cout << COLORPardon << _target << " Has been pardoned by Zaphod Beeblebrox." << RESETForm << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm ( void )
{
	std::cout << COLORPardon << "PresidentialPardonForm destructor called." << RESETForm << std::endl;
}
const std::string & PresidentialPardonForm::getTarget( void ) const
{
	return this->_target ;
}

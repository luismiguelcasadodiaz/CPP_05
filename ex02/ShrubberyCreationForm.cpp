#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm ( void ) : 
	AForm("ShrubberyCreationForm", 45, 72),
	_target("no target"),
	_executions(0)
{
	std::cout << COLORShrubb << "ShrubberyCreationForm default constructor called." << RESETForm << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm ( std::string thetarget ) : 
	AForm("ShrubberyCreationForm", 45, 72), 
	_target( thetarget ),
	_executions(0)
{
	std::cout << COLORShrubb << "ShrubberyCreationForm list constructor called." << RESETForm << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & other) :
	AForm(other.getName(), other.getExecGrade(), other.getSignGrade()),
	_target(other._target), _executions(other._executions)
{
	std::cout << COLORShrubb << "ShrubberyCreationForm copy constructor called." << RESETForm << std::endl;
	AForm::setSigned( other.isSigned() );
}
ShrubberyCreationForm & ShrubberyCreationForm::operator=( const ShrubberyCreationForm & other)
{
	std::cout << COLORShrubb << "ShrubberyCreationForm assination constructor called." << RESETForm << std::endl;
	if (this != &other)
	{
		AForm::operator=(other) ;
		this->_target = other._target ;
		this->_executions = other._executions ;
	} 
	return *this ;
}
void ShrubberyCreationForm::execute( const Bureaucrat & b)
{
	int b_grade = b.getGrade() ;
	int f_grade = this->getExecGrade() ;
	if (!this->isSigned())
	{ 
		std::cout << COLORShrubb << this->getName()<< " for " << this->_target ;
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
	std::cout << COLORShrubb << "Robotomy drilling noise. " ;
	if ((this->_executions % 2 ) == 0 )
	{
		std::cout << _target << " has been robotomized sucessfully." ;
	}
	else
	{
		std::cout << _target << " robotomization failed." ;
	}
	std::cout << RESETForm << std::endl ;
	this->_executions++ ;
}
ShrubberyCreationForm::~ShrubberyCreationForm ( void )
{
	std::cout << COLORShrubb << "ShrubberyCreationForm destructor called." << RESETForm << std::endl;
}
const std::string & ShrubberyCreationForm::getTarget( void ) const
{
	return this->_target ;
}

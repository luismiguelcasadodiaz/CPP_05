
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm ( void ) : 
	AForm("RobotomyRequestForm", 45, 72),
	_target("no target"),
	_executions(0)
{
	std::cout << COLORRobotomy << "RobotomyRequestForm default constructor called." << RESETForm << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm ( std::string thetarget ) : 
	AForm("RobotomyRequestForm", 45, 72), 
	_target( thetarget ),
	_executions(0)
{
	std::cout << COLORRobotomy << "RobotomyRequestForm list constructor called." << RESETForm << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & other) :
	AForm(other.getName(), other.getExecGrade(), other.getSignGrade()),
	_target(other._target), _executions(other._executions)
{
	std::cout << COLORRobotomy << "RobotomyRequestForm copy constructor called." << RESETForm << std::endl;
	AForm::setSigned( other.isSigned() );
}
RobotomyRequestForm & RobotomyRequestForm::operator=( const RobotomyRequestForm & other)
{
	std::cout << COLORRobotomy << "RobotomyRequestForm assination constructor called." << RESETForm << std::endl;
	if (this != &other)
	{
		AForm::operator=(other) ;
		this->_target = other._target ;
		this->_executions = other._executions ;
	} 
	return *this ;
}
void RobotomyRequestForm::execute( const Bureaucrat & b)
{
	int b_grade = b.getGrade() ;
	int f_grade = this->getExecGrade() ;
	if (!this->isSigned())
	{ 
		std::cout << COLORRobotomy << this->getName()<< " for " << this->_target ;
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
	std::cout << COLORRobotomy << "Robotomy drilling noise. " ;
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
RobotomyRequestForm::~RobotomyRequestForm ( void )
{
	std::cout << COLORRobotomy << "RobotomyRequestForm destructor called." << RESETForm << std::endl;
}
const std::string & RobotomyRequestForm::getTarget( void ) const
{
	return this->_target ;
}

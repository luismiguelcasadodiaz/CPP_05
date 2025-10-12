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
		throw( AForm::GradeTooLowException() );
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
// Exception GradeException

PresidentialPardonForm::GradeException::GradeException ( void ) :
	_formName("No name"), _action("No action"), _minGrade(0), _curGrade(0)
{
	std::cout << COLORFormGradeEXEC << "PresidentialPardonForm::GradeException default constructor called." << RESETForm << std::endl;
}
PresidentialPardonForm::GradeException::~GradeException ( void ) throw()
{
	std::cout << COLORFormGradeEXEC << "PresidentialPardonForm::GradeException default destructor called." << RESETForm << std::endl;
}
PresidentialPardonForm::GradeException::GradeException (
		const std::string & name,
		const std::string & target,
		const std::string & action,
		int required_g,
		int actual_g):
	_formName(name), _target(target),_action(action), 
	_minGrade(required_g), _curGrade(actual_g)
{
	std::cout << COLORFormGradeEXEC << "PresidentialPardonForm::GradeException list constructor called." << RESETForm << std::endl;
	std::stringstream ss ;
	ss << _formName << " for "  << _target ;
	ss << " requires a minimun grade of " << _minGrade << " for " << _action ;
	ss << ", but bureaucrat has only grade " << _curGrade << "."  << std::endl ;
	_msg = ss.str();
}
PresidentialPardonForm::GradeException::GradeException ( const GradeException & other ) :
	_formName(other._formName), _target(other._target),_action(other._action),
	_minGrade(other._minGrade), _curGrade(other._curGrade), _msg(other._msg)
{
	std::cout << COLORFormGradeEXEC << "PresidentialPardonForm::GradeException copy constructor called." << RESETForm << std::endl;
}
PresidentialPardonForm::GradeException & PresidentialPardonForm::GradeException::operator= ( const GradeException & other ) 
{
	std::cout << COLORFormGradeEXEC << "PresidentialPardonForm::GradeException Assingnation constructor called." << RESETForm << std::endl;
	if (this != &other)
	{
		this->_formName = other._formName;
		this->_target = other._target ;
		this->_action = other._action ;
		this->_minGrade = other._minGrade ;
		this->_curGrade = other._curGrade ;
		this->_msg = other._msg ;
	}
	return *this;
}
const char * PresidentialPardonForm::GradeException::what() const throw()
{
	return this->_msg.c_str();
}

// Exception execGradeTooLowException

PresidentialPardonForm::execGradeTooLowException::execGradeTooLowException (
		std::string & formName,
		std::string & formTarget,
		int required_g,
		int actual_g ) : 
	GradeException(formName, formTarget, "Execution", required_g, actual_g)
{
	std::cout << COLORFormGradeEXEC << "PresidentialPardonForm::execGradeTooLowException default  constructor called." << RESETForm << std::endl;
}
PresidentialPardonForm::execGradeTooLowException::~execGradeTooLowException ( void ) throw ()
{
	std::cout << COLORFormGradeEXEC << "PresidentialPardonForm::execGradeTooLowException default  destructor called." << RESETForm << std::endl;
}
/*
const char * PresidentialPardonForm::execGradeTooLowException::what() const throw()
{
	return this->_msg.c_str();
}
*/

// Exception signGradeTooLowException

PresidentialPardonForm::signGradeTooLowException::signGradeTooLowException (
		std::string & formName,
		std::string & formTarget,
		int required_g,
		int actual_g ) : 
	GradeException(formName, formTarget, "signature", required_g, actual_g)
{
	std::cout << COLORFormGradeEXEC << "PresidentialPardonForm::signGradeTooLowException default  constructor called." << RESETForm << std::endl;
}
PresidentialPardonForm::signGradeTooLowException::~signGradeTooLowException ( void ) throw()
{
	std::cout << COLORFormGradeEXEC << "PresidentialPardonForm::signGradeTooLowException default  destructor called." << RESETForm << std::endl;
}
/*
const char * PresidentialPardonForm::signGradeTooLowException::what() const throw()
{
	return this->_msg.c_str();
}
*/

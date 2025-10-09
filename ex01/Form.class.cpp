#include "Form.class.hpp"

Form::Form ( void ) : _name( "no name" ), _e_grade( 0 ), _s_grade( 0 )
{
	std::cout << COLORForm << "Form default constructor called." << RESETForm << std::endl;
}

Form::~Form ( void )
{
	std::cout << COLORForm << "Form default destructo called." << RESETForm << std::endl;
}

Form::Form( const Form & other ) :
	_name( other._name), 
	_e_grade( other._e_grade ),
	_s_grade(other._s_grade ),
	_signed( other._signed )

{
	std::cout << COLORForm << "Form copy constructor called." << RESETForm << std::endl;
}
Form & Form::operator=( const Form & other )
{
	std::cout << COLORForm << "Form assignation constructor called." << RESETForm << std::endl;
	if ( this != &other )
	{
		//this->_e_grade = other._e_grade ; 
		//this->_s_grade = other._s_grade ;
		this->_signed = other._signed ;
	}
	return *this;
}
Form::Form (const std::string & thename, const int & e, const int & s) :
			_name( thename ),
			_e_grade( e ), 
			_s_grade( s ),
			_signed( false )
{
	std::cout << COLORForm << "Form list  constructor called." << RESETForm << std::endl;
}
void Form::beSigned( const Bureaucrat & b )
{
	if (this->_s_grade < b.getGrade() )
	{
		this->_signed = true ;
		throw( Form::GradeTooLowException() );
	}
	this->_signed = true ;
}

const std::string & Form::getName( void ) const 
{
	return this->_name ;
}
int Form::getExecGrade( void ) const 
{
	return this->_e_grade ;
}
int Form::getSignGrade( void ) const 
{
	return this->_s_grade ;
}
bool Form::isSigned( void ) const 
{
	return this->_signed ;
}

Form::GradeException::GradeException( void ) : 
	_adjective( "" ), _limit( 0 ) 
{
	std::cout << COLORFormGradeE << "Form::GradeException default  constructor called." << RESETForm << std::endl;
}
Form::GradeException::GradeException( const std::string & adj, const int lim ) : 
	_adjective( adj ), _limit( lim ) 
{
	std::cout << COLORFormGradeE << "Form::GradeException list  constructor called." << RESETForm << std::endl;
}
Form::GradeException::GradeException( const GradeException & other ) :
	_adjective(other._adjective), _limit( other._limit)
{
	std::cout << COLORFormGradeE << "Form::GradeException copy constructor called." << RESETForm << std::endl;
}
Form::GradeException & Form::GradeException::operator=(const GradeException & other) 
{
	std::cout << COLORFormGradeE << "Form::GradeException Assignation constructor called." << RESETForm << std::endl;
	(void)other;
	return *this;
}
Form::GradeException::~GradeException ( void ) throw () 
{
	std::cout << COLORFormGradeE << "Form::GradeException destructor called." << RESETForm << std::endl;
}
const char * Form::GradeException::what() const throw ()
{
	std::stringstream ss;
	ss << this->_adjective << " Form grade is Grade= " << this->_limit << "." ;
	return ss.str().c_str();
}


// GradeTooLowException
  
Form::GradeTooLowException::GradeTooLowException(void) : GradeException("Minimum", 150)
{
	std::cout << COLORFormGradeTLE << "Form::GradeTooLowException default  constructor called." << RESETForm << std::endl;
}
Form::GradeTooLowException::GradeTooLowException( const GradeTooLowException & other) : GradeException( other )
{
	std::cout << COLORFormGradeTLE << "Form::GradeTooLowException copy  constructor called." << RESETForm << std::endl;
}
Form::GradeTooLowException & Form::GradeTooLowException::operator=( const GradeTooLowException & other )
{
	std::cout << COLORFormGradeTLE << "Form::GradeTooLowException Assignation  constructor called." << RESETForm << std::endl;
	if (this != &other)
		GradeException::operator=(other) ;
	return *this ; 
}
Form::GradeTooLowException::~GradeTooLowException( void ) throw()
{
	std::cout << COLORFormGradeTLE << "Form::GradeTooLowException destructor called." << RESETForm << std::endl;
}
// GradeTooHighException
  
Form::GradeTooHighException::GradeTooHighException(void) : GradeException("Minimum", 150)
{
	std::cout << COLORFormGradeTLE << "Form::GradeTooHighException default  constructor called." << RESETForm << std::endl;
}
Form::GradeTooHighException::GradeTooHighException( const GradeTooHighException & other) : GradeException( other )
{
	std::cout << COLORFormGradeTLE << "Form::GradeTooHighException copy  constructor called." << RESETForm << std::endl;
}
Form::GradeTooHighException & Form::GradeTooHighException::operator=( const GradeTooHighException & other )
{
	std::cout << COLORFormGradeTLE << "Form::GradeTooHighException Assignation  constructor called." << RESETForm << std::endl;
	if (this != &other)
		GradeException::operator=(other) ;
	return *this ; 
}
Form::GradeTooHighException::~GradeTooHighException( void ) throw()
{
	std::cout << COLORFormGradeTLE << "Form::GradeTooHighException destructor called." << RESETForm << std::endl;
}

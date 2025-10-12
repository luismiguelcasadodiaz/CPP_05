#include "AForm.hpp"

AForm::AForm ( void ) : 
	_name( "no name" ), 
	_e_grade( 0 ), 
	_s_grade( 0 ), 
	_signed(false)
{
	std::cout << COLORForm << "AForm default constructor called." << RESETForm << std::endl;
}

AForm::~AForm ( void )
{
	std::cout << COLORForm << "AForm default destructor called." << RESETForm << std::endl;
}

AForm::AForm( const AForm & other ) :
	_name( other._name), 
	_e_grade( other._e_grade ),
	_s_grade( other._s_grade ),
	_signed( other._signed )

{
	std::cout << COLORForm << "AForm copy constructor called." << RESETForm << std::endl;
	
}
AForm & AForm::operator=( const AForm & other )
{
	std::cout << COLORForm << "AForm assignation constructor called." << RESETForm << std::endl;
	if ( this != &other )
	{
		//this->_e_grade = other._e_grade ; 
		//this->_s_grade = other._s_grade ;
		this->_signed = other._signed ;
	}
	return *this;
}
AForm::AForm (const std::string & thename, const int & e, const int & s) :
			_name( thename ),
			_e_grade( e ), 
			_s_grade( s ),
			_signed( false )
{
	std::cout << COLORForm << "AForm list  constructor called." << RESETForm << std::endl;
	if ( ( _e_grade < AForm::_highest ) || ( _s_grade < AForm::_highest ) )
	{throw AForm::GradeTooHighException() ;}
	else if ( ( AForm::_lowest < _e_grade ) || ( AForm::_lowest < _s_grade ) )
	{throw AForm::GradeTooLowException() ;}
}
void AForm::beSigned( const Bureaucrat & b )
{
	if (this->_signed)
	{ return ; }
	if (this->_s_grade < b.getGrade() )
	{
		throw( AForm::GradeTooLowException() );
	}
	this->_signed = true ;
}

const std::string & AForm::getName( void ) const 
{
	return this->_name ;
}
int AForm::getExecGrade( void ) const 
{
	return this->_e_grade ;
}
int AForm::getSignGrade( void ) const 
{
	return this->_s_grade ;
}
bool AForm::isSigned( void ) const 
{
	return this->_signed ;
}
void AForm::setSigned(bool state)
{
	this->_signed = state ;
}
const std::string AForm::canonizeme( void ) const
{
	std::stringstream _str_ ;
	_str_ << "AForm " << _name << " [exec=" << _e_grade << ", sign="<< _s_grade <<"] is " ;
	if ( _signed ){ _str_ << "SIGNED." ;} else { _str_ << "NOT SIGNED." ;}
	return _str_.str() ;
	
}
std::ostream & operator<<(std::ostream & os, const AForm & obj)
{
	os << COLORForm << obj.canonizeme()  << RESETForm << std::endl;
	return os ;
}
AForm::GradeException::GradeException( void ) : 
	_adjective( "" ), _limit( 0 ), _text() 
{
	std::stringstream ss;
	ss << this->_adjective << " AForm grade is Grade= " << this->_limit << "." ;
	this->_text = ss.str() ;
}
AForm::GradeException::GradeException( const std::string & adj, const int lim ) : 
	_adjective( adj ), _limit( lim ), _text() 
{
	std::cout << COLORFormGradeE << "AForm::GradeException list  constructor called." << RESETForm << std::endl;
	std::stringstream ss;
	ss << this->_adjective << " AForm grade is Grade= " << this->_limit << "." ;
	this->_text = ss.str() ;
}
AForm::GradeException::GradeException( const GradeException & other ) :
	_adjective(other._adjective), _limit( other._limit), _text( other._text)
{
	std::cout << COLORFormGradeE << "AForm::GradeException copy constructor called." << RESETForm << std::endl;
}
AForm::GradeException & AForm::GradeException::operator=(const GradeException & other) 
{
	std::cout << COLORFormGradeE << "AForm::GradeException Assignation constructor called." << RESETForm << std::endl;
	(void)other;
	return *this;
}
AForm::GradeException::~GradeException ( void ) throw () 
{
	std::cout << COLORFormGradeE << "AForm::GradeException destructor called." << RESETForm << std::endl;
}
const char * AForm::GradeException::what() const throw ()
{
	return this->_text.c_str();
}


// GradeTooLowException
  
AForm::GradeTooLowException::GradeTooLowException(void) : GradeException("Minimum", 150)
{
	std::cout << COLORFormGradeTLE << "AForm::GradeTooLowException default  constructor called." << RESETForm << std::endl;
}
AForm::GradeTooLowException::GradeTooLowException( const GradeTooLowException & other) : GradeException( other )
{
	std::cout << COLORFormGradeTLE << "AForm::GradeTooLowException copy  constructor called." << RESETForm << std::endl;
}
AForm::GradeTooLowException & AForm::GradeTooLowException::operator=( const GradeTooLowException & other )
{
	std::cout << COLORFormGradeTLE << "AForm::GradeTooLowException Assignation  constructor called." << RESETForm << std::endl;
	if (this != &other)
		GradeException::operator=(other) ;
	return *this ; 
}
AForm::GradeTooLowException::~GradeTooLowException( void ) throw()
{
	std::cout << COLORFormGradeTLE << "AForm::GradeTooLowException destructor called." << RESETForm << std::endl;
}
// GradeTooHighException
  
AForm::GradeTooHighException::GradeTooHighException(void) : GradeException("Minimum", 150)
{
	std::cout << COLORFormGradeTLE << "AForm::GradeTooHighException default  constructor called." << RESETForm << std::endl;
}
AForm::GradeTooHighException::GradeTooHighException( const GradeTooHighException & other) : GradeException( other )
{
	std::cout << COLORFormGradeTLE << "AForm::GradeTooHighException copy  constructor called." << RESETForm << std::endl;
}
AForm::GradeTooHighException & AForm::GradeTooHighException::operator=( const GradeTooHighException & other )
{
	std::cout << COLORFormGradeTLE << "AForm::GradeTooHighException Assignation  constructor called." << RESETForm << std::endl;
	if (this != &other)
		GradeException::operator=(other) ;
	return *this ; 
}
AForm::GradeTooHighException::~GradeTooHighException( void ) throw()
{
	std::cout << COLORFormGradeTLE << "AForm::GradeTooHighException destructor called." << RESETForm << std::endl;
}

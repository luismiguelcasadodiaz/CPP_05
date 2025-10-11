#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void Bureaucrat::signForm( Form & f)
{
	if ( f.isSigned() )
	{
		std::cout << this->_name << " couldn't sign " << f.getName() ;
		std::cout << "Because it is already signed." <<std::endl ;
		return ;
	}
	int form_grade = f.getSignGrade() ;
	int bure_grade = this->getGrade() ;
	if ( form_grade < bure_grade )
	{
		std::cout << this->_name << " couldn't sign " << f.getName() ;
		std::cout << "Because my grade " << bure_grade << "can not sign " ;
		std::cout << "forms of grade " << form_grade << "." <<std::endl ;
		return ;
	}
	f.beSigned( *this ) ;
	if ( f.isSigned() )
	{
		std::cout << this->_name << " signed " << f.getName() << "." <<std::endl ;
	}
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

//======================================================================//
//                          class GradeException                        //
//======================================================================//
// class GradeException default constructor
Bureaucrat::GradeException::GradeException( void )
	:_adjective(""), 
	_limit(0)
{
	std::cout << COLORBureaucratGradeE << "Bureaucrat::GradeException default constructor called." << RESETBureaucrat << std::endl;
}
// class GradeException default destructor

Bureaucrat::GradeException::~GradeException( void ) throw ()
{
	std::cout << COLORBureaucratGradeE << "Bureaucrat::GradeException default destructor called." << RESETBureaucrat << std::endl;
}
// class GradeException copy constructor
Bureaucrat::GradeException::GradeException (
	const GradeException & other):
	_adjective(other._adjective), 
	_limit(other._limit),
	_msg()
{
	std::cout << COLORBureaucratGradeE << "Bureaucrat::GradeException copy constructor called." << RESETBureaucrat << std::endl;
	std::stringstream ss ;
	ss << _adjective << " grade is Grade=" << _limit << "." ;
	_msg = ss.str() ; 
}

// class GradeException list constructor
Bureaucrat::GradeException::GradeException( 
	const std::string & adjective,
	std::size_t limit ) : 
	_adjective(adjective), 
	_limit(limit),
	_msg()
{
	std::cout << COLORBureaucratGradeE << "Bureaucrat::GradeException list constructor called." << RESETBureaucrat << std::endl;
	std::stringstream ss ;
	ss << _adjective << " grade is Grade=" << _limit << "." ;
	_msg = ss.str() ; 
}

const char * Bureaucrat::GradeException::what() const throw () 
{
	return _msg.c_str(); 
} 
// class GradeException assgnation constructor
Bureaucrat::GradeException & Bureaucrat::GradeException::operator=(
	const GradeException & other)
{
	std::cout << COLORBureaucratGradeE << "Bureaucrat::GradeException assignation constructor called." << RESETBureaucrat << std::endl;
	(void)other;
	return *this;
}
//======================================================================//
//                    class GradeTooHighException                       //
//======================================================================//
// class GradeTooHighException default constructor
Bureaucrat::GradeTooHighException::GradeTooHighException()
	: GradeException("Maximun", 1)
{
	std::cout << COLORBureaucratGradeETH << "Bureaucrat::GradeTooHighException default constructor called." << RESETBureaucrat << std::endl;
}
// class GradeTooHighException copy constructor
Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException & other)
	: GradeException( other )
{
	std::cout << COLORBureaucratGradeETH << "Bureaucrat::GradeTooHighException copy constructor called." << RESETBureaucrat << std::endl;
}
// class GradeTooHighException asignation copy constructor
Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator=(const GradeTooHighException& other)
{
	std::cout << COLORBureaucratGradeETH << "Bureaucrat::GradeTooHighException assignation  constructor called." << RESETBureaucrat << std::endl;
	if (this != & other)
		GradeException::operator=(other);
	return *this ;
};
// class GradeTooHighException default destructor
Bureaucrat::GradeTooHighException::~GradeTooHighException( void ) throw()
{
	std::cout << COLORBureaucratGradeETH << "Bureaucrat::GradeTooHighException default destructor called." << RESETBureaucrat << std::endl;
} ;
//======================================================================//
//                    class GradeTooLowException                       //
//======================================================================//
// class GradeTooLowException default constructor
Bureaucrat::GradeTooLowException::GradeTooLowException()
	: GradeException("Maximun", 150)
{
	std::cout << COLORBureaucratGradeETL << "Bureaucrat::GradeTooLowException default constructor called." << RESETBureaucrat << std::endl;
}
// class GradeTooLowException copy constructor
Bureaucrat::GradeTooLowException::GradeTooLowException(const GradeTooLowException & other)
	: GradeException( other )
{
	std::cout << COLORBureaucratGradeETL << "Bureaucrat::GradeTooLowException copy constructor called." << RESETBureaucrat << std::endl;
}
// class GradeTooLowException asignation copy constructor
Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator=(const GradeTooLowException& other)
{
	std::cout << COLORBureaucratGradeETL << "Bureaucrat::GradeTooLowException assignation  constructor called." << RESETBureaucrat << std::endl;
	if (this != & other)
		GradeException::operator=(other);
	return *this ;
};
// class GradeTooLowException default destructor
Bureaucrat::GradeTooLowException::~GradeTooLowException( void ) throw()
{
	std::cout << COLORBureaucratGradeETL << "Bureaucrat::GradeTooLowException default destructor called." << RESETBureaucrat << std::endl;
} ;

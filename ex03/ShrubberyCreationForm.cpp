#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::_tree =  "       *\n"
												  "      /|\\\n"
												  "     /*|o\\\n"
												  "    /o*@*o\\\n"
												  "   /*o@*@o*\\\n"
												  "  /o*@o*o@*o\\\n"
												  " /*@o*@o@*o@*\\\n"
												  "/o*@o*@o@*o@*o\\\n"
												  "      |||\n"
												  "      |||\n"
												  "\n" 
												  "   Shruberry\n";
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
		return ;
	}
	
    std::string directory = "."; // Current directory
								 //
	if ( (access(directory.c_str(), W_OK) != 0) )
	{
        std::cout << COLORShrubb << "[ERROR] No write permission on current " ;
        std::cout << "directory! Error: " ;
		std::cout << std::strerror(errno) << RESETForm << std::endl;
        return ;
	}

	std::string filename = this->_target + "_shrubbery" ;
    std::ifstream file(filename.c_str());
    if ( file.good() )
	{
        std::cout << COLORShrubb << "Form executed previously. A shruberry " ;
		std::cout << "exists at " << this->_target << "." << RESETForm << std::endl;
        return ;
	}
    std::ofstream outFile(filename.c_str(), std::ios::out | std::ios::trunc);
    if (!outFile.is_open()) {
        std::cout << COLORShrubb << "[ERROR] Failed to open file for writing!";
        std::cout << " Error: " << std::strerror(errno) << RESETForm << std::endl;
        return ;
    }
    outFile << ShrubberyCreationForm::_tree;
    
    // Check if write operation succeeded
    if (outFile.fail()) 
	{
        std::cout << COLORShrubb << "[ERROR] Failed to write to  file!";
        std::cout << " Error: " << std::strerror(errno) << RESETForm << std::endl;
        return ;
    }
    
    outFile.close();

}
ShrubberyCreationForm::~ShrubberyCreationForm ( void )
{
	std::cout << COLORShrubb << "ShrubberyCreationForm destructor called." << RESETForm << std::endl;
}
const std::string & ShrubberyCreationForm::getTarget( void ) const
{
	return this->_target ;
}

#ifndef ShrubberyCreationForm_HH
# define ShrubberyCreationForm_HH

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cerrno>
#include <cstring>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <unistd.h>

# define RESETForm  	"\033[0;39m"
//# define COLORForm		"\033[0;90m"             //GRAY
//# define COLORForm		"\033[0;91m"             //RED
//# define COLORForm		"\033[0;92m"             //GREEN
//# define COLORForm		"\033[38;2;75;179;82m"   //GREEN
//# define COLORForm		"\033[0;93m"             //YELLOW
//# define COLORForm		"\033[0;94m"             //BLUE
//# define COLORForm		"\033[0;95m"             //MAGENTA
//# define COLORForm		"\033[0;96m"             //CYAN
//# define COLORForm		"\033[0;97m"             //WHITE
//# define COLORForm		"\033[0;99m"             //BLACK
//# define COLORForm		"\033[38;5;209m"         //ORANGE
# define COLORShrubb		"\033[38;2;184;143;29m"  //BROWN
//# define COLORForm    	"\033[38;5;234m"         //DARK_GRAY
//# define COLORForm		"\033[38;5;245m"         //MID_GRAY
//# define COLORForm		"\033[38;2;75;179;82m"   //DARK_GREEN
//# define COLORForm		"\033[38;5;143m"         //DARK_YELLOW

class Bureaucrat ; // Forward declaration
				   //
class ShrubberyCreationForm : public AForm
{
	public:
		virtual ~ShrubberyCreationForm( void ) ;
		ShrubberyCreationForm( std::string thetarget) ;
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm & other);
		ShrubberyCreationForm (const ShrubberyCreationForm & other);
		virtual void execute( const Bureaucrat & b);
		const std::string & getTarget( void ) const ;

	private:
		std::string _target ;
		int _executions;
		ShrubberyCreationForm( void ) ;
		static const std::string _tree ;
} ;

#endif

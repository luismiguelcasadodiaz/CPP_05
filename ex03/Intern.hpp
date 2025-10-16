#ifndef INTERN_HH
#define INTERN_HH

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

# define RESETForm  	"\033[0;39m"
//# define COLORFormGradeE		"\033[0;90m"             //GRAY
//# define COLORForm		"\033[0;91m"             //RED
//# define COLORForm		"\033[0;92m"             //GREEN
//# define COLORForm		"\033[38;2;75;179;82m"   //GREEN
//# define COLORPardon		"\033[0;93m"             //YELLOW
//# define COLORForm		"\033[0;94m"             //BLUE
# define COLORIntern		"\033[0;95m"             //MAGENTA
//# define COLORForm		"\033[0;96m"             //CYAN
//# define COLORForm		"\033[0;97m"             //WHITE
//# define COLORForm		"\033[0;99m"             //BLACK
//# define COLORForm		"\033[38;5;209m"         //ORANGE
//# define COLORForm		"\033[38;2;184;143;29m"  //BROWN
//# define COLORFormGradeEXEC	"\033[38;5;234m"         //DARK_GRAY
//# define COLORFormGradeSIGN	"\033[38;5;245m"         //MID_GRAY
//# define COLORForm		"\033[38;2;75;179;82m"   //DARK_GREEN
//# define COLORForm		"\033[38;5;143m"         //DARK_YELLOW

class Intern
{
	public:
		Intern ( void );
		~Intern ( void );
		Intern ( const Intern & other );
		Intern & operator=( const Intern & other );
		AForm * makeForm(const std::string & formName, const std::string & _target);

	private:
		struct form 
		{
			std::string formName ;
			AForm * (*formCreator)(const std::string &) ;
		};
		static form forms[] ;
		static const size_t num_forms;

		static AForm * ShrubberyFormCreator(const std::string & target);
		static AForm * RobotomyyFormCreator(const std::string & target);
		static AForm * PresidentFormCreator(const std::string & target);



};

#endif

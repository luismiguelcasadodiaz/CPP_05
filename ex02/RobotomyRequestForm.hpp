#ifndef RobotomyRequestForm_HH
# define RobotomyRequestForm_HH

#include "AForm.hpp"

# define RESETForm  	"\033[0;39m"
# define COLORFormGradeE		"\033[0;90m"             //GRAY
//# define COLORForm		"\033[0;91m"             //RED
//# define COLORForm		"\033[0;92m"             //GREEN
//# define COLORForm		"\033[38;2;75;179;82m"   //GREEN
//# define COLORPardon		"\033[0;93m"             //YELLOW
# define COLORRobotomy	"\033[0;94m"             //BLUE
//# define COLORForm		"\033[0;95m"             //MAGENTA
//# define COLORForm		"\033[0;96m"             //CYAN
//# define COLORForm		"\033[0;97m"             //WHITE
//# define COLORForm		"\033[0;99m"             //BLACK
//# define COLORForm		"\033[38;5;209m"         //ORANGE
//# define COLORForm		"\033[38;2;184;143;29m"  //BROWN
//# define COLORFormGradeEXEC	"\033[38;5;234m"         //DARK_GRAY
//# define COLORFormGradeSIGN	"\033[38;5;245m"         //MID_GRAY
//# define COLORForm		"\033[38;2;75;179;82m"   //DARK_GREEN
//# define COLORForm		"\033[38;5;143m"         //DARK_YELLOW

class Bureaucrat ; // Forward declaration
				   //
class RobotomyRequestForm : public AForm
{
	public:
		virtual ~RobotomyRequestForm( void ) ;
		RobotomyRequestForm( std::string thetarget) ;
		RobotomyRequestForm & operator=(const RobotomyRequestForm & other);
		RobotomyRequestForm (const RobotomyRequestForm & other);
		virtual void execute( const Bureaucrat & b);
		const std::string & getTarget( void ) const ;

	private:
		std::string _target ;
		int _executions;
		RobotomyRequestForm( void ) ;
} ;

#endif

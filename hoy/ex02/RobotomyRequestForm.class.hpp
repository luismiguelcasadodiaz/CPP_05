#ifndef RobotomyRequestForm_H
# define RobotomyRequestForm_H

# define RESETRobotomyRequestForm  	"\033[0;39m"
# define COLORRobotomyRequestForm		"\033[0;90m"             //GRAY
//# define COLORRobotomyRequestForm		"\033[0;91m"             //RED
//# define COLORRobotomyRequestForm		"\033[0;92m"             //GREEN
//# define COLORRobotomyRequestForm		"\033[38;2;75;179;82m"   //GREEN
//# define COLORRobotomyRequestForm		"\033[0;93m"             //YELLOW
//# define COLORRobotomyRequestForm		"\033[0;94m"             //BLUE
//# define COLORRobotomyRequestForm		"\033[0;95m"             //MAGENTA
//# define COLORRobotomyRequestForm		"\033[0;96m"             //CYAN
//# define COLORRobotomyRequestForm		"\033[0;97m"             //WHITE
//# define COLORRobotomyRequestForm		"\033[0;99m"             //BLACK
//# define COLORRobotomyRequestForm		"\033[38;5;209m"         //ORANGE
//# define COLORRobotomyRequestForm		"\033[38;2;184;143;29m"  //BROWN
//# define COLORRobotomyRequestForm		"\033[38;5;234m"         //DARK_GRAY
//# define COLORRobotomyRequestForm		"\033[38;5;245m"         //MID_GRAY
//# define COLORRobotomyRequestForm		"\033[38;2;75;179;82m"   //DARK_GREEN
//# define COLORRobotomyRequestForm		"\033[38;5;143m"         //DARK_YELLOW
# include <iostream>
# include <string>

class RobotomyRequestForm {
	private:
		// Private member functions
	protected:
		// Protectd member functions
	public:
		// Canonical form 
		RobotomyRequestForm( void ); //constructor by default
		RobotomyRequestForm(const RobotomyRequestForm& other); //constructor by copy
		RobotomyRequestForm & operator=(const RobotomyRequestForm & other);
		~RobotomyRequestForm( void ); // destructor

		// Constructor(s)
		//RobotomyRequestForm(${ARGS_LIST});

		// Getters

		// Setters

		// Oveloading of comparison operators

		// Public member functions

		// Helper functions for canonicalization
		std::string canonizeme( void ) const;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& obj);

#endif // RobotomyRequestForm_H

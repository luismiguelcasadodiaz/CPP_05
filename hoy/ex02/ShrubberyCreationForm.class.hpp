#ifndef ShrubberyCreationForm_H
# define ShrubberyCreationForm_H

# define RESETShrubberyCreationForm  	"\033[0;39m"
# define COLORShrubberyCreationForm		"\033[0;90m"             //GRAY
//# define COLORShrubberyCreationForm		"\033[0;91m"             //RED
//# define COLORShrubberyCreationForm		"\033[0;92m"             //GREEN
//# define COLORShrubberyCreationForm		"\033[38;2;75;179;82m"   //GREEN
//# define COLORShrubberyCreationForm		"\033[0;93m"             //YELLOW
//# define COLORShrubberyCreationForm		"\033[0;94m"             //BLUE
//# define COLORShrubberyCreationForm		"\033[0;95m"             //MAGENTA
//# define COLORShrubberyCreationForm		"\033[0;96m"             //CYAN
//# define COLORShrubberyCreationForm		"\033[0;97m"             //WHITE
//# define COLORShrubberyCreationForm		"\033[0;99m"             //BLACK
//# define COLORShrubberyCreationForm		"\033[38;5;209m"         //ORANGE
//# define COLORShrubberyCreationForm		"\033[38;2;184;143;29m"  //BROWN
//# define COLORShrubberyCreationForm		"\033[38;5;234m"         //DARK_GRAY
//# define COLORShrubberyCreationForm		"\033[38;5;245m"         //MID_GRAY
//# define COLORShrubberyCreationForm		"\033[38;2;75;179;82m"   //DARK_GREEN
//# define COLORShrubberyCreationForm		"\033[38;5;143m"         //DARK_YELLOW
# include <iostream>
# include <string>

class ShrubberyCreationForm {
	private:
		// Private member functions
	protected:
		// Protectd member functions
	public:
		// Canonical form 
		ShrubberyCreationForm( void ); //constructor by default
		ShrubberyCreationForm(const ShrubberyCreationForm& other); //constructor by copy
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm & other);
		~ShrubberyCreationForm( void ); // destructor

		// Constructor(s)
		//ShrubberyCreationForm(${ARGS_LIST});

		// Getters

		// Setters

		// Oveloading of comparison operators

		// Public member functions

		// Helper functions for canonicalization
		std::string canonizeme( void ) const;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& obj);

#endif // ShrubberyCreationForm_H

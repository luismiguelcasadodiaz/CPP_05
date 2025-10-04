#ifndef Form_H
# define Form_H

# define RESETForm  	"\033[0;39m"
# define COLORForm		"\033[0;90m"             //GRAY
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
//# define COLORForm		"\033[38;2;184;143;29m"  //BROWN
//# define COLORForm		"\033[38;5;234m"         //DARK_GRAY
//# define COLORForm		"\033[38;5;245m"         //MID_GRAY
//# define COLORForm		"\033[38;2;75;179;82m"   //DARK_GREEN
//# define COLORForm		"\033[38;5;143m"         //DARK_YELLOW
# include <iostream>
# include <string>

class Form {
	private:
		// Private member functions
	protected:
		// Protectd member functions
	public:
		// Canonical form 
		Form( void ); //constructor by default
		Form(const Form& other); //constructor by copy
		Form & operator=(const Form & other);
		~Form( void ); // destructor

		// Constructor(s)
		//Form(${ARGS_LIST});

		// Getters

		// Setters

		// Oveloading of comparison operators

		// Public member functions

		// Helper functions for canonicalization
		std::string canonizeme( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif // Form_H

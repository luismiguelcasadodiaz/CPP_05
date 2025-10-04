#ifndef AForm_H
# define AForm_H

# define RESETAForm  	"\033[0;39m"
# define COLORAForm		"\033[0;90m"             //GRAY
//# define COLORAForm		"\033[0;91m"             //RED
//# define COLORAForm		"\033[0;92m"             //GREEN
//# define COLORAForm		"\033[38;2;75;179;82m"   //GREEN
//# define COLORAForm		"\033[0;93m"             //YELLOW
//# define COLORAForm		"\033[0;94m"             //BLUE
//# define COLORAForm		"\033[0;95m"             //MAGENTA
//# define COLORAForm		"\033[0;96m"             //CYAN
//# define COLORAForm		"\033[0;97m"             //WHITE
//# define COLORAForm		"\033[0;99m"             //BLACK
//# define COLORAForm		"\033[38;5;209m"         //ORANGE
//# define COLORAForm		"\033[38;2;184;143;29m"  //BROWN
//# define COLORAForm		"\033[38;5;234m"         //DARK_GRAY
//# define COLORAForm		"\033[38;5;245m"         //MID_GRAY
//# define COLORAForm		"\033[38;2;75;179;82m"   //DARK_GREEN
//# define COLORAForm		"\033[38;5;143m"         //DARK_YELLOW
# include <iostream>
# include <string>

class AForm {
	private:
		// Private member functions
	protected:
		// Protectd member functions
	public:
		// Canonical form 
		AForm( void ); //constructor by default
		AForm(const AForm& other); //constructor by copy
		AForm & operator=(const AForm & other);
		~AForm( void ); // destructor

		// Constructor(s)
		//AForm(${ARGS_LIST});

		// Getters

		// Setters

		// Oveloading of comparison operators

		// Public member functions

		// Helper functions for canonicalization
		std::string canonizeme( void ) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif // AForm_H

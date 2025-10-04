#ifndef Intern_H
# define Intern_H

# define RESETIntern  	"\033[0;39m"
# define COLORIntern		"\033[0;90m"             //GRAY
//# define COLORIntern		"\033[0;91m"             //RED
//# define COLORIntern		"\033[0;92m"             //GREEN
//# define COLORIntern		"\033[38;2;75;179;82m"   //GREEN
//# define COLORIntern		"\033[0;93m"             //YELLOW
//# define COLORIntern		"\033[0;94m"             //BLUE
//# define COLORIntern		"\033[0;95m"             //MAGENTA
//# define COLORIntern		"\033[0;96m"             //CYAN
//# define COLORIntern		"\033[0;97m"             //WHITE
//# define COLORIntern		"\033[0;99m"             //BLACK
//# define COLORIntern		"\033[38;5;209m"         //ORANGE
//# define COLORIntern		"\033[38;2;184;143;29m"  //BROWN
//# define COLORIntern		"\033[38;5;234m"         //DARK_GRAY
//# define COLORIntern		"\033[38;5;245m"         //MID_GRAY
//# define COLORIntern		"\033[38;2;75;179;82m"   //DARK_GREEN
//# define COLORIntern		"\033[38;5;143m"         //DARK_YELLOW
# include <iostream>
# include <string>

class Intern {
	private:
		// Private member functions
	protected:
		// Protectd member functions
	public:
		// Canonical form 
		Intern( void ); //constructor by default
		Intern(const Intern& other); //constructor by copy
		Intern & operator=(const Intern & other);
		~Intern( void ); // destructor

		// Constructor(s)
		//Intern(${ARGS_LIST});

		// Getters

		// Setters

		// Oveloading of comparison operators

		// Public member functions

		// Helper functions for canonicalization
		std::string canonizeme( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Intern& obj);

#endif // Intern_H

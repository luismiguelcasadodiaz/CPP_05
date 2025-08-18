#ifndef Bureaucrat_H
# define Bureaucrat_H

# define RESETBureaucrat  	"\033[0;39m"
# define COLORBureaucrat		"\033[0;90m"             //GRAY
//# define COLORBureaucrat		"\033[0;91m"             //RED
//# define COLORBureaucrat		"\033[0;92m"             //GREEN
//# define COLORBureaucrat		"\033[38;2;75;179;82m"   //GREEN
//# define COLORBureaucrat		"\033[0;93m"             //YELLOW
//# define COLORBureaucrat		"\033[0;94m"             //BLUE
//# define COLORBureaucrat		"\033[0;95m"             //MAGENTA
//# define COLORBureaucrat		"\033[0;96m"             //CYAN
//# define COLORBureaucrat		"\033[0;97m"             //WHITE
//# define COLORBureaucrat		"\033[0;99m"             //BLACK
//# define COLORBureaucrat		"\033[38;5;209m"         //ORANGE
//# define COLORBureaucrat		"\033[38;2;184;143;29m"  //BROWN
//# define COLORBureaucrat		"\033[38;5;234m"         //DARK_GRAY
//# define COLORBureaucrat		"\033[38;5;245m"         //MID_GRAY
//# define COLORBureaucrat		"\033[38;2;75;179;82m"   //DARK_GREEN
//# define COLORBureaucrat		"\033[38;5;143m"         //DARK_YELLOW
# include <iostream>
# include <string>

class Bureaucrat {
	private:
		// Private member functions
		str::string name;
		std::size_t range;
	protected:
		// Protectd member functions
	public:
		// Canonical form 
		Bureaucrat( void ); //constructor by default
		Bureaucrat(const Bureaucrat& other); //constructor by copy
		Bureaucrat & operator=(const Bureaucrat & other);
		~Bureaucrat( void ); // destructor

		// Constructor(s)
		//Bureaucrat(${ARGS_LIST});

		// Getters

		// Setters

		// Oveloading of comparison operators

		// Public member functions

		// Helper functions for canonicalization
		std::string canonizeme( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif // Bureaucrat_H

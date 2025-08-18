#ifndef Contact_H
# define Contact_H

# define RESETContact  	"\033[0;39m"
# define COLORContact		"\033[0;90m"             //GRAY
//# define COLORContact		"\033[0;91m"             //RED
//# define COLORContact		"\033[0;92m"             //GREEN
//# define COLORContact		"\033[38;2;75;179;82m"   //GREEN
//# define COLORContact		"\033[0;93m"             //YELLOW
//# define COLORContact		"\033[0;94m"             //BLUE
//# define COLORContact		"\033[0;95m"             //MAGENTA
//# define COLORContact		"\033[0;96m"             //CYAN
//# define COLORContact		"\033[0;97m"             //WHITE
//# define COLORContact		"\033[0;99m"             //BLACK
//# define COLORContact		"\033[38;5;209m"         //ORANGE
//# define COLORContact		"\033[38;2;184;143;29m"  //BROWN
//# define COLORContact		"\033[38;5;234m"         //DARK_GRAY
//# define COLORContact		"\033[38;5;245m"         //MID_GRAY
//# define COLORContact		"\033[38;2;75;179;82m"   //DARK_GREEN
//# define COLORContact		"\033[38;5;143m"         //DARK_YELLOW
# include <iostream>
# include <string>

class Contact {
	private:
		// Private member functions
	protected:
		// Protectd member functions
	public:
		// Canonical form 
		Contact( void ); //constructor by default
		Contact(const Contact& other); //constructor by copy
		Contact & operator=(const Contact & other);
		~Contact( void ); // destructor

		// Constructor(s)
		//Contact(${ARGS_LIST});

		// Getters

		// Setters

		// Oveloading of comparison operators

		// Public member functions

		// Helper functions for canonicalization
		std::string canonizeme( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Contact& obj);

#endif // Contact_H

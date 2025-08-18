#ifndef PhoneBook_H
# define PhoneBook_H

# define RESETPhoneBook  	"\033[0;39m"
# define COLORPhoneBook		"\033[0;90m"             //GRAY
//# define COLORPhoneBook		"\033[0;91m"             //RED
//# define COLORPhoneBook		"\033[0;92m"             //GREEN
//# define COLORPhoneBook		"\033[38;2;75;179;82m"   //GREEN
//# define COLORPhoneBook		"\033[0;93m"             //YELLOW
//# define COLORPhoneBook		"\033[0;94m"             //BLUE
//# define COLORPhoneBook		"\033[0;95m"             //MAGENTA
//# define COLORPhoneBook		"\033[0;96m"             //CYAN
//# define COLORPhoneBook		"\033[0;97m"             //WHITE
//# define COLORPhoneBook		"\033[0;99m"             //BLACK
//# define COLORPhoneBook		"\033[38;5;209m"         //ORANGE
//# define COLORPhoneBook		"\033[38;2;184;143;29m"  //BROWN
//# define COLORPhoneBook		"\033[38;5;234m"         //DARK_GRAY
//# define COLORPhoneBook		"\033[38;5;245m"         //MID_GRAY
//# define COLORPhoneBook		"\033[38;2;75;179;82m"   //DARK_GREEN
//# define COLORPhoneBook		"\033[38;5;143m"         //DARK_YELLOW
# include <iostream>
# include <string>

class PhoneBook {
	private:
		// Private member functions
	protected:
		// Protectd member functions
	public:
		// Canonical form 
		PhoneBook( void ); //constructor by default
		PhoneBook(const PhoneBook& other); //constructor by copy
		PhoneBook & operator=(const PhoneBook & other);
		~PhoneBook( void ); // destructor

		// Constructor(s)
		//PhoneBook(${ARGS_LIST});

		// Getters

		// Setters

		// Oveloading of comparison operators

		// Public member functions

		// Helper functions for canonicalization
		std::string canonizeme( void ) const;
};

std::ostream& operator<<(std::ostream& os, const PhoneBook& obj);

#endif // PhoneBook_H

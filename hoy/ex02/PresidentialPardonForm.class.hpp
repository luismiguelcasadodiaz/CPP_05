#ifndef PresidentialPardonForm_H
# define PresidentialPardonForm_H

# define RESETPresidentialPardonForm  	"\033[0;39m"
# define COLORPresidentialPardonForm		"\033[0;90m"             //GRAY
//# define COLORPresidentialPardonForm		"\033[0;91m"             //RED
//# define COLORPresidentialPardonForm		"\033[0;92m"             //GREEN
//# define COLORPresidentialPardonForm		"\033[38;2;75;179;82m"   //GREEN
//# define COLORPresidentialPardonForm		"\033[0;93m"             //YELLOW
//# define COLORPresidentialPardonForm		"\033[0;94m"             //BLUE
//# define COLORPresidentialPardonForm		"\033[0;95m"             //MAGENTA
//# define COLORPresidentialPardonForm		"\033[0;96m"             //CYAN
//# define COLORPresidentialPardonForm		"\033[0;97m"             //WHITE
//# define COLORPresidentialPardonForm		"\033[0;99m"             //BLACK
//# define COLORPresidentialPardonForm		"\033[38;5;209m"         //ORANGE
//# define COLORPresidentialPardonForm		"\033[38;2;184;143;29m"  //BROWN
//# define COLORPresidentialPardonForm		"\033[38;5;234m"         //DARK_GRAY
//# define COLORPresidentialPardonForm		"\033[38;5;245m"         //MID_GRAY
//# define COLORPresidentialPardonForm		"\033[38;2;75;179;82m"   //DARK_GREEN
//# define COLORPresidentialPardonForm		"\033[38;5;143m"         //DARK_YELLOW
# include <iostream>
# include <string>

class PresidentialPardonForm {
	private:
		// Private member functions
	protected:
		// Protectd member functions
	public:
		// Canonical form 
		PresidentialPardonForm( void ); //constructor by default
		PresidentialPardonForm(const PresidentialPardonForm& other); //constructor by copy
		PresidentialPardonForm & operator=(const PresidentialPardonForm & other);
		~PresidentialPardonForm( void ); // destructor

		// Constructor(s)
		//PresidentialPardonForm(${ARGS_LIST});

		// Getters

		// Setters

		// Oveloading of comparison operators

		// Public member functions

		// Helper functions for canonicalization
		std::string canonizeme( void ) const;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& obj);

#endif // PresidentialPardonForm_H

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
		std::string first;
		std::string last;
		std::string nick;
		std::string number;
		std::string secret;
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
		std::string get_first( void ) const ;
		std::string get_last( void ) const ;
		std::string get_nick( void ) const ;
		std::string get_number( void ) const ;
		std::string get_secret( void ) const ;

		// Setters
		void set_first ( std::string the_first);
		void set_last ( std::string the_last);
		void set_nick ( std::string the_nick);
		void set_number ( std::string the_number);
		void set_secret ( std::string the_secret);

		// Oveloading of comparison operators

		// Public member functions

		// Helper functions for canonicalization
		std::string canonizeme( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Contact& obj);

#endif // Contact_H

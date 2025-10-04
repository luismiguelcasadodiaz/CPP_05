#ifndef ${CLASS_NAME}_H
# define ${CLASS_NAME}_H

# define RESET${CLASS_NAME}  	"\033[0;39m"
# define COLOR${CLASS_NAME}		"\033[0;90m"             //GRAY
//# define COLOR${CLASS_NAME}		"\033[0;91m"             //RED
//# define COLOR${CLASS_NAME}		"\033[0;92m"             //GREEN
//# define COLOR${CLASS_NAME}		"\033[38;2;75;179;82m"   //GREEN
//# define COLOR${CLASS_NAME}		"\033[0;93m"             //YELLOW
//# define COLOR${CLASS_NAME}		"\033[0;94m"             //BLUE
//# define COLOR${CLASS_NAME}		"\033[0;95m"             //MAGENTA
//# define COLOR${CLASS_NAME}		"\033[0;96m"             //CYAN
//# define COLOR${CLASS_NAME}		"\033[0;97m"             //WHITE
//# define COLOR${CLASS_NAME}		"\033[0;99m"             //BLACK
//# define COLOR${CLASS_NAME}		"\033[38;5;209m"         //ORANGE
//# define COLOR${CLASS_NAME}		"\033[38;2;184;143;29m"  //BROWN
//# define COLOR${CLASS_NAME}		"\033[38;5;234m"         //DARK_GRAY
//# define COLOR${CLASS_NAME}		"\033[38;5;245m"         //MID_GRAY
//# define COLOR${CLASS_NAME}		"\033[38;2;75;179;82m"   //DARK_GREEN
//# define COLOR${CLASS_NAME}		"\033[38;5;143m"         //DARK_YELLOW
# include <iostream>
# include <string>

class ${CLASS_NAME} {
	private:
		// Private member functions
	protected:
		// Protectd member functions
	public:
		// Canonical form 
		${CLASS_NAME}( void ); //constructor by default
		${CLASS_NAME}(const ${CLASS_NAME}& other); //constructor by copy
		${CLASS_NAME} & operator=(const ${CLASS_NAME} & other);
		~${CLASS_NAME}( void ); // destructor

		// Constructor(s)
		//${CLASS_NAME}(${ARGS_LIST});

		// Getters

		// Setters

		// Oveloading of comparison operators

		// Public member functions

		// Helper functions for canonicalization
		std::string canonizeme( void ) const;
};

std::ostream& operator<<(std::ostream& os, const ${CLASS_NAME}& obj);

#endif // ${CLASS_NAME}_H

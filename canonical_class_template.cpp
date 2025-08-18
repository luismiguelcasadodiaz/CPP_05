#include "${CLASS_NAME}.class.hpp"

//
// ::::::::::::::::::::::::::::Canonical form::::::::::::::::::::::::::::::::
//
${CLASS_NAME}::${CLASS_NAME}( void ) //constructor by default
{
	std::cout << "Default constructor called for ${CLASS_NAME} " << std::endl;
	std::cout << COLOR${CLASS_NAME} << "${CLASS_NAME} default constructor called." << RESET${CLASS_NAME} << std::endl;
	return ;
}

${CLASS_NAME}::${CLASS_NAME}(const ${CLASS_NAME}& other) //constructor by copy
{
	std::cout << COLOR${CLASS_NAME} << "${CLASS_NAME} copy constructor called." << RESET${CLASS_NAME} << std::endl;
	*this = other;
	return;
}

${CLASS_NAME} &  ${CLASS_NAME}::operator=(const ${CLASS_NAME} & other)
{
	std::cout << COLOR${CLASS_NAME} << "${CLASS_NAME} copy assignment operator called." << RESET${CLASS_NAME} <<std::endl;
	if (this != &other)
	{
		*this = other;
	}
	return *this; 
}

${CLASS_NAME}::~${CLASS_NAME}( void ) // destructor
{
	std::cout << COLOR${CLASS_NAME} << "${CLASS_NAME} destructor called." << RESET${CLASS_NAME} << std::endl;
	return ;
}

// Constructor(s)
//${CLASS_NAME}::${CLASS_NAME}(${ARGS_LIST});

// Getters

// Setters

// Comparison operators

// public member functions
// protected  member functions

// private member funcions

// Helper functions for canonicalization
std::string ${CLASS_NAME}::canonizeme( void ) const {
	std::string _str_ = "No implemented yet";
	return (_str_);
}


std::ostream& operator<<(std::ostream& os, const ${CLASS_NAME}& obj)
{
	os << COLOR${CLASS_NAME} << "${CLASS_NAME} " << obj.canonizeme()  << RESET${CLASS_NAME} << std::endl;
	return os;
};


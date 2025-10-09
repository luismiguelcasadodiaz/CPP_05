#ifndef Bureaucrat_H
# define Bureaucrat_H

# define RESETBureaucrat  	"\033[0;39m"
//# define COLORBureaucrat		"\033[0;90m"             //GRAY
# define COLORBureaucrat		"\033[0;91m"             //RED
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
# include <sstream>

class Bureaucrat {
	private:
		static const int _highest = 1 ;
		static const int _lowest = 150 ;		
		// Private member functions
		const std::string _name ;
		int _grade ;

	protected:
		// Protectd member functions
	public:
		// exceptions
		class GradeException : public std::exception {
			public:
				GradeException( const std::string & adjective,
					std::size_t limit ) : 
					_adjective(adjective), 
					_limit(limit),
					_msg() {
					std::stringstream ss ;
					ss << _adjective << " grade is Grade=" << _limit << "." ;
					_msg = ss.str() ; 
					}

				virtual ~GradeException( void ) throw () {}

				virtual const char * what() const throw () {
					return _msg.c_str(); 
				} 
			protected:
				GradeException ( const GradeException & other):
					_adjective(other._adjective), 
					_limit(other._limit),
					_msg()
				{
					std::stringstream ss ;
					ss << _adjective << " grade is Grade=" << _limit << "." ;
					_msg = ss.str() ; 
				}
				GradeException & operator=(const GradeException & other) ;
			private:
				const std::string _adjective ;
				const std::size_t _limit ;
				std::string _msg ;
				GradeException( void ):_adjective(""), _limit(0) {} //Default constructor

		} ;

		class GradeTooHighException : public GradeException
		{
			public: 
				GradeTooHighException() : GradeException("Maximun", 1) {};
				GradeTooHighException(const GradeTooHighException & other):
					GradeException( other ) {};
				GradeTooHighException & operator=(const GradeTooHighException& other)
				{
					if (this != & other)
						GradeException::operator=(other);
					return *this ;
				};
				virtual ~GradeTooHighException( void ) throw() {} ;
		} ;
		class GradeTooLowException : public GradeException
		{
			public:
				GradeTooLowException() : GradeException("Minimun", 150) {}
				GradeTooLowException(const GradeTooLowException & other):
					GradeException( other ) {};
				GradeTooLowException & operator=(const GradeTooLowException& other)
				{
					if (this != & other)
						GradeException::operator=(other);
					return *this ;
				};
				virtual ~GradeTooLowException( void ) throw() {} ;
		} ;

		// Canonical form 
		Bureaucrat( void ); //constructor by default
		Bureaucrat(const Bureaucrat & other); //constructor by copy
		Bureaucrat & operator=(const Bureaucrat & other);
		~Bureaucrat( void ); // destructor

		// Constructor(s)
		Bureaucrat( const std::string & thename, const int thegrade ) ;

		// Getters
		const std::string getName() const ;
		int getGrade() const ;

		// Setters
		void setGrade(const int & thegrade) ;

		// Oveloading of comparison operators

		// Public member functions
		void upGrade() ;
		void downGrade();

		// Helper functions for canonicalization
		std::string canonizeme( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif // Bureaucrat_H

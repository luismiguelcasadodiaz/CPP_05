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
# include <sstream>

class Bureaucrat {
	private:
		static const std::size_t _highest = 1 ;
		static const std::size_t _lowest = 150 ;		
		// Private member functions
		const std::string _name ;
		std::size_t _grade ;

		// exceptions
		class GradeException : public std::exception {
			public:
				GradeException( const std::string & adjective,
					std::size_t limit ) : 
					_adjective(adjective), 
					_limit(limit) {
					std::stringstream ss ;
					ss << _adjective << " grade is Grade=" << _limit << "." ;
					_msg = ss.str() ; 
					}


				virtual ~GradeException( void ) throw () {}
				GradeException ( const GradeException & other) :
					_adjective(other._adjective), 
					_limit(other._limit), 
					_msg(other._msg) {}

				virtual const char * what() const throw () {
					return _msg.c_str(); 
				} 


			private:
				const std::size_t _limit ;
				const std::string _adjective ;
				std::string _msg ;
				GradeException & operator=(const GradeException & other) 
				{
					if (this != & other)
					{ 
						_limit = other._limit ;
						_adjective = other._adjective ;
						_msg = other._msg ;

					}
					return *this ;
				}				

		} ;

		class GradeTooLowException : public std::exception {

		} ;
	protected:
		// Protectd member functions
	public:

		// Canonical form 
		Bureaucrat( void ); //constructor by default
		Bureaucrat(const Bureaucrat & other); //constructor by copy
		Bureaucrat & operator=(const Bureaucrat & other);
		~Bureaucrat( void ); // destructor

		// Constructor(s)
		//Bureaucrat(${ARGS_LIST});

		// Getters
		const std::string getName() const ;
		std::size_t getGrade() const ;

		// Setters
		void setName(const std::string & thename) ;
		void setGrade(const std::size_t & thegrade) ;

		// Oveloading of comparison operators

		// Public member functions
		void upGrade() ;
		void downGrade()

		// Helper functions for canonicalization
		std::string canonizeme( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif // Bureaucrat_H

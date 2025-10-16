#ifndef Bureaucrat_H
# define Bureaucrat_H

# define RESETBureaucrat  	"\033[0;39m"
# define COLORBureaucratGradeE		"\033[0;90m"             //GRAY
//# define COLORBureaucrat		"\033[0;91m"             //RED
# define COLORBureaucrat		"\033[0;92m"             //GREEN
//# define COLORBureaucrat		"\033[38;2;75;179;82m"   //GREEN
//# define COLORBureaucrat		"\033[0;93m"             //YELLOW
//# define COLORBureaucrat		"\033[0;94m"             //BLUE
//# define COLORBureaucrat		"\033[0;95m"             //MAGENTA
//# define COLORBureaucrat		"\033[0;96m"             //CYAN
//# define COLORBureaucrat		"\033[0;97m"             //WHITE
//# define COLORBureaucrat		"\033[0;99m"             //BLACK
//# define COLORBureaucrat		"\033[38;5;209m"         //ORANGE
//# define COLORBureaucrat		"\033[38;2;184;143;29m"  //BROWN
# define COLORBureaucratGradeETH		"\033[38;5;234m"         //DARK_GRAY
# define COLORBureaucratGradeETL		"\033[38;5;245m"         //MID_GRAY
//# define COLORBureaucrat		"\033[38;2;75;179;82m"   //DARK_GREEN
//# define COLORBureaucrat		"\033[38;5;143m"         //DARK_YELLOW
# include <iostream>
# include <string>
# include <sstream>
class AForm ; // Forward declaration
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
					            std::size_t limit ) ;

				virtual ~GradeException( void ) throw () ;

				virtual const char * what() const throw () ;
			protected:
				GradeException ( const GradeException & other) ;
				GradeException & operator=(const GradeException & other) ;
			private:
				const std::string _adjective ;
				const std::size_t _limit ;
				std::string _msg ;
				GradeException( void ) ;
		} ;

		class GradeTooHighException : public GradeException
		{
			public: 
				GradeTooHighException();
				GradeTooHighException(const GradeTooHighException & other); 
				GradeTooHighException & operator=(
					const GradeTooHighException& other);
				virtual ~GradeTooHighException( void ) throw();
		} ;
		class GradeTooLowException : public GradeException
		{
			public:
				GradeTooLowException() ;
				GradeTooLowException(const GradeTooLowException & other);
				GradeTooLowException & operator=(
					const GradeTooLowException& other);
				virtual ~GradeTooLowException( void ) throw();
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
		void signForm( AForm & f );
		void executeForm( AForm & f );

		// Helper functions for canonicalization
		std::string canonizeme( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif // Bureaucrat_H

#ifndef FORM_HH
#define FORM_HH
#include "Bureaucrat.hpp"
#include <ostream>

# define RESETForm  	"\033[0;39m"
# define COLORFormGradeE		"\033[0;90m"             //GRAY
//# define COLORForm		"\033[0;91m"             //RED
//# define COLORForm		"\033[0;92m"             //GREEN
//# define COLORForm		"\033[38;2;75;179;82m"   //GREEN
//# define COLORForm		"\033[0;93m"             //YELLOW
# define COLORForm		"\033[0;94m"             //BLUE
//# define COLORForm		"\033[0;95m"             //MAGENTA
//# define COLORForm		"\033[0;96m"             //CYAN
//# define COLORForm		"\033[0;97m"             //WHITE
//# define COLORForm		"\033[0;99m"             //BLACK
//# define COLORForm		"\033[38;5;209m"         //ORANGE
//# define COLORForm		"\033[38;2;184;143;29m"  //BROWN
# define COLORFormGradeTHE		"\033[38;5;234m"         //DARK_GRAY
# define COLORFormGradeTLE		"\033[38;5;245m"         //MID_GRAY
# define COLORFormGradeEXEC		"\033[38;2;75;179;82m"   //DARK_GREEN
# define COLORFormGradeSIGN		"\033[38;5;143m"         //DARK_YELLOW

class AForm
{
	private:
		static const int _highest = 1 ;
		static const int _lowest = 150 ;		
		const std::string _name ;
		const int _e_grade ;
		const int _s_grade ;
		bool _signed ;
		

	public:
		AForm( void ) ;
		virtual ~AForm ( void ) ;
		AForm( const AForm & other ) ;
		AForm & operator=( const AForm & other ) ;

		AForm (const std::string & thename, const int & e, const int & s) ;
		void beSigned( const Bureaucrat & b ) ;
		virtual void execute( const Bureaucrat & b ) const = 0 ;
		const std::string canonizeme ( void ) const ;

		// Base Exception for Form operational exceptions
		class FormOperException : public std::exception
		{
			public:
				FormOperException(	const std::string & name, 
								const std::string & target,
								const std::string & action, 
								int required_g,
								int actual_g);
				FormOperException( const FormOperException & other) ;
				virtual ~FormOperException ( void ) throw();
				virtual const char * what() const throw() ;
			protected:
				FormOperException & operator=(const FormOperException & other);
			private:
				std::string _formName ;
				std::string _target ;
				std::string _action ;
				int	_minGrade ;
				int _curGrade ;
				std::string _msg;
				FormOperException( void ) ;

		};
		class execGradeTooLowException : public FormOperException
		{
			public:
				execGradeTooLowException(	const std::string & formName,
											const std::string & formTarget,
											int required_g,
											int actual_g) ;
				virtual ~execGradeTooLowException( void ) throw ();
		};
		class signGradeTooLowException : public FormOperException
		{
			public:
				signGradeTooLowException( 	const std::string & formName,
											const std::string & formTarget,
											int required_g,
											int actual_g ) ;
				virtual ~signGradeTooLowException( void ) throw ();
		};

		// Base Exception for max min grades 
		class GradeException :public std::exception
		{ 
			private:
				const std::string _adjective ;
				const int _limit ;
				std::string _text ;
			protected:
				GradeException (const GradeException & other ) ;
				GradeException & operator=( const GradeException & other) ;
			public:
				GradeException ( void ) ;
				virtual ~GradeException ( void ) throw () ;
				GradeException (const std::string & adj, const int lim) ;
				virtual const char * what () const throw ();
		};
		// specific exception for under grade forms
		class GradeTooLowException: public GradeException
		{
			public:
				GradeTooLowException( void ) ;
				GradeTooLowException(const GradeTooLowException & other) ;
				GradeTooLowException & operator=(const GradeTooLowException & other) ;
				~GradeTooLowException( void ) throw();
		}  ;
		// specific exception for over grade forms
		class GradeTooHighException: public GradeException
		{
			public:
				GradeTooHighException( void ) ;
				GradeTooHighException(const GradeTooHighException & other) ;
				GradeTooHighException & operator=(const GradeTooHighException & other) ;
				~GradeTooHighException( void ) throw();
		} ; 
		// getters
		const std::string & getName( void ) const ;
		int getExecGrade( void ) const ;
		int getSignGrade( void ) const ;
		bool isSigned( void ) const ;
		// setters
		void setSigned( bool state) ;

};

std::ostream& operator<<(std::ostream & os, const AForm & obj );
#endif


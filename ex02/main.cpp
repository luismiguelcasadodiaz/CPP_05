#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <string>
#include <stdexcept>


int main(void)
{
	Bureaucrat b001("Alice", 1) ;
	Bureaucrat b020("Bob 020", 20) ;
	Bureaucrat b025("Peter 025", 25) ;
	try
	{
		PresidentialPardonForm ppf023("Miguel") ; 
		PresidentialPardonForm ppf024("Carlos") ; 
		b025.signForm(ppf023);
		b025.executeForm(ppf023) ;
		b025.executeForm(ppf024);
		b025.signForm(ppf024);
		b025.executeForm(ppf024);
		b001.signForm(ppf023);
		b001.executeForm(ppf023) ;
		b001.executeForm(ppf024);
		b001.signForm(ppf024);
		b001.executeForm(ppf024);
		b020.signForm(ppf023);
		b020.executeForm(ppf023) ;
		b020.executeForm(ppf024);
		b020.signForm(ppf024);
		b020.executeForm(ppf024);
	} catch (std::exception &e)
	{
		std::cout << "Exception =>" << e.what() << std::endl;
	}

	try
	{
		RobotomyRequestForm rrf023("Miguel") ; 
		RobotomyRequestForm rrf024("Carlos") ; 
		b025.signForm(rrf023);
		b025.executeForm(rrf023) ;
		b025.executeForm(rrf024);
		b025.signForm(rrf024);
		b025.executeForm(rrf024);
		b001.signForm(rrf023);
		b001.executeForm(rrf023) ;
		b001.executeForm(rrf024);
		b001.signForm(rrf024);
		b001.executeForm(rrf024);
		b020.signForm(rrf023);
		b020.executeForm(rrf023) ;
		b020.executeForm(rrf024);
		b020.signForm(rrf024);
		b020.executeForm(rrf024);
	} catch (std::exception &e)
	{
		std::cout << "Exception =>" << e.what() << std::endl;
	}

return 0;
}

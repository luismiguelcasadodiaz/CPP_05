#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>
#include <stdexcept>


int main(void)
{
	{
		Bureaucrat b001("Alice", 1) ;
		Bureaucrat b020("Bob 020", 20) ;
		Bureaucrat b025("Peter 025", 25) ;
		PresidentialPardonForm f023("Miguel") ; 
		PresidentialPardonForm f024("Carlos") ; 
		b025.signForm(f023);
		b025.executeForm(f023) ;
		b025.executeForm(f024);
		b025.signForm(f024);
		b025.executeForm(f024);
		b001.signForm(f023);
		b001.executeForm(f023) ;
		b001.executeForm(f024);
		b001.signForm(f024);
		b001.executeForm(f024);
		b020.signForm(f023);
		b020.executeForm(f023) ;
		b020.executeForm(f024);
		b020.signForm(f024);
		b020.executeForm(f024);
	}
return 0;
}

#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
#include <string>
#include <cctype>
#include <csignal>
#include <limits> 
// This is our custom signal handler function.
// It will be executed whenever a SIGINT signal is received.
void signalHandler(int signum) {
    std::cout << "\n[INFO]: Received signal " << signum << ". Ignoring it.\n";
    std::cout << "Please use a different method to exit the program.\n";
}
std::string read_command( void )
{
	bool goodcommand = false ;
	std::string exit = ("EXIT");
	std::string add = ("ADD");
	std::string search = ("SEARCH");
    std::string command ;
	std::string capitalized;
	while (not goodcommand) 
	{
		std::cout << "Enter a command [ADD, SEARCH, EXIT] ==>" ;
		if (std::getline(std::cin, command)) 
		{
			// The read was successful, now check if the sentence is empty
			if (command.empty()) {
				std::cout << "You entered an empty line. It is invalid" << std::endl;
			} else {
				capitalized = "";
				for (std::size_t i = 0; i < command.length(); i++)
				{
					capitalized += static_cast<char>(std::toupper(command[i]));
				}
				if ( ( capitalized.compare(add   ) == 0 ) || 
					 ( capitalized.compare(search) == 0 ) ||
					 ( capitalized.compare(exit  ) == 0 ) )	          
				{
					goodcommand = true ;	
				} else {
					std::cout << "You entered incorrectly : " << command << std::endl;
				}
            }
		} else {
			// The read was not successful. This typically means an end-of-file (EOF) condition was met.
			// On Unix, this is usually caused by Ctrl+D.
			std::cout << "End of input or an error occurred." << std::endl;
            // Step 1: Clear the fail state.
            std::cin.clear();
            
            // Step 2: Ignore the rest of the bad line of input.
            // We read up to the maximum number of characters possible, or until a newline character is found.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            // The loop will now run again, prompting the user for new input.
			capitalized = exit;
			goodcommand = true;
		}
    }
	return capitalized ;
}

std::string capitalize(std::string command)
{ 
	std::string capitalized;
	for (std::size_t i = 0; i < command.length(); i++)
	{
		capitalized += static_cast<char>(std::toupper(command[i]));
	}
	return capitalized;
}
int main(void)
{
	Contact amigo;
	bool finish = false;
	std::string command ;
	std::string command_cap;
	std::string exit = ("EXIT");

    // Register the signal handler.
    // When the program receives SIGINT (Ctrl+C), it will call our signalHandler function.

    signal(SIGINT, signalHandler);
    signal(SIGQUIT, signalHandler);

	amigo.set_first("Luis");
	amigo.set_last("Casado");
	amigo.set_nick("Luismi");
	amigo.set_number("3456");
	amigo.set_secret("Tirame");

	std::cout << amigo.get_first() << std::endl ;
	std::cout << amigo.get_last() << std::endl ;
	std::cout << amigo.get_nick() << std::endl ;
	std::cout << amigo.get_number() << std::endl ;
	std::cout << amigo.get_secret() << std::endl ;
	std::cout << amigo.canonizeme() << std::endl ;
	while ( not finish )
	{	
		command_cap = read_command() ;
		if ( command_cap.compare(exit) == 0 )
			finish = true;
	}
}

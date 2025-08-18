#include <iostream>

int main (int argc, char** argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl ;
	else
	{
		for (int i = 1 ; i < argc ; i++)
		{
			std::string line = argv[i];
			for(std::size_t k = 0; k <= line.size(); k++)
				line[k] = toupper(line[k]);
			std::cout << line ;
		}
		std::cout << std::endl;
	}
}


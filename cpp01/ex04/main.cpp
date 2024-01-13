#include <iostream> 
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>

int	occurence(std::string s1, std::string s2){
	std::size_t found = s2.find(s1);
	if (found != std::string::npos)
		return 1;
	return 0;
}

int	main(int ac, char **av){
	if (ac != 4)
		return (std::cout << "./Sed takes 3 parameters: a \"file\" and 2 strings s1 and s2, where s2 is going to replace s1 in \"file\"" << std::endl, 1);
	std::ifstream	infile;
	infile.open(av[1]);
	if (!infile.good())
		return (std::cout << av[1] << ": error opening it" << std::endl, 1);
	infile.seekg(0, infile.end);
	int	len = infile.tellg();
	if (len == -1)
		return (std::cout << av[1] << ": error trying to get its length" << std::endl, 1);
	infile.seekg(0, infile.beg);
	char	*buf = new char[len + 1];
	if (!infile.read(buf, len))
		return (std::cout << "error reading" << std::endl, 1);
	buf[len] = 0;
	infile.close();
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string replaced = av[1];
	replaced += ".replace";
	std::ofstream outfile;
	outfile.open(replaced.c_str());
	std::string	replacing;
	std::string beubeuf = buf;
	std::size_t	found = beubeuf.find(s1);
	int	occurance = occurence(s1, s2);
	if (s1.length() == 0)
		return (outfile << buf, delete [] buf, outfile.close(), infile.close(), 0);
	while (found != std::string::npos){
		beubeuf.erase(found, s1.length());
		beubeuf.insert(found, s2);
		if (occurance == 0)
			found = beubeuf.find(s1, found);
		else
			found = beubeuf.find(s1, found+s2.length());
	}
	std::cout << beubeuf << std::endl;
	outfile << beubeuf;
	delete [] buf;
	outfile.close();
	infile.close();
	return (0);
}
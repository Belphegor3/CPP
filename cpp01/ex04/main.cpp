#include <iostream> 
#include <fstream>
#include <string>

// int	main(int ac, char **av)
// {
// 	if (ac != 4)
// 		return (std::cout << "./sed takes three parameters in the following order: a filename and two strings, s1 and s2.", 1);
// 	std::ifstream ifs(av[1], std::ifstream::binary);
// 	if (!ifs)
// 		return (std::cout << av[1] << ": no such file or directory" << std::endl, 1);
// 	// get length of file:
//    ifs.seekg(0,ifs.end);
//     int length =ifs.tellg();
// 	// std::cout <<ifs.tellg();
//    ifs.seekg(0,ifs.beg);

//     // allocate memory:
//     char * buffer = new char [length];

//     // read data as a block:
//    ifs.read(buffer,length);


//    ifs.close();

//     // print content:
//     std::cout.write(buffer,length);
// 	// std::cout <<ifs.tellg();

//     delete[] buffer;
// }

// #include <iostream>     // std::cout
// #include <fstream>      // std::ifstream

// int main () {
//   std::ifstream is("test.txt", std::ifstream::binary);
//   if (is) {
//     // get length of file:
//     is.seekg(0, is.end);
//     int length = is.tellg();
// 	std::cout << is.tellg();
//     is.seekg(0, is.beg);

//     // allocate memory:
//     char * buffer = new char [length];

//     // read data as a block:
//     is.read(buffer,length);

//     is.close();

//     // print content:
//     std::cout.write(buffer,length);
// 	// std::cout << is.tellg();

//     delete[] buffer;
//   }

//   return 0;
// }

const char	*create_replace(char *name, int len_name)
{
	int i = 0;
	while (name[i])
		i++;
	int	len_name = i;
	char	*char_replace = new(len_name + 8);
	i = 0;
	while (i < len_name)
	{
		char_replace[i] = name[i];
		i++;
	}
	int j = 0;
	const char	*dot_replace = ".replace";
	while (j < 8){
		char_replace[i + j] = dot_replace[j];
		j++;
	}
	char_replace[i + j] = 0;
	const char	*replace = char_replace;
	return (replace);
}

int main (int ac, char **av) {
	if (ac != 4)
		return (std::cout << "./sed takes three parameters in the following order: a filename and two strings, s1 and s2.", 1);
	create_replace(av[1]);
	// std::ifstream	infile;

	// infile.open(av[1]);
	// if (!infile)
	// 	return (std::cout << av[1] << ": no such file or directory" << std::endl, 1);
	// infile.seekg(0, infile.end);

	
	
	std::string replace = av[1];
	replace += ".replace";

	std::ofstream outfile;
	outfile.open (replace);
	outfile.seekp(0, outfile.end);
	// int	length = outfile.tellp();
	// char	*buffer = new char[length];
	
	outfile.write ("This is an apple",16);
	long pos = outfile.tellp();
	outfile.seekp (pos-7);	
	outfile.write (" sam 123456789",14);
	pos = outfile.tellp();
	outfile.seekp (pos-2);
	outfile.write (" sam 123456789",14);
	outfile.close();

  return 0;
}
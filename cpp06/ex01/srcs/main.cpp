#include <iostream>
#include <stdint.h>
#include "Data.hpp"

uintptr_t serialize(Data* ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw){
	return (reinterpret_cast<Data *>(raw));
}

int	main(void)
{
	Data		*test = new Data;
	test->i = 42;
	Data		*cpy;
	uintptr_t	raw;
	
	raw = serialize(test);
	cpy = deserialize(raw);
	
	std::cout << "test->i: " << test->i << std::endl;
	std::cout << "cpy->i: " << cpy->i << std::endl << std::endl;
	
	std::cout << "test: " << test << std::endl;
	std::cout << "cpy: " << cpy << std::endl;
	
	delete test;
	return (0);
}
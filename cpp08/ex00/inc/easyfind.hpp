#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <deque>
#include <stdexcept>
#include <vector>
#include <list>
#define OUT_RANGE "value not found"

template<typename T>
int	easyfind(T &container, int i){
	typename T::iterator it = std::find(container.begin(), container.end(), i);
	if (it == container.end()){
		std::cout << i << " ";
		throw(std::out_of_range(OUT_RANGE));
	}
	return *it;
}

#endif
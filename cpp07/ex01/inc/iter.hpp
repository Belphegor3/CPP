#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template< typename T >
void	iter(T *tab, int size, void (*f)(T&)){
	for (int i = 0; i < size; i++)
		f(tab[i]);
}

template< typename T >
void	display(T &i){
	std::cout << ++i << std::endl;
}

#endif
#ifndef MUTANTSTACK_CLASS_HPP
# define MUTANTSTACK_CLASS_HPP

# include <iostream>
# include <vector>
# include <stack>
# include <algorithm>
# include <stdlib.h>
# include <list>
# include <time.h>

// La classe std::stack<T> définit un membre de données c qui est de type
// std::stack<T>::container_type. Le type std::stack<T>::container_type est
// un alias de type défini par la classe std::stack<T> qui vaut de base deque (deck)

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const iterator begin() const { return this->c.begin(); }
	const iterator end() const { return this->c.end(); }
};

#endif
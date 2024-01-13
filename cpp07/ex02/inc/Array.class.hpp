#ifndef ARRAY_CLASS_HPP
# define ARRAY_CLASS_HPP

# include <iostream>
# include <string>

template <class T>
class Array{
	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(Array const& src);
		Array & operator=(Array const& rhs);
		T & operator[](unsigned int i);
		int	size (void) const;
		class excep : public std::exception{
			public:
				const char* what() const throw(){
					return ("Out of tab");
				};
		};
	private:
		unsigned int	_size;
		T	*_tab;
};

template <class T>
Array<T>::Array(): _size(0), _tab(new T[0]()){}

template <class T>
Array<T>::Array(unsigned int n): _size(n), _tab(new T[n]()){}

template <class T>
Array<T>::~Array(){
	delete [] _tab;
}

template <class T>
Array<T>::Array(Array const& src){
	_size = src.size();
	_tab = new T[src.size()]();
	for (unsigned int i = 0; i < _size; i++)
		_tab[i] = src._tab[i];
}

template <class T>
int	Array<T>::size (void) const{
	return (_size);
}

template <class T>
Array<T> &	Array<T>::operator=(Array<T> const& rhs)
{
	_size = rhs.size();
	_tab = new T[rhs.size()]();
	for (unsigned int i = 0; i < _size; i++)
		_tab[i] = rhs._tab[i];
	return *this;
}

template<class T>
T & Array<T>::operator[](unsigned int i){
		if (i < _size && i >= 0)
			return (_tab[i]);
		else
			throw excep();
}

#endif
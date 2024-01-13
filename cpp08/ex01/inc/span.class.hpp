#ifndef SPAN_CLASS_HPP
# define SPAN_CLASS_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdlib.h>
# include <time.h>
# include <exception>

class Span{
	public:
		Span(unsigned int N);
		~Span();
		Span(Span const & src);
		Span const & operator=(Span const & rhs);
		
		void	addNumber(int i);
		int		shortestSpan();
		int		longestSpan();
		class limit : public std::exception{
			public:
				const char* what() const throw(){
					return ("Max values already reached");
				};
		};
		class not_enough : public std::exception{
			public:
				const char* what() const throw(){
					return ("Not enough values to compare");
				};
		};
		int	nbMax() const;
		int	getNb();
		void	display();
	private:
		int		_nb;
		int		_nb_max;
		int		*_tab;
};

Span::Span(unsigned int N): _nb(0), _nb_max(N), _tab(new int[N]()){}

Span::~Span(){
	delete [] _tab;
}

Span::Span(Span const & src){
	_nb = src._nb;
	_nb_max = src._nb_max;
	_tab = new int[src._nb_max]();
	for (int i = 0; i < _nb; i++){
		_tab[_nb] = src._tab[_nb];
	}
}

Span const&	Span::operator=(Span const & rhs){
	_nb = rhs._nb;
	_nb_max = rhs._nb_max;
	_tab = new int[rhs._nb_max]();
	for (int i = 0; i < _nb; i++){
		_tab[_nb] = rhs._tab[_nb];
	}
	return *this;
}

void	Span::display(){
	for (int i = 0; i < _nb; i++)
		std::cout << _tab[i] << std::endl;
}

void	Span::addNumber(int i){
	if (_nb < _nb_max)
		_tab[_nb++] = i;
	else
		throw limit();
}

int		Span::shortestSpan(){
	if (_nb < 2)
		throw not_enough();
	std::vector<int> myvector(_tab, _tab+_nb);
	std::sort(myvector.begin(), myvector.end());
	int	shortest = abs(_tab[0] - _tab[1]);
	if (_tab[2]){
		for (std::vector<int>::iterator it = myvector.begin()+1; it != myvector.end(); it++){
			if (shortest > abs(*it - *(it-1)))
				shortest = abs(*it - *(it-1));
		}
	}
	return (shortest);
}

int		Span::longestSpan(){
	if (_nb < 2)
		throw not_enough();
	std::vector<int> myvector(_tab, _tab+_nb);
	std::sort(myvector.begin(), myvector.end());
	std::vector<int>::iterator beg=myvector.begin();
	std::vector<int>::iterator end=myvector.end()-1;
	return (abs(*beg - *end));
}

int	Span::nbMax(void) const{
	return (_nb_max);
}

int	Span::getNb(){
	return (_nb);
}

#endif
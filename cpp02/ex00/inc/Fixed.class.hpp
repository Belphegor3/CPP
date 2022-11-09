#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class Fixed
{
	private:
		int	_dot;
		static const int	_nb_bits;	
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		~Fixed();
		Fixed &	operator=(Fixed const & rhs);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

Fixed::Fixed(void): _dot(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &rhs)
		this->_dot = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member fonction called" << std::endl;
	return _dot;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member fonction called" << std::endl;
	_dot = raw;
}

#endif

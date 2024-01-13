#include "Fixed.class.hpp"

Fixed::Fixed(void): _res(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i){
	std::cout << "Default int constructor called" << std::endl;
	_res = i << _neg_bits;
}

// valeur de base de 10 passe en parametre de la classe fixed: 00001010
// conversion de la valeur 10 dans le constructeur: 0000101000000000
// utilisation de toInt: 00001010

Fixed::Fixed(const float f){
	std::cout << "Default float constructor called" << std::endl;
	_res = (int)(roundf(f * (1 << _neg_bits)));
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
		this->_res = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	return _res;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member fonction called" << std::endl;
	_res = raw;
}

float	Fixed::toFloat() const{
	return ((float)_res / (float)(1 << _neg_bits));
}

int		Fixed::toInt() const{
	return ((int)_res >> _neg_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &src){
	return (out << src.toFloat());
}
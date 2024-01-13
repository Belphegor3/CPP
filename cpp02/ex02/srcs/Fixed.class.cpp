#include "Fixed.class.hpp"

Fixed::Fixed(void): _res(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i){
	// std::cout << "Default int constructor called" << std::endl;
	_res = i << _neg_bits;
}

Fixed::Fixed(const float f){
	// std::cout << "Default float constructor called" << std::endl;
	_res = (int)(roundf(f * (1 << _neg_bits)));
}

Fixed::Fixed(Fixed const & src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	// std::cout << "Copy assignement operator called" << std::endl;
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
	// std::cout << "setRawBits member fonction called" << std::endl;
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

Fixed 	Fixed::operator+(Fixed const & rhs){
    Fixed fix;
    fix.setRawBits(_res + rhs.getRawBits());
    return (fix);
}

Fixed 	Fixed::operator-(Fixed const & rhs){
    Fixed fix;
    fix.setRawBits(_res - rhs.getRawBits());
    return (fix);
}

Fixed 	Fixed::operator*(Fixed const & rhs){
    Fixed fix;
    fix.setRawBits((_res * rhs.getRawBits()) >> _neg_bits);
    return (fix);
}

Fixed 	Fixed::operator/(Fixed const & rhs){
    Fixed fix;
    fix.setRawBits((_res << _neg_bits) / rhs.getRawBits());
    return (fix);
}

Fixed &	Fixed::operator++(){
	_res++;
	return *this;
}

Fixed &	Fixed::operator--(){
	_res--;
	return *this;
}

Fixed 	Fixed::operator--(int){
	Fixed fix(*this);
	operator--();
	return fix;
}

Fixed 	Fixed::operator++(int){
	Fixed fix(*this);
	operator++();
	return fix;
}

bool	Fixed::operator>(Fixed const & rhs) const{
	return (_res > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const & rhs) const{
	return (_res < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const & rhs) const{
	return (_res >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const & rhs) const{
	return (_res <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const & rhs) const{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const & rhs) const{
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed	&Fixed::min(Fixed &f1, Fixed &f2){
	return (f1 < f2 ? f1: f2);
}

const Fixed	&Fixed::min(Fixed const &f1, Fixed const &f2){
	return (f1 < f2 ? f1: f2);
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2){
	return (f1 < f2 ? f2: f1);
}

const Fixed	&Fixed::max(Fixed const &f1, Fixed const &f2){
	return (f1 < f2 ? f2: f1);
}

Fixed	&min(Fixed &f1, Fixed &f2){
	return (f1 < f2 ? f1:f2);
}

Fixed	&max(Fixed &f1, Fixed &f2){
	return (f1 > f2 ? f1:f2);
}
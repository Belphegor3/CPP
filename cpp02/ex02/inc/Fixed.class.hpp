#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int	_res;
		static const int	_neg_bits = 8;	
	public:
		Fixed(void);
		Fixed(const int i);
		Fixed(const float f);
		Fixed(Fixed const & src);
		~Fixed();


		Fixed &	operator=(Fixed const & rhs);
		Fixed 	operator+(Fixed const & rhs);
		Fixed 	operator-(Fixed const & rhs);
		Fixed 	operator*(Fixed const & rhs);
		Fixed 	operator/(Fixed const & rhs);
		bool	operator>(Fixed const & rhs) const;
		bool	operator<(Fixed const & rhs) const;
		bool	operator>=(Fixed const & rhs) const;
		bool	operator<=(Fixed const & rhs) const;
		bool	operator==(Fixed const & rhs) const;
		bool	operator!=(Fixed const & rhs) const;
		Fixed &	operator++();
		Fixed &	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);


		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt() const;

		Fixed static &min(Fixed &f1, Fixed &f2);
		const static Fixed	&min(Fixed const &f1, Fixed const &f2);
		Fixed static &max(Fixed &f1, Fixed &f2);
		const static Fixed	&max(Fixed const &f1, Fixed const &f2);
};

Fixed &min(Fixed &f1, Fixed &f2);
Fixed &max(Fixed &f1, Fixed &f2);
std::ostream &operator<<(std::ostream &out, const Fixed &src);

#endif

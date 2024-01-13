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
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &src);

#endif

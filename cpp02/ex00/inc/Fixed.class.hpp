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

#endif

#pragma once
#include <iomanip>

class Fixed
{
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed	&operator=(const Fixed &other);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int _value;
		static const int _rawBits;
};

std::ostream &operator<<( std::ostream & o, Fixed const & i );

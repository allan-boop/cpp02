#pragma once

#include <iomanip>

class Fixed
{
	public:
		//*************Constructeur/Destructeur******************/
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &fixed);
		~Fixed();

		//*************Surcharge d'operateur******************/
		Fixed				&operator=(const Fixed &other);
		bool 				operator>(const Fixed &other) const;
		bool 				operator<(const Fixed &other) const;
		bool 				operator>=(const Fixed &other) const;
		bool 				operator<=(const Fixed &other) const;
		bool 				operator==(const Fixed &other) const;
		bool 				operator!=(const Fixed &other) const;
		Fixed 				operator+(const Fixed &other) const;
		Fixed 				operator-(const Fixed &other) const;
		Fixed 				operator*(const Fixed &other) const;
		Fixed 				operator/(const Fixed &other) const;
		Fixed& 				operator++();
		Fixed 				operator++(int);
		Fixed& 				operator--();
		Fixed 				operator--(int);

		//*************Fonctions membres******************/
		int					getRawBits( void ) const;
		void				setRawBits( int const raw );
		float				toFloat( void ) const;
		int					toInt( void ) const;
		static Fixed& 		min(Fixed &a, Fixed &b);
		static const Fixed&	min(const Fixed &a, const Fixed &b);
		static Fixed& 		max(Fixed &a, Fixed &b);
		static const Fixed&	max(const Fixed &a, const Fixed &b);

	private:
		int					_value;
		static const int	_rawBits;
};

std::ostream &operator<<( std::ostream & o, Fixed const & i );

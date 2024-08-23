#include <iomanip>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed &operator=(const Fixed &other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:
		int _value;
		static const int _rawBits;
};
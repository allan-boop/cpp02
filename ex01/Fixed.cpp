#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_rawBits = 8;

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << _rawBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _rawBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) : _value(fixed._value) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->setRawBits(other.getRawBits());
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    float floatValue = static_cast<float>(fixed.getRawBits()) / (1 << Fixed::_rawBits);
    out << floatValue;
    return out;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits( int const raw ) {
	_value = raw;
}

float Fixed::toFloat( void ) const {
	return (float)_value / (1 << _rawBits);
}

int Fixed::toInt( void ) const {
	return _value >> _rawBits;
}
#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_rawBits = 8;


//********************************Constructeurs/Destructeur************************************//

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

//********************************Surcharges d'operateurs************************************//

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->setRawBits(other.getRawBits());
    }
    return *this;
}

bool Fixed::operator>(const Fixed &other) const {
    return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const {
    return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const {
	return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->_value != other._value;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
    o << i.toFloat();
    return o;
}

Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
    this->_value += 1;
    return *this;
}

Fixed& Fixed::operator--() {
	this->_value -= 1;
	return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--(*this);
	return temp;
}

//********************************Fonctions membres************************************//

int Fixed::getRawBits( void ) const {
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

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (Fixed &)(a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (Fixed &)(a < b ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (Fixed &)(a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return ((Fixed &)(a > b ? a : b));
}
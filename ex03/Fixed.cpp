#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_rawBits = 8;


//********************************Constructeurs/Destructeur************************************//

Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(const int value) : _value(value << _rawBits) {
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _rawBits))) {
}

Fixed::Fixed(const Fixed &fixed) : _value(fixed._value) {
	*this = fixed;
}

Fixed::~Fixed() {
}

//********************************Surcharges d'operateurs************************************//

Fixed &Fixed::operator=(const Fixed &other) {
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

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    float floatValue = static_cast<float>(fixed.getRawBits()) / (1 << Fixed::_rawBits);
    out << floatValue;
    return out;
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
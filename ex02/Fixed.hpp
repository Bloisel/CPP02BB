/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:20:55 by bloisel           #+#    #+#             */
/*   Updated: 2024/11/30 02:51:37 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H


#include <iostream>
#include <cmath>


class Fixed 
{
private:
    int _value;  
    static const int _fractionalBits = 8;  

public:
    
    Fixed() : _value(0) { }

   
    Fixed(int const intValue) 
    {
        _value = intValue << _fractionalBits;
    }

   
    Fixed(float const floatValue) 
    {
        _value = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
    }

  
    Fixed(const Fixed& other) : _value(other._value) { }

  
    ~Fixed() { }

    
    Fixed& operator=(const Fixed& other) 
    {
        if (this != &other) 
        {
            _value = other._value;
        }
        return *this;
    }

   
    float toFloat() const 
    {
        return static_cast<float>(_value) / (1 << _fractionalBits);
    }

   
    int toInt() const 
    {
        return _value >> _fractionalBits;
    }

    
    friend std::ostream& operator<<(std::ostream& out, const Fixed& fixed) 
    {
        out << fixed.toFloat();
        return out;
    }

   
    int getRawBits() const { return _value; }
    void setRawBits(int const raw) { _value = raw; }

   
    bool operator>(const Fixed& other) const { return _value > other._value; }
    bool operator<(const Fixed& other) const { return _value < other._value; }
    bool operator>=(const Fixed& other) const { return _value >= other._value; }
    bool operator<=(const Fixed& other) const { return _value <= other._value; }
    bool operator==(const Fixed& other) const { return _value == other._value; }
    bool operator!=(const Fixed& other) const { return _value != other._value; }


    Fixed operator+(const Fixed& other) const 
    {
        Fixed result;
        result.setRawBits(this->_value + other.getRawBits());
        return result;
    }

    Fixed operator-(const Fixed& other) const 
    {
        Fixed result;
        result.setRawBits(this->_value - other.getRawBits());
        return result;
    }

    Fixed operator*(const Fixed& other) const 
    {
        Fixed result;
        result.setRawBits((this->_value * other.getRawBits()) >> _fractionalBits);
        return result;
    }

    Fixed operator/(const Fixed& other) const 
    {
        Fixed result;
        if (other.getRawBits() != 0) 
        {
            result.setRawBits((this->_value << _fractionalBits) / other.getRawBits());
        } 
        else 
        {
            std::cerr << "Error: Division by zero" << std::endl;
        }
        return result;
    }

   
    Fixed& operator++() 
    {  
        _value++;
        return *this;
    }

    Fixed operator++(int) 
    {  
        Fixed temp = *this;
        ++(*this);
        return temp;
    }

    Fixed& operator--() 
    {  
        _value--;
        return *this;
    }

    Fixed operator--(int) 
    {  
        Fixed temp = *this;
        --(*this);
        return temp;
    }

    
    static Fixed& min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }
    static const Fixed& min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }
    static Fixed& max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }
    static const Fixed& max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }
};





#endif
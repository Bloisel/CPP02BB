/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:20:55 by bloisel           #+#    #+#             */
/*   Updated: 2024/11/30 03:04:04 by bloisel          ###   ########.fr       */
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
  
    Fixed() : _value(0) 
    {
        std::cout << "Default constructor called" << std::endl;
    }

    
    Fixed(int const intValue) 
    {
        std::cout << "Int constructor called" << std::endl;
        _value = intValue << _fractionalBits;  
    }

   
    Fixed(float const floatValue) 
    {
        std::cout << "Float constructor called" << std::endl;
        _value = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));  
    }

   
    Fixed(const Fixed& other)  
    {
        std::cout << "Copy constructor called" << std::endl;
        this->_value = other._value;
    }

    
    Fixed& operator=(const Fixed& other) 
    {
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &other) 
        {
            this->_value = other._value;
        }
        return *this;
    }

    
    ~Fixed() 
    {
        std::cout << "Destructor called" << std::endl;
    }

    
    int getRawBits() const 
    {
        std::cout << "getRawBits member function called" << std::endl;
        return this->_value;
    }

   
    void setRawBits(int const raw) 
    {
        std::cout << "setRawBits member function called" << std::endl;
        this->_value = raw;
    }

  
    float toFloat() const 
    {
        return static_cast<float>(_value) / (1 << _fractionalBits);
    }

    
    int toInt() const 
    {
        return _value >> _fractionalBits;
    }
    
};

 std::ostream& operator<<(std::ostream& out, const Fixed& fixed);


#endif
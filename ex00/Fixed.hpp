/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:20:55 by bloisel           #+#    #+#             */
/*   Updated: 2024/11/15 03:21:04 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>


class Fixed {
private:
    int _value;  // pour stocker la valeur du nombre en virgule fixe
    static const int _fractionalBits = 8;  // nombre de bits de la partie fractionnaire (fixé à 8)

public:
    // Constructeur par défaut
    Fixed() : _value(0) 
    {
        std::cout << "Default constructor called" << std::endl;
    }

    // Constructeur de recopie
    Fixed(const Fixed& other) : _value(other._value) 
    {
        std::cout << "Copy constructor called" << std::endl;
    }

    // Surcharge de l’opérateur d’affectation
    Fixed& operator=(const Fixed& other) 
    {
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &other) {
            this->_value = other._value;
        }
        return *this;
    }

    // Destructeur
    ~Fixed() 
    {
        std::cout << "Destructor called" << std::endl;
    }

    // Fonction membre pour obtenir la valeur brute
    int getRawBits() const 
    {
        std::cout << "getRawBits member function called" << std::endl;
        return this->_value;
    }

    // Fonction membre pour définir la valeur brute
    void setRawBits(int const raw) {
        std::cout << "setRawBits member function called" << std::endl;
        this->_value = raw;
    }
};






#endif
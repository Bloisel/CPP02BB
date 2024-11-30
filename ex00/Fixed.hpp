/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:20:55 by bloisel           #+#    #+#             */
/*   Updated: 2024/11/30 00:55:01 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>


class Fixed 
{
private:
    int _fixe; 
    static const int _bit = 8;
    
public:
    Fixed(void); // Constructeur par défaut
    Fixed(Fixed const &src); // Constructeur de recopie
    
    // Surcharge de l’opérateur d’affectation
    Fixed& operator=(Fixed const &rhs);

    // Destructeur
    ~Fixed() 
    {
        std::cout << "Destructor called" << std::endl;
    }
   
    int getRawBits() const 
    {
        std::cout << "getRawBits member function called" << std::endl;
        return this->_fixe;
    }

    void setRawBits(int const raw) 
    {
        std::cout << "setRawBits member function called" << std::endl;
        this->_fixe = raw;
    }
};






#endif
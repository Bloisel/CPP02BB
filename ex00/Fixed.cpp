/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:13:23 by bloisel           #+#    #+#             */
/*   Updated: 2024/11/26 00:51:29 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixe(0) 
{
	std::cout << "Default constructor called" << std::endl;
	return ;
};

Fixed::Fixed(Fixed const &src)
{
		std::cout << "Copy costructor called" << std::endl;
		*this = src;
		return ;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
			this->_fixe = rhs.getRawBits();
	return *this;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:20:11 by bloisel           #+#    #+#             */
/*   Updated: 2024/11/30 04:12:39 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Fixed.hpp"

int main() 
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    
    
    std::cout << a << std::endl;        //  0
    std::cout << ++a << std::endl;      //  0.00390625
    std::cout << a << std::endl;        //  0.00390625
    std::cout << a++ << std::endl;      //  0.00390625
    std::cout << a << std::endl;        // 0.0078125
    std::cout << b << std::endl;        //  10.1016
    std::cout << Fixed::max(a, b) << std::endl;  //  10.1016
    // if (a > b) 
    // {
    //     std::cout << "a est plus grand que b" << std::endl;
    // } else 
    // {
    //     std::cout << "a n'est pas plus grand que b" << std::endl;
    // }

    return 0;
}
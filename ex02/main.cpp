/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:20:11 by bloisel           #+#    #+#             */
/*   Updated: 2024/11/15 03:31:28 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    
    // Affichage des valeurs
    std::cout << a << std::endl;        // Devrait afficher 0
    std::cout << ++a << std::endl;      // Pré-incrémentation : 0.00390625
    std::cout << a << std::endl;        // Devrait afficher 0.00390625
    std::cout << a++ << std::endl;      // Post-incrémentation : 0.00390625
    std::cout << a << std::endl;        // Devrait afficher 0.0078125
    std::cout << b << std::endl;        // Devrait afficher 10.1016
    std::cout << Fixed::max(a, b) << std::endl;  // Devrait afficher 10.1016

    return 0;
}
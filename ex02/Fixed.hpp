/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 00:20:55 by bloisel           #+#    #+#             */
/*   Updated: 2024/11/15 03:32:11 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H


#include <iostream>
#include <cmath>


class Fixed 
{
private:
    int _value;  // Valeur stockée en virgule fixe
    static const int _fractionalBits = 8;  // Nombre de bits de la partie fractionnaire (fixé à 8)

public:
    // Constructeur par défaut : initialise _value à 0
    Fixed() : _value(0) { }

    // Constructeur prenant un entier : convertit l'entier en nombre à virgule fixe
    Fixed(int const intValue) {
        _value = intValue << _fractionalBits;
    }

    // Constructeur prenant un flottant : convertit le flottant en nombre à virgule fixe
    Fixed(float const floatValue) {
        _value = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
    }

    // Constructeur de recopie
    Fixed(const Fixed& other) : _value(other._value) { }

    // Destructeur
    ~Fixed() { }

    // Surcharge de l’opérateur d’affectation
    Fixed& operator=(const Fixed& other) {
        if (this != &other) {
            _value = other._value;
        }
        return *this;
    }

    // Conversion en flottant
    float toFloat() const {
        return static_cast<float>(_value) / (1 << _fractionalBits);
    }

    // Conversion en entier
    int toInt() const {
        return _value >> _fractionalBits;
    }

    // Surcharge de l'opérateur d'insertion pour l'affichage
    friend std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
        out << fixed.toFloat();
        return out;
    }

    // Fonctions membres getRawBits et setRawBits
    int getRawBits() const { return _value; }
    void setRawBits(int const raw) { _value = raw; }

    // Surcharge des opérateurs de comparaison
    bool operator>(const Fixed& other) const { return _value > other._value; }
    bool operator<(const Fixed& other) const { return _value < other._value; }
    bool operator>=(const Fixed& other) const { return _value >= other._value; }
    bool operator<=(const Fixed& other) const { return _value <= other._value; }
    bool operator==(const Fixed& other) const { return _value == other._value; }
    bool operator!=(const Fixed& other) const { return _value != other._value; }

    // Surcharge des opérateurs arithmétiques
    Fixed operator+(const Fixed& other) const {
        Fixed result;
        result.setRawBits(this->_value + other.getRawBits());
        return result;
    }

    Fixed operator-(const Fixed& other) const {
        Fixed result;
        result.setRawBits(this->_value - other.getRawBits());
        return result;
    }

    Fixed operator*(const Fixed& other) const {
        Fixed result;
        result.setRawBits((this->_value * other.getRawBits()) >> _fractionalBits);
        return result;
    }

    Fixed operator/(const Fixed& other) const {
        Fixed result;
        if (other.getRawBits() != 0) {
            result.setRawBits((this->_value << _fractionalBits) / other.getRawBits());
        } else {
            std::cerr << "Error: Division by zero" << std::endl;
        }
        return result;
    }

    // Opérateurs d'incrémentation et de décrémentation
    Fixed& operator++() {  // Pré-incrémentation
        _value++;
        return *this;
    }

    Fixed operator++(int) {  // Post-incrémentation
        Fixed temp = *this;
        ++(*this);
        return temp;
    }

    Fixed& operator--() {  // Pré-décrémentation
        _value--;
        return *this;
    }

    Fixed operator--(int) {  // Post-décrémentation
        Fixed temp = *this;
        --(*this);
        return temp;
    }

    // Fonctions membres statiques min et max
    static Fixed& min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }
    static const Fixed& min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }
    static Fixed& max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }
    static const Fixed& max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }
};





#endif
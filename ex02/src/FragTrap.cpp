/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:18:09 by azerfaou          #+#    #+#             */
/*   Updated: 2025/05/30 19:16:35 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"
#include "../include/colors.hpp"
#include <iostream>
#include <string>

// Default constructor
FragTrap::FragTrap() : ClapTrap("DefaultFragTrap") // Call ClapTrap constructor with default _name
{
	std::cout << "Default FragTrap constructed." << std::endl;
	_hitPoints = 100; // FragTrap specific hit points
	_energyPoints = 100; // FragTrap specific energy points
	_attackDamage = 30; // FragTrap specific attack damage
}

// Constructor
FragTrap::FragTrap(std::string newName) : ClapTrap(newName) 
{
	std::cout << "FragTrap " << newName << " constructed." << std::endl;
	_hitPoints = 100; // FragTrap specific hit points
	_energyPoints = 100; // FragTrap specific energy points
	_attackDamage = 30; // FragTrap specific attack damage
}

// Copy assignment operator
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap " << _name << "copy constructor called" << std::endl;
	*this = other;
}

//Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " is destroyed" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		// ClapTrap::operator=(other);
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	return *this;
}

// attack method
void FragTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " 
			<< _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else if (_hitPoints <= 0)
		std::cout << RED << "FragTrap " << _name << " is out of hit points!" << RESET << std::endl;
	else
		std::cout << RED << "FragTrap " << _name << " is out of energy points!" << RESET << std::endl;
}

// highFivesGuys method
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " : Come on  guys give me Highh fiveeeee !! " << std::endl;
}
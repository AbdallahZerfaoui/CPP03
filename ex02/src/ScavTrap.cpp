/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 00:11:52 by azerfaou          #+#    #+#             */
/*   Updated: 2025/05/30 19:15:57 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"
#include <iostream>
#include <string>

// Default constructor
ScavTrap::ScavTrap() : ClapTrap("DefaultScavTrap") // Call ClapTrap constructor with default name
{
	std::cout << "Default ScavTrap constructed." << std::endl;
	_hitPoints = 100; // ScavTrap specific hit points
	_energyPoints = 50; // ScavTrap specific energy points
	_attackDamage = 20; // ScavTrap specific attack damage
}

// Constructor
ScavTrap::ScavTrap(std::string newName) : ClapTrap(newName) 
{
	std::cout << "ScavTrap " << newName << " constructed." << std::endl;
	_hitPoints = 100; // ScavTrap specific hit points
	_energyPoints = 50; // ScavTrap specific energy points
	_attackDamage = 20; // ScavTrap specific attack damage
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << _name << "copy constructor called" << std::endl;
    *this = other;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " is destroyed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		// ClapTrap::operator=(other);
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	return *this;
}

// attack method
void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " is out of hit points and cannot attack!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << _name << " is out of energy and cannot attack!" << std::endl;
	}
}

//Gard Gate method
void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is now in Gatekeeper mode!" << std::endl;
}
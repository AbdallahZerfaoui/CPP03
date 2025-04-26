/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 00:11:52 by azerfaou          #+#    #+#             */
/*   Updated: 2025/04/27 00:11:53 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"
#include <iostream>
#include <string>

// Default constructor
ScavTrap::ScavTrap() : ClapTrap("DefaultScavTrap") // Call ClapTrap constructor with default name
{
	std::cout << "Default ScavTrap constructed." << std::endl;
	hitPoints = 100; // ScavTrap specific hit points
	energyPoints = 50; // ScavTrap specific energy points
	attackDamage = 20; // ScavTrap specific attack damage
}

// Constructor
ScavTrap::ScavTrap(std::string newName) : ClapTrap(newName) 
{
	std::cout << "ScavTrap " << newName << " constructed." << std::endl;
	hitPoints = 100; // ScavTrap specific hit points
	energyPoints = 50; // ScavTrap specific energy points
	attackDamage = 20; // ScavTrap specific attack damage
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << name << "copy constructor called" << std::endl;
    *this = other;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " is destroyed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	return *this;
}

// attack method
void ScavTrap::attack(const std::string& target)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		energyPoints--;
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	}
	else if (hitPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " is out of hit points and cannot attack!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << name << " is out of energy and cannot attack!" << std::endl;
	}
}

//Gard Gate method
void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name << " is now in Gatekeeper mode!" << std::endl;
}
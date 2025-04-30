/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:18:09 by azerfaou          #+#    #+#             */
/*   Updated: 2025/04/30 12:25:21 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"
#include <iostream>
#include <string>

// Default constructor
FragTrap::FragTrap() : ClapTrap("DefaultFragTrap") // Call ClapTrap constructor with default name
{
	std::cout << "Default FragTrap constructed." << std::endl;
	hitPoints = 100; // FragTrap specific hit points
	energyPoints = 100; // FragTrap specific energy points
	attackDamage = 30; // FragTrap specific attack damage
}

// Constructor
FragTrap::FragTrap(std::string newName) : ClapTrap(newName) 
{
	std::cout << "FragTrap " << newName << " constructed." << std::endl;
	hitPoints = 100; // FragTrap specific hit points
	energyPoints = 100; // FragTrap specific energy points
	attackDamage = 30; // FragTrap specific attack damage
}

// Copy assignment operator
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap " << name << "copy constructor called" << std::endl;
	*this = other;
}

//Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " is destroyed" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	return *this;
}

// attack method
void FragTrap::attack(const std::string& target)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		std::cout << "FragTrap " << name << " attacks " << target << ", causing " 
			<< attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
	else if (hitPoints <= 0)
		std::cout << RED << "FragTrap " << name << " is out of hit points!" << RESET << std::endl;
	else
		std::cout << RED << "FragTrap " << name << " is out of energy points!" << RESET << std::endl;
}

// highFivesGuys method
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " : Come on  guys give me Highh fiveeeee !! " << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 00:11:47 by azerfaou          #+#    #+#             */
/*   Updated: 2025/05/24 15:12:05 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include <iostream>

// Default constructor
ClapTrap::ClapTrap():
	_name("Default"),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string newName):
	_name(newName),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other):
	_name(other._name),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

// Copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	return *this;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

// attack method
void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is out of hit points and cannot attack!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " is out of energy points and cannot attack!" << std::endl;
	}
}

// takeDamage method
void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		if (_hitPoints >= (int)amount)
		{
			_hitPoints -= amount;
			std::cout << "ClapTrap " << _name << " takes " << amount << " damage, and has " << _hitPoints << " left!" << std::endl;
		}
		else
		{
			_hitPoints = 0; // Ensure hitPoints do not go negative
			std::cout << "ClapTrap " << _name << " takes " << amount << " damage, and has 0 hit points left!" << std::endl;
		}
	}
	else
	{
		std::cout << "Pray for your brother " << _name << ", he is already out of hit points!" << std::endl;
	}
}

// beRepaired method
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " is repaired by " << amount << ", and has " << _hitPoints << " hit points left!" << std::endl;
	}
	else if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is out of hit points and cannot be repaired!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " is out of energy points and cannot be repaired!" << std::endl;
	}
}

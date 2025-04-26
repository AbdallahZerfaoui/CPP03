#include "../include/ClapTrap.hpp"
#include <iostream>

// Default constructor
ClapTrap::ClapTrap():
	name("Default"),
	hitPoints(10),
	energyPoints(10),
	attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string newName):
	name(newName),
	hitPoints(10),
	energyPoints(10),
	attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other):
	name(other.name),
	hitPoints(other.hitPoints),
	energyPoints(other.energyPoints),
	attackDamage(other.attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

// Copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
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
	if (hitPoints > 0 && energyPoints > 0)
	{
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	}
	else if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is out of hit points and cannot attack!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << name << " is out of energy points and cannot attack!" << std::endl;
	}
}

// takeDamage method
void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints > 0)
	{
		if (hitPoints >= (int)amount)
		{
			hitPoints -= amount;
			std::cout << "ClapTrap " << name << " takes " << amount << " damage, and has " << hitPoints << " left!" << std::endl;
		}
		else
		{
			hitPoints = 0; // Ensure hitPoints do not go negative
			std::cout << "ClapTrap " << name << " takes " << amount << " damage, and has 0 hit points left!" << std::endl;
		}
	}
	else
	{
		std::cout << "Pray for your brother " << name << ", he is already out of hit points!" << std::endl;
	}
}

// beRepaired method
void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints > 0 && energyPoints > 0)
	{
		energyPoints--;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " is repaired by " << amount << ", and has " << hitPoints << " hit points left!" << std::endl;
	}
	else if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is out of hit points and cannot be repaired!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << name << " is out of energy points and cannot be repaired!" << std::endl;
	}
}

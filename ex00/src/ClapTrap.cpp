#include "../include/ClapTrap.hpp"
#include <iostream>

// Default constructor
ClapTrap::ClapTrap()
{
	// std::cout << "ClapTrap default constructor called" << std::endl;
	// Initialize member variables here (e.g., this->_name = "Default Name";)
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other)
{
	// std::cout << "ClapTrap copy constructor called" << std::endl;
	// Copy member variables from 'other'.
	// Often done by calling the copy assignment operator:
    *this = other;
    // Alternatively, copy them directly here:
    // 
	// Copy member variables
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
}

// Copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	// std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		// Clean up existing resources if necessary

        
	// Copy member variables
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
		// Assign member variables from 'other' (assigned above or add more manually)
	}
	return *this;
}

// Destructor
ClapTrap::~ClapTrap()
{
	// std::cout << "ClapTrap destructor called" << std::endl;
	// Clean up resources if necessary
}

// attack method
void ClapTrap::attack(const std::string& target)
{
	// Method implementation here
}

// takeDamage method
void ClapTrap::takeDamage(unsigned int amount)
{
	// Method implementation here
}

// beRepaired method
void ClapTrap::beRepaired(unsigned int amount)
{
	// Method implementation here
}

// Add other member function definitions here (declared above or add more manually)

// Optional: Overload stream insertion operator definition
// std::ostream& operator<<(std::ostream& os, const ClapTrap& obj)
// {
//     // Output object state to stream
//     return os;
// }

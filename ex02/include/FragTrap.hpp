#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

// Colors
# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();                            // Default constructor
		FragTrap(std::string newName);
		FragTrap(const FragTrap& other); // Copy constructor
		FragTrap& operator=(const FragTrap& other); // Copy assignment operator
		~FragTrap();                           // Destructor
		void attack(const std::string& target);
		void highFivesGuys(void); // New ability
	private:
};

#endif


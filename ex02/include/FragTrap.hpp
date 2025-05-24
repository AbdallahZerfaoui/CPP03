#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class FragTrap : public ClapTrap
{
	public:
		FragTrap();                                   // Default constructor
		FragTrap(std::string newName);
		FragTrap(const FragTrap& other);             // Copy constructor
		FragTrap& operator=(const FragTrap& other); // Copy assignment operator
		~FragTrap();                               // Destructor
		void attack(const std::string& target);
		void highFivesGuys(void);                 // New ability
	private:
};

#endif


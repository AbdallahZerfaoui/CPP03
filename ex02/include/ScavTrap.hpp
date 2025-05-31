#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();                            // Default constructor
		ScavTrap(std::string newName);
		ScavTrap(const ScavTrap& other); // Copy constructor
		ScavTrap& operator=(const ScavTrap& other); // Copy assignment operator
		~ScavTrap();                           // Destructor
		void attack(const std::string& target);
		void guardGate(void); // New ability
	private:
};

// Optional: Overload stream insertion operator
// std::ostream& operator<<(std::ostream& os, const ClapTrap& obj);

#endif
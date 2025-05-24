#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>   // Common include, adjust as needed

class ClapTrap
{
	protected:
		std::string _name;
		int _hitPoints; //the health of the ClapTrap
		int _energyPoints;
		int _attackDamage;

	public:
		// Canonical Form
		ClapTrap();                            // Default constructor
		ClapTrap(std::string newName);
		ClapTrap(const ClapTrap& other); // Copy constructor
		ClapTrap& operator=(const ClapTrap& other); // Copy assignment operator
		~ClapTrap();                           // Destructor
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

// Optional: Overload stream insertion operator
// std::ostream& operator<<(std::ostream& os, const ClapTrap& obj);

#endif

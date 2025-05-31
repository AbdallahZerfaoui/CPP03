#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>


class ClapTrap
{
	private:
		std::string _name;
		int _hitPoints; //the health of the ClapTrap
		int _energyPoints;
		int _attackDamage;

	public:
		// Canonical Form
		ClapTrap();                                  // Default constructor
		ClapTrap(std::string newName);
		ClapTrap(const ClapTrap& other);             // Copy constructor
		ClapTrap& operator=(const ClapTrap& other);  // Copy assignment operator
		~ClapTrap();                                 // Destructor
		// Member functions
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif

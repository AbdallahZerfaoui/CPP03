#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream> // Common include, adjust as needed
# include <string>   // Common include, adjust as needed

// Colors
# define RED "\033[31m"
# define GREEN "\033[32m"
# define RESET "\033[0m"

class ClapTrap
{
	private:
		std::string name;
		int hitPoints; //the health of the ClapTrap
		int energyPoints;
		int attackDamage;

		// Member variables (declared above or add more manually)

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

		// Add other member functions here (declared above or add more manually)
};

// Optional: Overload stream insertion operator (common 42 practice)
// std::ostream& operator<<(std::ostream& os, const ClapTrap& obj);

#endif

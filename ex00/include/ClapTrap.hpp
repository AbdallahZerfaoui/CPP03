#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream> // Common include, adjust as needed
# include <string>   // Common include, adjust as needed

// Add other necessary includes here

class ClapTrap
{
private:
	int hitPoints;
	int energyPoints;
	int attackDamage;

	// Member variables (declared above or add more manually)

public:
	// Canonical Form
	ClapTrap();                            // Default constructor
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

#endif /* CLAPTRAP_HPP */

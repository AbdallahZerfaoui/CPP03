#include <iostream>
#include "include/ClapTrap.hpp"

int main() 
{
	// Test Case 1: Basic functionality
	std::cout << "--- Test Case 1: Basic Actions ---" << std::endl;
	ClapTrap player1("HeroBot");
	player1.attack("Enemy1"); // Should print attack message, cost 1 energy (0 damage initially)
	player1.takeDamage(3);    // Should print damage message, reduce HP
	player1.beRepaired(2);    // Should print repair message, cost 1 energy, increase HP
	player1.attack("Enemy2"); // Another attack

	std::cout << std::endl;

	// Test Case 2: Running out of Energy
	std::cout << "--- Test Case 2: Running out of Energy ---" << std::endl;
	ClapTrap energyBot("EnergyBot");
	// Drain energy (10 energy points initially)
	for (int i = 0; i < 11; ++i) {
		energyBot.attack("Training Dummy"); // First 10 attacks cost energy, 11th fails
	}
	energyBot.beRepaired(5); // Should fail due to no energy

	std::cout << std::endl;

	// Test Case 3: Taking Fatal Damage and actions when dead
	std::cout << "--- Test Case 3: Taking Fatal Damage ---" << std::endl;
	ClapTrap fragileBot("FragileBot");
	fragileBot.takeDamage(5); // Takes 5 damage
	fragileBot.takeDamage(5); // Takes another 5 damage, should result in 0 HP and death message
	fragileBot.attack("Zombie");   // Should fail due to 0 HP
	fragileBot.beRepaired(1);  // Should fail due to 0 HP
	fragileBot.takeDamage(1);  // Should indicate already dead

	std::cout << std::endl;

	// Test Case 4: Large repair amount
	std::cout << "--- Test Case 4: Large Repair ---" << std::endl;
	ClapTrap repairBot("RepairBot");
	repairBot.takeDamage(8); // Take significant damage but survive
	repairBot.beRepaired(20); // Repair large amount (no max HP constraint specified)

	std::cout << std::endl;

	// Destructors will be called automatically as objects go out of scope
	std::cout << "--- End of main, destructors called ---" << std::endl;

	return 0;
}
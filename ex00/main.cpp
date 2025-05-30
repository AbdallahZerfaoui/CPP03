/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 00:11:36 by azerfaou          #+#    #+#             */
/*   Updated: 2025/05/24 16:05:12 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/ClapTrap.hpp"
#include "include/colors.hpp"


/**
 * @brief Main function to test ClapTrap class functionality.
 * 
 * It tests the following scenarios:
 * 1. Basic actions: attack, take damage, and repair.
 * 2. Running out of energy points: attempts to attack and repair when energy is depleted.
 * 3. Taking fatal damage: checks behavior when HP reaches zero.
 * 4. Large repair amount: tests repairing with a large value.
 *
 * @return int Exit status of the program.
 */
int main()
{
	// Test Case 1: Basic functionality
	std::cout << CYAN <<"--- Test Case 1: Basic Actions ---" << RESET << std::endl;
	ClapTrap player1("HeroBot");
	player1.attack("Enemy1"); // Should print attack message, cost 1 energy (0 damage initially)
	player1.takeDamage(3);    // Should print damage message, reduce HP
	player1.beRepaired(2);    // Should print repair message, cost 1 energy, increase HP
	player1.attack("Enemy2"); // Another attack

	std::cout << std::endl;

	// Test Case 2: Running out of Energy - Drain energy points
	std::cout << CYAN << "--- Test Case 2: Running out of Energy ---" << RESET << std::endl;
	ClapTrap energyBot("EnergyBot");
	// Drain energy (10 energy points initially)
	for (int i = 0; i < 11; ++i) {
		energyBot.attack("Training Dummy"); // First 10 attacks cost energy, 11th fails
	}
	energyBot.beRepaired(5); // Should fail due to no energy

	std::cout << std::endl;

	// Test Case 3: Taking Fatal Damage and actions when dead
	std::cout << CYAN << "--- Test Case 3: Taking Fatal Damage ---" << RESET << std::endl;
	ClapTrap fragileBot("FragileBot");
	fragileBot.takeDamage(5); // Takes 5 damage
	fragileBot.takeDamage(5); // Takes another 5 damage, should result in 0 HP and death message
	fragileBot.attack("Zombie");   // Should fail due to 0 HP
	fragileBot.beRepaired(1);  // Should fail due to 0 HP
	fragileBot.takeDamage(1);  // Should indicate already dead

	std::cout << std::endl;

	// Test Case 4: Large repair amount
	std::cout << CYAN << "--- Test Case 4: Large Repair ---" << RESET << std::endl;
	ClapTrap repairBot("RepairBot");
	repairBot.takeDamage(8); // Take significant damage but survive
	repairBot.beRepaired(20); // Repair large amount (no max HP constraint specified)

	std::cout << std::endl;

	// Destructors will be called automatically as objects go out of scope
	std::cout << CYAN << "--- End of main, destructors called ---" << RESET << std::endl;

	return 0;
}
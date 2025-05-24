/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 00:11:56 by azerfaou          #+#    #+#             */
/*   Updated: 2025/05/24 14:30:18 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "include/ClapTrap.hpp"
#include "include/ScavTrap.hpp"
#include "include/colors.hpp"


int main() 
{
	std::cout <<CYAN<< "--- Creating ClapTrap and ScavTrap Objects ---" <<RESET<< std::endl;

	// Test Construction Chaining:
	// ClapTrap constructor should be called first, then ScavTrap constructor.
	ClapTrap defaultClap("DefaultClap"); // Just for comparison/demonstration
	std::cout << std::endl;
	ScavTrap scavTrap1("GatekeeperUnit"); // The main object to test

	std::cout <<CYAN<< "\n--- Testing Basic ScavTrap Actions (Should use ScavTrap stats/messages) ---" <<RESET<< std::endl;

	// Test overridden attack
	scavTrap1.attack("Invader"); // Should use ScavTrap attack message and 20 damage

	// Test inherited takeDamage (should use ClapTrap message)
	scavTrap1.takeDamage(30); // Takes 30 damage from 100 HP

	// Test inherited beRepaired (should use ClapTrap message)
	scavTrap1.beRepaired(10); // Repairs 10 HP, costs 1 energy

	std::cout <<CYAN<< "\n--- Testing ScavTrap Special Ability ---" <<RESET<< std::endl;

	// Test the new guardGate ability
	scavTrap1.guardGate(); // Should print Gatekeeper message

	std::cout <<CYAN<< "\n--- Testing ScavTrap Energy and HP Logic (with ScavTrap stats) ---" <<RESET<< std::endl;

	// Test draining energy (ScavTrap has 50 energy)
	std::cout << "Draining energy..." << std::endl;
	for (int i = 0; i < 50; ++i) 
	{
		scavTrap1.attack("EnergyTarget"); // Should work for 50 calls
	}
	scavTrap1.attack("ShouldFailTarget"); // Should fail: No energy left
	scavTrap1.beRepaired(5);           // Should fail: No energy left

	// Test taking fatal damage (ScavTrap has effectively 100 - 30 + 10 = 80 HP now)
	std::cout << "\nTaking fatal damage..." << std::endl;
	scavTrap1.takeDamage(80); // Should result in 0 HP and indicate death
	scavTrap1.takeDamage(10); // Should indicate already dead

	// Test actions when dead
	scavTrap1.attack("DeadTarget");  // Should fail: 0 HP
	scavTrap1.beRepaired(10); // Should fail: 0 HP
	scavTrap1.guardGate();   // Test if death prevents guardGate (depends on implementation, prompt doesn't specify, but a robust implementation might check HP)

	std::cout <<CYAN<< "\n--- End of main, objects going out of scope ---" <<RESET<< std::endl;

	// Test Destruction Chaining:
	// scavTrap1 destructor should be called first, then its base (ClapTrap) destructor.
	// defaultClap destructor will be called next.

	return 0; // Objects are destroyed here
}
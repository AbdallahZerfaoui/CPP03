/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azerfaou <azerfaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:25:37 by azerfaou          #+#    #+#             */
/*   Updated: 2025/05/31 12:34:19 by azerfaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/FragTrap.hpp"
#include "include/colors.hpp"
#include <iostream>
#include <string>

// Helper function to print a section header for clarity
void printSectionHeader(const std::string& title) 
{
    std::cout << std::endl << CYAN << "--- " << title << " ---" <<RESET<< std::endl;
}

int main() 
{
    // Test Case 1: Basic Construction and Destruction Chaining
    // Use a scope block {} to explicitly control when the destructor is called
    printSectionHeader("Testing FragTrap Construction and Destruction Chaining");
    {
        FragTrap fraggy("Fraggy McFrag");
        std::cout << "\n'Fraggy McFrag' FragTrap created within this scope." << std::endl;

        // Perform a few actions while the object exists
        fraggy.attack("a training dummy");
        fraggy.takeDamage(10);
        fraggy.beRepaired(5);
        fraggy.highFivesGuys(); // Test the special ability early

        std::cout << "\n'Fraggy McFrag' is about to go out of scope." << std::endl;
    } // fraggy goes out of scope here, triggering its destructor (and then the base destructor)
    std::cout << "\n'Fraggy McFrag' FragTrap has been destroyed." << std::endl;

    // Test Case 2: Initial Attributes and Core Functionality
    printSectionHeader("Testing FragTrap Initial Attributes and Core Methods");
    FragTrap robo("Robo-Frag");
    std::cout <<GREEN<< "\n'Robo-Frag' FragTrap created (HP=100, EP=100, AD=30)."<<RESET<< std::endl;

    // Test Attack method (should use 30 AD and consume 1 EP per attack)
    printSectionHeader("Testing Attack");
    robo.attack("an enemy scout");
    robo.attack("another scout");
    // Attack until energy is low/depleted
    for (int i = 0; i < 98; i++) { // Attack 98 more times to drain energy (100 - 2 = 98)
         robo.attack("random target " + std::to_string(i + 1));
    }
    std::cout <<GREEN<< "Robo-Frag's energy should now be 0." <<RESET<< std::endl;
    robo.attack("a target when out of energy"); // Should fail due to lack of energy

    // Test TakeDamage method
    printSectionHeader("Testing Take Damage");
    FragTrap tank("Tank-Frag");
    std::cout << "\n'Tank-Frag' FragTrap created (HP=100)." << std::endl;
    tank.takeDamage(20); // HP: 100 -> 80
    tank.takeDamage(50); // HP: 80 -> 30
    tank.takeDamage(40); // HP: 30 -> -10 (Should be treated as 0 or less)
    std::cout << "'Tank-Frag's HP should now be 0 or less (effectively dead)." << std::endl;
    tank.takeDamage(10); // Should indicate it's already dead

    // Test BeRepaired method
    printSectionHeader("Testing Be Repaired");
    FragTrap medic("Medi-Frag");
    std::cout <<GREEN<< "\n'Medi-Frag' FragTrap created (HP=100, EP=100)." <<RESET<< std::endl;
    medic.takeDamage(70); // Damage first: HP 100 -> 30, Energy 100
    medic.beRepaired(10); // HP 30 -> 40, Energy 100 -> 99
    medic.beRepaired(30); // HP 40 -> 70, Energy 99 -> 98
    // Repair until energy is low/depleted
     for (int i = 0; i < 98; ++i) { // Repair 98 more times to drain energy (98 - 1 - 1 = 96 repairs, needs 98 total)
        medic.beRepaired(1);
     }
    std::cout <<GREEN<< "Medi-Frag's energy should now be 0, HP should be maxed out if it repaired enough." <<RESET<< std::endl;
    medic.beRepaired(10); // Should fail due to lack of energy

    // Test Actions When Dead
    printSectionHeader("Testing Actions When Dead");
    std::cout << "Using 'Tank-Frag' which should be dead." << std::endl;
    tank.attack("something while dead"); // Should fail
    tank.beRepaired(20);      // Should fail
    tank.highFivesGuys();     // *Assumption: Special ability might work even when dead/out of energy. Test this.*

    // Test Special Ability: highFivesGuys
    printSectionHeader("Testing highFivesGuys Special Ability");
    FragTrap party_bot("Party-Frag");
    party_bot.highFivesGuys();
    // Test high five when low on HP/Energy (assuming it doesn't require energy/HP)
    party_bot.takeDamage(99);
    party_bot.highFivesGuys(); // Should still work
    for (int i = 0; i < 100; ++i) party_bot.attack("air"); // Drain energy
    party_bot.highFivesGuys(); // Should still work

    // Test Case 3: Multiple FragTrap Instances
    printSectionHeader("Testing Multiple FragTrap Instances");
    FragTrap frag1("FragOne");
    FragTrap frag2("FragTwo");

    frag1.attack("FragTwo (conceptually)"); // frag1 attacks
    frag2.takeDamage(15); // frag2 takes damage
    frag1.highFivesGuys();
    frag2.beRepaired(10);

    std::cout <<GREEN<< "\nBoth FragOne and FragTwo should exist and function independently." <<RESET<< std::endl;

    printSectionHeader("All FragTrap Tests Completed");

    // All objects created in main scope will be destroyed here automatically
    // Observe their destruction messages.

    return 0;
}
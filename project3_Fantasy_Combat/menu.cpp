/***********************************************************************************************
 * * Program name: 	testDriver.cpp
 * * Author: 		Benjamin Hillen
 * * Date: 		9 November 2019
 * * Description: 	Test driver for the fantasy combat simulator program, allows user to 
 * * 			choose two characters to fight until one character dies.
**********************************************************************************************/

#include "menu.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include <cstdlib>
#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int menu()
{
   const std::string VAMPIRE = "1";			//Character choice legend

   const std::string BARBARIAN = "2";

   const std::string BLUEMEN = "3";

   const std::string MEDUSA = "4";

   const std::string HARRYPOTTER = "5";

   const int QUIT = 2;

   Character* c1 = NULL;

   Character* c2 = NULL;

   std::string userInput = "";

   int rounds = 0;

   int damage = 0;

   int choice = 0;

   //present the Play/Quit option to the user and prompt for input until a valid input
   //is received
   do
   {
      cout << "\n\nFANTASY COMBAT - START MENU\n\n";

      cout << "1. Play\n2. Quit\n\n";

      getline(cin, userInput);

      if (userInput != "1" && userInput != "2")
      {
	 cout << "Invalid input, please enter 1 to play or 2 to quit.\n";
      }

   } while (userInput != "1" && userInput != "2");

   choice = stoi(userInput);

   //if the user chooses to quit, end the menu presentation and return 2 to indicate quit
   if (choice == QUIT)
   {
      return choice;
   }

   //inform user about the general functionality of the game
   cout << "\n\nFANTASY COMBAT - FIGHTER SELECTION\n\n";

   cout << "Welcome to fantasy combat simulator, this program has you select two fighters to";
   cout << " square off against each other\nin mortal combat! The program will continue to run";
   cout << " until one fighter runs out of strength points, no sooner and no later.\nChoose your first fighter!";

   //ask user to choose the first fighter, informing them of each fighter's characteristics and
   //special abilities and that the first fighter will make the first attack roll in combat
   do
   {
      cout << "\n\nSELECT FIRST FIGHTER\n(NOTE: this first fighter will attack first once combat begins)\n";

      cout << "1. Vampire --- Attack(atk) = 1d12 --- Defense(def) = 1d6*(Charm) --- Armor = 1 --- Strength Points = 18\n";
      cout << "2. Barbarian --- Atk = 2d6 --- Def = 2d6 --- Armor = 0 --- Strength Points = 12\n";
      cout << "3. Blue Men --- Atk = 2d10 --- Def = 3d6 --- Armor = 3 --- Strength Points = 12*(Mob)\n";
      cout << "4. Medusa --- Atk = 2d6*(Glare) --- Def = 1d6 --- Armor = 3 --- Strength Points = 8\n";
      cout << "5. Harry Potter --- Atk = 2d6 --- Def = 2d6 --- Armor = 0 --- Strength Points = 10/20*(Hogwarts)\n";

      cout << "\nSPECIAL ABILITIES\nCharm: for each attack against the vampire, there is a 50% chance that the";
      cout << " opponent does not actually attack them.\nMob: for every 4 points of damage received, Blue Men";
      cout << " lose one defense die.\nGlare: if Medusa rolls a 12, the opponent receives an absurd amount of damage.\n";
      cout << "Hogwarts: if Harry's strength reaches 0 or less, he comes back with 20 strength. Only happens once per game.\n\n";

      getline(cin, userInput);

      if (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4" && userInput != "5")
      {
	 cout << "Error, invalid input. Please enter 1, 2, 3, 4, or 5 for the first fighter\n";
      }

   } while (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4" && userInput != "5");

   if (userInput == VAMPIRE)
   {
      c1 = new Vampire;
   }

   else if (userInput == BARBARIAN)
   {
      c1 = new Barbarian;
   }

   else if (userInput == BLUEMEN)
   {
      c1 = new BlueMen;
   }

   else if (userInput == MEDUSA)
   {
      c1 = new Medusa;
   }

   else if (userInput == HARRYPOTTER)
   {
      c1 = new HarryPotter;
   }

   c1->printDescription();						//confirm the description of the first
   									//fighter

   cout << "\nTime to choose the second fighter!\n";

   //ask user to choose second fighter, informing them of characteristics, special abilities,
   //and that the second fighter rolls defense first in combat
   do
   {
      cout << "\n\nSELECT SECOND FIGHTER\n(NOTE: this second fighter will defend first once combat begins)\n";

      cout << "1. Vampire --- Attack(atk) = 1d12 --- Defense(def) = 1d6*(Charm) --- Armor = 1 --- Strength Points = 18\n";
      cout << "2. Barbarian --- Atk = 2d6 --- Def = 2d6 --- Armor = 0 --- Strength Points = 12\n";
      cout << "3. Blue Men --- Atk = 2d10 --- Def = 3d6 --- Armor = 3 --- Strength Points = 12*(Mob)\n";
      cout << "4. Medusa --- Atk = 2d6*(Glare) --- Def = 1d6 --- Armor = 3 --- Strength Points = 8\n";
      cout << "5. Harry Potter --- Atk = 2d6 --- Def = 2d6 --- Armor = 0 --- Strength Points = 10/20*(Hogwarts)\n";

      cout << "\nSPECIAL ABILITIES\nCharm: for each attack against the vampire, there is a 50% chance that the";
      cout << " opponent does not actually attack them.\nMob: for every 4 points of damage received, Blue Men";
      cout << " lose one defense die\nGlare: if Medusa rolls a 12, the opponent receives an absurd amount of damage\n";
      cout << "Hogwarts: if Harry's strength reaches 0 or less, he comes back with 20 strength. Only happens once per game\n\n";

      getline(cin, userInput);

      if (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4" && userInput != "5")
      {
	 cout << "Error, invalid input. Please enter 1, 2, 3, 4, or 5 for the first fighter\n";
      }

   } while (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4" && userInput != "5");

   if (userInput == VAMPIRE)
   {
      c2 = new Vampire;
   }

   else if (userInput == BARBARIAN)
   {
      c2 = new Barbarian;

      cout << "\nAlright, your second fighter is a Barbarian!\n";
   }

   else if (userInput == BLUEMEN)
   {
      c2 = new BlueMen;
   }

   else if (userInput == MEDUSA)
   {
      c2 = new Medusa;
   }

   else if (userInput == HARRYPOTTER)
   {
      c2 = new HarryPotter;
   }

   c2->printDescription();

   cout << "\nThe Fighters have been chosen, let the battle commence!\n\n";

   //as long as both characters have strength points, have them continue to fight each other
   //by rolling attack for c1 first and then for c2 if c2 survives
   while (c1->getStrength() > 0 && c2->getStrength() > 0)
   {
      //Display fighter types and the round
      cout << "\n\nFANTASTY COMBAT BATTLE, ";
      c1->printType();
      cout << " VS. ";
      c2->printType();
      cout << " - ROUND " << rounds + 1 << endl << endl;

      //Pre-attack info for Fighter 1
      cout << "Fighter 1, ";
      c1->printType();
      cout << ", is making an attack against Fighter 2! Fighter 2 is ";
      c2->printType();
      cout << " with ";
      cout << c2->getArmor();
      cout << " armor and ";
      cout << c2->getStrength();
      cout << " strength points remaining!\n\nHere comes Fighter 1!!\n";

      damage = c1->rollAtk();				//assume c1 is alive at the start of the round

      cout << "\n\nNow comes Fighter 2's defense calculations!\n";

      c2->rollDef(damage);

      cout << "\n\nFighter 2 has ";
      cout << c2->getStrength();
      cout << " strength remaining.";

      //Case: c2 still has strength after c1 attacks
      if (c2->getStrength() > 0)
      {
	 //Pre-attack info for Fighter 2
         cout << "\n\nFighter 2, ";
         c2->printType();
         cout << ", is making an attack against Fighter 1! Fighter 1 is ";
         c1->printType();
         cout << " with ";
         cout << c1->getArmor();
         cout << " armor and ";
         cout << c1->getStrength();
         cout << " strength points remaining!\n\nFighter 2's going in!\n";

	 damage = c2->rollAtk();

	 cout << "\n\nAnd here are Fighter 1's defense calculations!\n";

	 c1->rollDef(damage);

	 cout << "\n\nFighter 1 has ";
	 cout << c1->getStrength();
	 cout << " strength remaining.";

	 //Case: c1 has no strength left after c2 attacks
	 if (c1->getStrength() <= 0)
	 {
	    cout << "\nWhat a blow! It looks like Fighter 1, ";
	    c1->printType();
	    cout << " has been slain by Fighter 2, ";
	    c2->printType();
	    cout << "!!\n";
	 }
      }

      //Case: c2 has no strength left after c1 attacks
      else if (c2->getStrength() <= 0)
      {
	 cout << "\nOuch! It looks like Fighter 2, ";
	 c2->printType();
	 cout << " just got obliterated by Fighter 1, ";
	 c1->printType();
	 cout << "!!\n";
      }

      cout << "\n\n--------------------------------------------------------------------------------------\n\n";

      rounds++;
   }

   delete c1; 							//deallocate randomly assigned memory

   delete c2;

   c1 = NULL;

   c2 = NULL;
}

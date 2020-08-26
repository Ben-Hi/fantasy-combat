/*********************************************************************************************
 * * Program name: 	main.cpp
 * * Author: 		Benjamin Hillen
 * * Date: 		9 November 2019
 * * Description: 	Runs the Fantasy Combat program by continuously calling the menu
 * * 			function until the user chooses to quit the program
*********************************************************************************************/

#include "menu.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
   int choice = 0;

   srand(time(NULL));

   while (choice != 2)
   {
      choice = menu();
   }

   return 0;
}

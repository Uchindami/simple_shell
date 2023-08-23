#include "foundation.h"

/**
 * welcome_screen_1 - first half of loading screen
 */
void welcome_screen_1(void)
{
	write(1, "      /\\\n", 39);
	write(1, "     /  \\\n", 23);
	write(1, "    /    \\\n", 39);
	write(1, "   /      \\\n", 24);
	write(1, "  /_______/\\\n", 39);
	write(1, "SHELL", 39);
	write(1, "                \n", 25);
	write(1, "           by            MANFRED", 39);
}

/**
 * welcome_screen_2 - second half of loading screen
 */
void welcome_screen_2(void)
{
	write(1, "                  |    |\n", 25);
	write(1, ":--------------------------------------", 39);
	write(1, "-----------------------------------:\n", 37);
	write(1, "`---._.--------------------------------", 39);
	write(1, "-----------------------------._.---'\n", 37);
}

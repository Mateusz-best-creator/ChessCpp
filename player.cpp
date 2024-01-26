#include "player.h"
#include <cstring>

Player::Player(const char* n)
{
	whiteWins = blackWins = whiteLoses = blackLoses = 0;
	int i;
	for (i = 0; i < strlen(n); i++)
		name[i] = n[i];
	name[i] = '\0';
}
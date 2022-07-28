#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Flatulan.h"
#include "History.h"
#include "City.h"
#include "globals.h"

int main()
{
    // Create a game
    // Use this instead to create a mini-game:   Game g(3, 4, 2);
    Game g(3, 4, 2);
    // Play the game
    g.play();
}

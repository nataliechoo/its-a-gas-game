# its-a-gas-game
In a city full of bean eaters, the main player must preach to Flatulans in hopes that they stop eating so many beans! Beware of getting gassed!
This is an old game I made a while back, so it's slow, but still fun. 

CONTROLS:
u: move player UP
d: move player DOWN
r: move player RIGHT
l: move player LEFT
h: display map of game board's history
ENTER: attempt to preach to a Flatulan!

LEGEND:
'.' describes an empty position on the map
'F' describes a flatulan
'@' describes the player

HOW TO PLAY:
  - move around the map using u/d/l/r
  - when orthogonally adjacent or diagonal to a Flatulan, the player may attempt to preach by pressing ENTER. This has a 66% success rate.
  - If a Flatulan is orthogonally adjacent to a player, the player will get gassed, reducing 1 HP!
  - game ends when a player has converted all Flatulans, or when the player reaches 0 HP
  - run without adjustments, this will begin a minigame. Adjust code in main.cpp to customize game settings:
      - Game(int rows, int cols, int numberOfFlatulans): adjust these parameters on an instance of Game to customize
      - run .play() to begin game!

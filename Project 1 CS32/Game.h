//
//  Game.hpp
//  Project 1 CS32
//
//  Created by Natalie Choo on 4/5/21.
//

#ifndef Game_h
#define Game_h

#include <stdio.h>

class City;

class Game
{
  public:
        // Constructor/destructor
    Game(int rows, int cols, int nFlatulans);
    ~Game();

        // Mutators
    void play();

  private:
    City* m_city;
    
};


#endif /* Game_hpp */

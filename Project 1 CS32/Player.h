//
//  Player.hpp
//  Project 1 CS32
//
//  Created by Natalie Choo on 4/5/21.
//

#ifndef Player_h
#define Player_h

#include <stdio.h>
class City;

class Player
{
  public:
        // Constructor
    Player(City *cp, int r, int c);

        // Accessors
    int  row() const;
    int  col() const;
    int  age() const;
    int  health() const;
    bool isPassedOut() const;

        // Mutators
    void  preach();
    void  move(int dir);
    void  getGassed();

  private:
    City* m_city;
    int   m_row;
    int   m_col;
    int   m_health;
    int   m_age;
};
#endif /* Player_hpp */

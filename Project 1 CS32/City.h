//
//  City.hpp
//  Project 1 CS32
//
//  Created by Natalie Choo on 4/5/21.
//

#ifndef City_h
#define City_h

#include <stdio.h>
#include "globals.h"
#include "History.h"

class Player;
class Flatulan;
class History;


class City
{
  public:
        // Constructor/destructor
    City(int nRows, int nCols);
    ~City();

    //for history
    History& history();
    
        // Accessors
    int     rows() const;
    int     cols() const;
    Player* player() const;
    bool    isPlayerAt(int r, int c) const;
    int     flatulanCount() const;
    int     nFlatulansAt(int r, int c) const;
    bool    determineNewPosition(int& r, int& c, int dir) const;
    void    display() const;

        // Mutators
    bool  addFlatulan(int r, int c);
    bool  addPlayer(int r, int c);
    void  preachToFlatulansAroundPlayer();
    void  moveFlatulans();

  private:
    int       m_rows;
    int       m_cols;
    Player*   m_player;
    Flatulan* m_flatulans[MAXFLATULANS];
    int       m_nFlatulans;
    
    History m_history;

      // Helper functions
    bool isInBounds(int r, int c) const;
};
#endif /* City_hpp */

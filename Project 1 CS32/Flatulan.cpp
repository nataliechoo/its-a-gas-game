//
//  Flatulan.cpp
//  Project 1 CS32
//
//  Created by Natalie Choo on 4/5/21.
//

#include "Flatulan.h"
#include "City.h"
#include <iostream>
#include "globals.h"
#include "Player.h"

using namespace std;

Flatulan::Flatulan(City* cp, int r, int c)
 : m_city(cp), m_row(r), m_col(c)
{
    if (cp == nullptr)
    {
        cout << "***** A Flatulan must be created in some City!" << endl;
        exit(1);
    }
    if (r < 1  ||  r > cp->rows()  ||  c < 1  ||  c > cp->cols())
    {
        cout << "***** Flatulan created with invalid coordinates (" << r << ","
             << c << ")!" << endl;
        exit(1);
    }
}

int Flatulan::row() const
{
    return m_row;
}

int Flatulan::col() const
{
    return m_col;
}

bool Flatulan::haveIBeenConverted() const  // return true if converted
{
      // Probability of having been converted is 2/3
    return randInt(0, 2) < 2;
}

void Flatulan::move()
{
    
      // Attempt to move in a random direction; if it can't move, don't move.
      // If the player is there, don't move.
    int dir = randInt(0, NUMDIRS-1);  // dir is now UP, DOWN, LEFT, or RIGHT
    int r = m_row;
    int c = m_col;
    
    m_city->determineNewPosition(r, c, dir);
    if ( ! m_city->isPlayerAt(r, c))
    {
        m_row = r;
        m_col = c;
    }
    
    // after it moves, check if it is diagonal to player. if so, record the player's position
    
/*    int rowdiff = m_row - m_city->player()->row();
    int coldiff = m_col - m_city->player()->col();
    
    int pRow = m_city->player()->row();
    int pCol = m_city->player()->col();
    
    if (rowdiff == 1 || rowdiff == -1)
    {
        if (coldiff == 1 || coldiff == -1)
            m_city->history().record(pRow, pCol); */
    }


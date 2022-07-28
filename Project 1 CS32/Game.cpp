//
//  Game.cpp
//  Project 1 CS32
//
//  Created by Natalie Choo on 4/5/21.
//

#include "Game.h"
#include "City.h"
#include <cstdlib>
#include "globals.h"
#include "Player.h"
#include <iostream>

class Player;

using namespace std;

Game::Game(int rows, int cols, int nFlatulans)
{
    if (nFlatulans < 0)
    {
        cout << "***** Cannot create Game with negative number of Flatulans!" << endl;
        exit(1);
    }
    if (nFlatulans > MAXFLATULANS)
    {
        cout << "***** Trying to create Game with " << nFlatulans
             << " Flatulans; only " << MAXFLATULANS << " are allowed!" << endl;
        exit(1);
    }
    if (rows == 1  &&  cols == 1  &&  nFlatulans > 0)
    {
        cout << "***** Cannot create Game with nowhere to place the Flatulans!" << endl;
        exit(1);
    }

        // Create city
    m_city = new City(rows, cols);

        // Add player
    int rPlayer = randInt(1, rows);
    int cPlayer = randInt(1, cols);
    m_city->addPlayer(rPlayer, cPlayer);

      // Populate with Flatulans
    while (nFlatulans > 0)
    {
        int r = randInt(1, rows);
        int c = randInt(1, cols);
          // Don't put a Flatulan where the player is
        if (r == rPlayer  &&  c == cPlayer)
            continue;
        m_city->addFlatulan(r, c);
        nFlatulans--;
    }
}

Game::~Game()
{
    delete m_city;
}


void Game::play()
{
    m_city->display();
    Player* p = m_city->player();
    if (p == nullptr)
        return;

    while ( ! p->isPassedOut()  &&  m_city->flatulanCount() > 0)
    {
        bool h = false;
        cout << "Move (u/d/l/r//h/q): ";
        string action;
        getline(cin,action);
        if (action.size() == 0)  // player preaches
            p->preach();
        else
        {
            switch (action[0])
            {
                default:   // if a bad move, nobody moves
                    cout << '\a' << endl;  // beep
                    continue;
                case 'q':
                    return;
                case 'u':
                case 'd':
                case 'l':
                case 'r':
                {
                    p->move(decodeDirection(action[0]));
                    break;
                }
                case 'h':
                {
                    h = true;
                    m_city->history().display();
                    cout << endl;
                    cout << "Press enter to continue.";
                    cin.ignore(10000,'\n');
                }
            }
        }
        if (h == false)
        {
        m_city->moveFlatulans();
        }
        m_city->display();
        
    }
    if (p->isPassedOut())
        cout << "You lose." << endl;
    else
        cout << "You win." << endl;
}

//
//  History.cpp
//  Project 1 CS32
//
//  Created by Natalie Choo on 4/5/21.
//

#include "History.h"
#include "globals.h"
#include <iostream>
using namespace std;

History::History(int nRows, int nCols)
{
    cityR = nRows;
    cityC = nCols;
    for (int row = 1; row <= cityR; row++)
    {
        for (int col = 1; col <= cityC; col++)
        {
            grid[row][col] = '.';
        }
    }
}

bool History::record(int r, int c)
{
    if (r > cityR || c > cityC || r <= 0 || c <= 0)
        return(false);
    else
    {
        char& gridChar = grid[r][c];
        if (gridChar == '.')
            gridChar = 'A';
        else if (gridChar <= 'Y' && gridChar >= 'A')
            gridChar++;
        else if (gridChar == 'Z')
            gridChar = 'Z';
        int row, col;
        
        // Fill the grid with dots but if the grid is already a character, skip it
        for (row = 1; row <= cityR; row++)
        {
            for (col = 1; col <= cityC; col++)
            {
                
                if  ((grid[row][col] >= 'A' && grid[row][col] <= 'Y') || grid[row][col] == 'Z')
                {
                    //then this is good!
                }
                else
                    grid[row][col] = '.';

            }
        }
        recorded = true;
        return(true);
    }
}

void History::display() const
{
  /*  // Position (row,col) in the city coordinate system is represented in
    // the array element grid[row-1][col-1]
    int r, c;
    
    // Fill the grid with dots but if the grid is already a character, skip it
    for (r = 0; r < cityR; r++)
    {
    for (c = 0; c < cityC; c++)
        {
            if (recorded(r,c))
            {
                if  ((grid[r][c] >= 'A' && grid[r][c] <= 'Y') || grid[r][c] == 'Z')
                {
                    //then this is good!
                }
                else
                    grid[r][c] = '.';
            }
        }
    }
    */
    // Draw the grid
    int r,c;
    clearScreen();
    if (recorded)
    {
    for (r = 1; r <= cityR; r++)
    {
        for (c = 1; c <= cityC; c++)
        cout << grid[r][c];
        cout << endl;
    }
    }
    else
    {
        for (r = 1; r <= cityR; r++)
        {
            for (c = 1; c <= cityC; c++)
            cout << grid[r][c];
            cout << endl;
        }
    }
    cout << endl;
    
}

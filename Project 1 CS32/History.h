//
//  History.hpp
//  Project 1 CS32
//
//  Created by Natalie Choo on 4/5/21.
//

#ifndef History_h
#define History_h
#include "globals.h"

#include <stdio.h>
class History
    {
      public:
        History(int nRows, int nCols);
        bool record(int r, int c);
        void display() const;
    private:
        int currC;
        int currR;
        int cityR;
        int cityC;
        bool recorded;
        char grid[MAXROWS][MAXCOLS];
        
        
    };
#endif /* History_hpp */

//
//  recursive.cpp
//  labrob
//
//  Created by Ormir G. on 16/05/16.
//  Copyright © 2016 Nitika Kumar, Ormir Gjurgjej. All rights reserved.
//

#include "recursive.hpp"

Recursive::Recursive(const Labyrinth l):
Robot(l) {}

bool Recursive::solve() {
    return recursiveSolve(curX, curY);
}

bool Recursive::recursiveSolve(int x, int y) {
    steps++;
    if (lab.isAtExit(x, y)) return true;
    if (lab.at(x, y) != ' ') return false;
    
    lab.at(x, y) = 'x';
    
    // north
    if(y != 0 && recursiveSolve(x, y-1)) return true;
    
    // south
    if (y != lab.getHeight()-1 && recursiveSolve(x, y+1)) return true;
    
    // west
    if(x != 0 && recursiveSolve(x-1, y)) return true;
    
    // east
    if(x != lab.getWidth()-1 && recursiveSolve(x+1, y)) return true;
    
    return false;
}

Recursive::~Recursive() {}